package CrackingTheCodingInterviewExercices;

import jdk.jfr.Description;
import org.junit.jupiter.api.Test;

import java.util.function.BiFunction;
import java.util.function.Function;

import static com.google.common.truth.Truth.assertThat;

/**
 * Exercises from Cracking the code interview - Chapter 1 - Array and Strings
 */
public class FirstChapterTest {
    FirstChapter chapter = new FirstChapter();

    @Test
    @Description("Exercise 1")
    void testHasUniqueChars() {
        hasUniqueCharsWithHashMapTest(s -> chapter.hasUniqueChars(s));
        hasUniqueCharsWithHashMapTest(s -> chapter.hasUniqueCharsWithBitSet(s));
        hasUniqueCharsWithHashMapTest(s -> chapter.hasUniqueCharsWithMap(s));
        hasUniqueCharsWithHashMapTest(s -> chapter.hasUniqueCharsWithoutDataStructure(s));
    }

    private void hasUniqueCharsWithHashMapTest(Function<String, Boolean> f) {
        assertThat(f.apply("")).isTrue();
        assertThat(f.apply("abcdef")).isTrue();
        assertThat(f.apply("abcdaf")).isFalse();
        assertThat(f.apply(Character.toString(0) + Character.toString(255))).isTrue();
    }

    @Test
    @Description("Exercise 3")
    void testIsPermutation() {
        isPermutationTest((a, b) -> chapter.isPermutation(a, b));
        isPermutationTest((a, b) -> chapter.isPermutationWithHashMap(a, b));
    }

    private void isPermutationTest(BiFunction<String, String, Boolean> f) {
        assertThat(f.apply("abc", "cba")).isTrue();
        assertThat(f.apply("aaa", "aa")).isFalse();
        assertThat(f.apply("abc", "cbe")).isFalse();
        assertThat(f.apply("", "")).isTrue();
    }

    @Test
    @Description("Exercise 4")
    void testReplaceSpaces() {
        testReplaceSpaces(" ", "%20");
        testReplaceSpaces("a", "a");
        testReplaceSpaces("  ", "%20%20");
        testReplaceSpaces("a ", "a%20");
        testReplaceSpaces("a b c", "a%20b%20c");
    }

    private void testReplaceSpaces(String input, String expected) {
        char[] s = new char[2^20];
        System.arraycopy(input.toCharArray(), 0, s, 0, input.length());
        chapter.replaceSpaces(s, input.length());
        assertThat(new String(s)).startsWith(expected);
    }

    @Test
    @Description("Exercise 5")
    void testCompressString() {
        assertThat(chapter.compress("")).isEqualTo("");
        assertThat(chapter.compress("abc")).isEqualTo("abc");
        assertThat(chapter.compress("aabbcc")).isEqualTo("aabbcc");
        assertThat(chapter.compress("aabbbcc")).isEqualTo("a2b3c2");
    }

    @Test
    @Description("Exercise 6")
    void testRotate() {
        rotateTest(new int[][] {{0, 1}, {2, 3}}, new int[][] {{2, 0}, {3, 1}});
        rotateTest(new int[][] {{0, 1, 2}, {3, 4, 5}, {6, 7, 8}}, new int[][] {{6, 3, 0}, {7, 4, 1}, {8, 5, 2}});
    }

    private void rotateTest(int[][] m, int[][] expected) {
        chapter.rotate(m, m.length);
        assertThat(m).isEqualTo(expected);
    }

    @Test
    @Description("Exercise 7")
    void testSetZeros() {
        setZerosTest(new int[][] {{0, 1, 2}, {3, 0, 5}, {6, 7, 8}}, new int[][] {{0, 0, 0}, {0, 0, 0}, {0, 0, 8}});
    }

    private void setZerosTest(int[][] m, int[][] expected) {
        chapter.setZeros(m);
        assertThat(m).isEqualTo(expected);
    }

    @Test
    @Description("Exercise 8")
    void testIsRotation() {
        assertThat(chapter.isRotation("abcdef", "defabc")).isEqualTo(true);
        assertThat(chapter.isRotation("abcdef", "degabc")).isEqualTo(false);
        assertThat(chapter.isRotation("abcdef", "defgabc")).isEqualTo(false);
    }
}
