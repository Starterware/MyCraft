#!/usr/bin/perl

use warnings;
use strict;
use File::Copy;

my $sources = "sources";
my $build_file = "templates/CMakeLists.txt";

opendir( my $dirs, $sources );

while ( my $dir = readdir $dirs ) {
	my $todir = $sources . '/' . $dir;
    next unless -d $todir;
    next if $dir eq '.' or $dir eq '..';
	
	print("[Copy] $build_file to $todir");
	copy($build_file, $todir) or die "[Failed] Copy: $!";
}

closedir $dirs;