package CrackingTheCodingInterviewExercices;

import jdk.jfr.Description;
import org.junit.jupiter.api.Test;

import java.util.ArrayList;
import java.util.List;

import static com.google.common.truth.Truth.assertThat;

/**
 * Exercises from Cracking the code interview - Chapter 5 - Bit Manipulation
 */
public class FifthChapterTest {
    FifthChapter chapter = new FifthChapter();

    @Test
    @Description("Exercise 1")
    void testInsertBitNumberInBitNumber() {
        assertThat(chapter.insertBitNumberInBitNumber(0b10101010, 0b1100, 6, 2)).isEqualTo(0b10110010);
    }

    @Test
    @Description("Exercise 2")
    void testConvertDoubleToBinary() {
        assertThat(chapter.convertToBinary(0.5)).isEqualTo("0.10000000000000000000000000000000");
        assertThat(chapter.convertToBinary(0.99999999)).isEqualTo("ERROR");
        assertThat(chapter.convertToBinary(0.05882352939806878566741943359375)).isEqualTo("0.00001111000011110000111100001111");
    }

    @Test
    @Description("Exercise 3")
    void testNextSmallestAndBiggestBinaryNumber() {
        assertThat(chapter.getNextBiggestBinaryNumber(0b11110111)).isEqualTo(0b11111011);
        assertThat(chapter.getNextBiggestBinaryNumber(0b11010000)).isEqualTo(0b11100000);
        assertThat(chapter.getNextSmallestBinaryNumber(0b10000111)).isEqualTo(0b01111000);
    }

    @Test
    @Description("Exercise 5")
    void testGetNumberOfDifferentBits() {
        assertThat(chapter.getNumberOfDifferentBits(0b11010111, 0b10110101)).isEqualTo(3);
        assertThat(chapter.getNumberOfDifferentBitsWithBitFlip(0b11010111, 0b10110101)).isEqualTo(3);
    }

    @Test
    @Description("Exercise 6")
    void testSwapEvenAndOddBits() {
        assertThat(chapter.swapEvenAndOddBits(0b11010111)).isEqualTo(0b11101011);
    }

    @Test
    @Description("Exercise 7")
    void testFindMissingNumber() {
        List<String> l = new ArrayList<>(List.of("0100", "0111", "0000", "0001", "0010", "0101", "0110"));
        assertThat(chapter.findMissingNumber(l)).isEqualTo("0011");
        l.add("1000");
        assertThat(chapter.findMissingNumber(l)).isEqualTo("0011");
    }

    @Test
    @Description("Exercise 8")
    void testDrawHorizontalLine() {
        byte[] screen = {0x0, 0x0, 0x0, (byte)0xAA, 0x77, (byte)0x99, 0x0, 0x0, 0x0};
        byte[] screenWithLine = {0x0, 0x0, 0x0, (byte)0xBF, (byte)0xFF, (byte)0xF9, 0x0, 0x0, 0x0};
        chapter.drawHorizontalLine(screen, 24, 3, 19, 1);
        assertThat(screen).isEqualTo(screenWithLine);
    }
}
