#!/usr/bin/perl

use warnings;
use strict;

# Global functions

sub ReadLinesFromFile
{
	my ($filename) = @_;
	
	open my $in, '<', $filename or die "Could not open file '$filename' $!";
	chomp(my @lines = <$in>);
	close $in;
	
	return @lines;
}

sub WriteContentToFile
{
	my ($filename, $filecontent) = @_;
	
	open my $out, '>', $filename or die "Can't write to file '$filename': $!";
	print $out $filecontent;
	close $out;
}

sub ListSubDirectories
{
	my ($dir) = @_;
	opendir ( my $dh, $dir );
	return grep {-d "$dir/$_" && ! /^\.{1,2}$/} readdir($dh);
}

sub FindNextEmptyLine
{
	my ($start, @lines) = @_;
	
	foreach my $i ($start .. $#lines) 
	{
		if ($lines[$i] eq "") {
			return $i;
		}
	}
	
	return $#lines;
}

# Katas related functions

sub RetrieveLanguages
{
	my ($dir) = @_;
	my @subdirs = ListSubDirectories($dir);
	
	foreach my $subdir (@subdirs) {
		$subdir = "[$subdir]($dir/$subdir)";
	}
	
	return @subdirs;
}

sub BuildKataLink
{
	my ($dir, $name) = @_;
	return "* [$name]($dir/README.md) : implemented in " . join(', ', RetrieveLanguages($dir)) . "\n";
}

sub BuildKataLinkForDir
{
	my ($dir) = @_;
    my @readme = ReadLinesFromFile("$dir/README.md");
	my $name = substr $readme[2], 1;
	
	$name =~ s/^\s+|\s+$//g;
	
	return BuildKataLink($dir, $name);
}

sub BuildKatasLinks
{
	my $sources_folder = "Kata/sources";
	my $links = "";
	my @dirs = ListSubDirectories($sources_folder);

	foreach my $dir (@dirs) {
		$links .= BuildKataLinkForDir("$sources_folder/$dir");
	}
	
	return $links;
}

# Project Euler related functions

sub RetrieveProjectEulerInfo
{
	my ($dir) = @_;

	my @data = ReadLinesFromFile($dir . "/main.cpp");
    my @info = split(/Project Euler Problem | - |\n/, $data[1]);
	
	return @info;
}

sub BuildProjectEulerLink
{
	my ($name, $number, $dir) = @_;
	return "* [$name](https://projecteuler.net/problem=$number) : problem $number [[source]($dir)]\n";
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
	my @dirs = ListSubDirectories($sources_folder);

	foreach my $dir (@dirs) {
		$links .= BuildProjectEulerLinkForDir("$sources_folder/$dir");
	}
	
	return $links;
}

# Main

sub UpdateFileContent
{
	my (@lines) = @_;
	my $filecontent = "";
	my $i = 0;
	
	while ($i < $#lines)
	{		
		$filecontent .= $lines[$i] . "\n";
		
		if ($lines[$i] eq "### Katas") 
		{
			$i = FindNextEmptyLine($i+2, @lines) - 1;
			$filecontent .= "\n" . BuildKatasLinks();
		}
		if ($lines[$i] eq "### Problems") 
		{
			$i = FindNextEmptyLine($i+2, @lines) - 1;
			$filecontent .= "\n" . BuildProjectEulerLinks();
		}
		
		$i++;
	}
	
	return $filecontent;
}

sub UpdateReadmeFile
{
	my $filename = "README.md";

	my @lines = ReadLinesFromFile($filename);
	my $filecontent = UpdateFileContent(@lines);
	WriteContentToFile($filename, $filecontent);
}

UpdateReadmeFile();	
	

