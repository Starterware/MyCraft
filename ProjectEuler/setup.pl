#!/usr/bin/perl

use warnings;
use strict;
use File::Copy; 
use File::Basename;

# Function definitions

sub CopyFile 
{
	my ($file, $todir) = @_;

	print "[Copy] $file to $todir... ";
	copy($file, $todir) or die "[Failed]\n Error: $!";
	print "[done]\n";
}

sub CopyFileIfNotPresent
{
	my ($file, $todir) = @_;
	my $basename = basename($file);
	
	unless (-f "$todir/$basename") {
		CopyFile($file, $todir);
	}
}

# Main

my $sources_folder = "sources";
my $templates_folder = "templates";

my $build_file = "CMakeLists.txt";
my $main_file = "main.cpp";

opendir( my $dirs, $sources_folder );

while ( my $dir = readdir $dirs ) 
{
	my $todir = $sources_folder . '/' . $dir;
    next unless -d $todir;
    next if $dir eq '.' or $dir eq '..';
	
	CopyFile("$templates_folder/$build_file", $todir);
	CopyFileIfNotPresent("$templates_folder/$main_file", $todir);
}

closedir $dirs;