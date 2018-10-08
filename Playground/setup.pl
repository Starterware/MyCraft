#!/usr/bin/perl
 
use warnings;
use strict;
use File::Find;
use File::Basename;

my $gtestpath = "";

sub UpdateGtestPaths
{
	find(\&process, ".");
}

sub process
{
	return if (($_ eq '.') || ($_ eq '..'));
	return if $_ ne "CMakeLists.txt";

	print $File::Find::name . "\n";

	my $content = "";
	my $filepath = $_;
	open(DATA, $filepath) or die $!;
	while(<DATA>)
	{
		$_=~ s/set\s\(GTEST_DIR.*\)/set (GTEST_DIR "$gtestpath")/g;
		$content .= $_;
	}
	close(DATA);

	open(DATA, '>'.$filepath) or die $!;
	print DATA $content;
	close(DATA);
}

sub PrintUsage
{
	my ($program_name) = @_;
	print "\nUsage:\n\n";
	$program_name = basename($program_name);
	print "\t".$program_name." -gtest <path_to_gtest_include_and_lib>\n";
}

# Main

if ($#ARGV < 1 or not($ARGV[0] eq "--gtest" or $ARGV[0] eq "-g")) {
	PrintUsage($0);
}
else {
	$gtestpath = $ARGV[1];
	UpdateGtestPaths();
}

