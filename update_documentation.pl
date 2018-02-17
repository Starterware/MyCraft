#!/usr/bin/perl

use warnings;
use strict;

# Function definitions

sub RetrieveProjectEulerInfo
{
	my ($dir) = @_;
	my $file = $dir . "/main.cpp";
	
	open my $fh, $file or die "Could not open '$file' $!\n";
	my @data = <$fh>;
    my @info = split(/Project Euler Problem | - |\n/, $data[1]);
	close $fh;
	
	return @info;
}

sub BuildProjectEulerLink
{
	my ($name, $number, $dir) = @_;
	return "* $name : problem $number [[link]](https://projecteuler.net/problem=$number) [[source]]($dir)\n";
}

sub BuildProjectEulerLinkForDir
{
	my ($dir) = @_;
    my @info = RetrieveProjectEulerInfo($dir);
	my $name = $info[2];
	my $number = $info[1];
	
	$name =~ s/^\s+|\s+$//g;
	$number =~ s/^\s+|\s+$//g;
	
	return BuildProjectEulerLink($name, $number, $dir);
}

sub BuildProjectEulerLinks
{
	my $sources_folder = "ProjectEuler/sources";
	my $links = "";

	opendir ( my $dirs, $sources_folder );

	while ( my $dir = readdir $dirs ) 
	{
		next if $dir eq '.' or $dir eq '..';
		
		my $todir = "$sources_folder/$dir";
		next unless -d $todir;
		
		$links .= BuildProjectEulerLinkForDir($todir);
	}

	closedir $dirs;
	
	return $links;
}

sub FindNextEmptyLine
{
	my ($start, @lines) = @_;
	
	foreach my $i ($start .. $#lines) 
	{
		if ($lines[$i] eq "") {
			return $i - $start;
		}
	}
	
	return $#lines - $start;
}

sub ReadLinesFromFile
{
	my ($filename) = @_;
	
	open my $in, '<', $filename or die "Could not open file '$filename' $!";
	chomp(my @lines = <$in>);
	close $in;
	
	return @lines;
}

sub UpdateFileContent
{
	my (@lines) = @_;
	my $filecontent = "";
	my $add = 0;
	
	foreach my $i (0 .. $#lines) 
	{
		last if $i + $add >= $#lines;
		
		$filecontent .= $lines[$i + $add] . "\n";
		if ($lines[$i + $add] eq "### Problems") 
		{
			$add = FindNextEmptyLine($i+2, @lines) + 1;
			$filecontent .= "\n" . BuildProjectEulerLinks() . "\n";
		}
	}
	
	return $filecontent;
}

sub WriteContentToFile
{
	my ($filename, $filecontent) = @_;
	
	open my $out, '>', $filename or die "Can't write to file '$filename': $!";
	print $out $filecontent;
	close $out;
}

sub UpdateReadmeFile
{
	my $filename = "README.md";

	my @lines = ReadLinesFromFile($filename);
	my $filecontent = UpdateFileContent(@lines);
	WriteContentToFile($filename, $filecontent);
}

# Main
UpdateReadmeFile();	
	

