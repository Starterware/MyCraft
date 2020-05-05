package CrackingTheCodingInterviewExercices;

import jdk.jfr.Description;
import org.junit.Test;
import org.junit.jupiter.params.ParameterizedTest;
import org.junit.jupiter.params.provider.CsvSource;

import java.awt.*;
import java.util.List;
import java.util.Set;

import static com.google.common.truth.Truth.assertThat;

/**
 * Exercises from Cracking the code interview - Chapter 9 - Recursion and dynamic programming
 */
public class NinthChapterTest {
    NinthChapter chapter = new NinthChapter();

    /**
     * When using ints for the solution the max numbers of stairs are n=37 otherwise there will be an overflow
     */
    @ParameterizedTest
    @Description("Exercise 1")
    @CsvSource({"-1,0", "0,1", "1,1", "2,2", "3,4", "4,7"})
    public void testCountWaysToRunUpStairs(int numberOfStairs, int expectedCount) {
        assertThat(chapter.countWaysToRunUpStairs(numberOfStairs)).isEqualTo(expectedCount);
    }

    /**
     * When using dynamic programming on factorials on integers, it limits the solution to x+y < 13. It is possible to
     * make the number higher by not using dynamic programming and just multiply the numbers from x+y to max(x, y).
     */
    @ParameterizedTest
    @Description("Exercise 2")
    @CsvSource({"0,0,1", "-1,0,0", "0,-1,0", "0,1,1", "1,0,1", "1,1,2", "2,3,10"})
    public void testCountPathsRobotCanTake(int x, int y, int expectedCount) {
        assertThat(chapter.countPathsRobotCanTake(x, y)).isEqualTo(expectedCount);
    }

    @Test
    @Description("Exercise 2")
    public void testFindPathRobotCanTake() {
        Set<Point> blockedPoints = Set.of(new Point(1,3), new Point(2,2), new Point(1,0));
        List<Point> expectedPath = List.of(new Point(0,0), new Point(0,1), new Point(1,1),
                new Point(2, 1), new Point(3, 1), new Point(3, 2), new Point(3, 3));
        assertThat(chapter.findPathRobotCanTake(3, 3, blockedPoints)).isEqualTo(expectedPath);
    }

    @Test
    @Description("Exercise 3")
    public void testHasMagicIndex() {
        assertThat(chapter.hasMagicIndex(List.of(1, 2, 3, 4, 5))).isEqualTo(-1);
        assertThat(chapter.hasMagicIndex(List.of(-1, 0, 1, 2, 3))).isEqualTo(-1);
        assertThat(chapter.hasMagicIndex(List.of(-1, 0, 1, 3, 4))).isEqualTo(3);
    }

    @Test
    @Description("Exercise 3")
    public void testHasMagicIndexNotDistinct() {
        assertThat(chapter.hasMagicIndexNotDistinct(List.of(1, 2, 3, 4, 5))).isEqualTo(-1);
        assertThat(chapter.hasMagicIndexNotDistinct(List.of(-1, 0, 1, 2, 3))).isEqualTo(-1);
        assertThat(chapter.hasMagicIndexNotDistinct(List.of(-1, 0, 1, 3, 4))).isEqualTo(3);
        assertThat(chapter.hasMagicIndexNotDistinct(List.of(-1, 0, 3, 3, 4))).isEqualTo(3);
    }

    @Test
    @Description("Exercise 4")
    public void testSubsetsOfSet() {
        assertThat(chapter.subsetOfSet(List.of(1, 2, 3))).containsExactly(
                List.of(),
                List.of(1), List.of(2), List.of(3),
                List.of(1,2), List.of(2,3), List.of(1,3),
                List.of(1,2,3));
    }

    @Test
    @Description("Exercise 5")
    public void testStringPermutations() {
        assertThat(chapter.stringPermutations("abc")).containsExactly("abc", "acb", "bac", "bca", "cab", "cba");
    }

    @Test
    @Description("Exercise 6")
    public void testParenthesesCombinations() {
        assertThat(chapter.parenthesesCombinations(3)).containsExactly("((()))", "(())()", "()(())", "()()()", "(()())");
    }

    @Test
    @Description("Exercise 7")
    public void testPaintFill() {
        Color[][] picture = {
                { Color.BLACK, Color.WHITE, Color.BLACK, Color.BLACK, Color.BLACK },
                { Color.BLACK, Color.WHITE, Color.WHITE, Color.WHITE, Color.BLACK },
                { Color.WHITE, Color.WHITE, Color.WHITE, Color.WHITE, Color.BLACK },
                { Color.BLACK, Color.BLACK, Color.WHITE, Color.BLACK, Color.BLACK },
                { Color.BLACK, Color.BLACK, Color.WHITE, Color.BLACK, Color.WHITE }};
        Color[][] paintFilledPicture = {
                { Color.BLACK, Color.RED, Color.BLACK, Color.BLACK, Color.BLACK },
                { Color.BLACK, Color.RED, Color.RED, Color.RED, Color.BLACK },
                { Color.RED, Color.RED, Color.RED, Color.RED, Color.BLACK },
                { Color.BLACK, Color.BLACK, Color.RED, Color.BLACK, Color.BLACK },
                { Color.BLACK, Color.BLACK, Color.RED, Color.BLACK, Color.WHITE }};
        boolean painted = chapter.paintFill(picture, 2, 1, Color.RED);
        assertThat(painted).isTrue();
        assertThat(picture).isEqualTo(paintFilledPicture);
    }

    @Test
    @Description("Exercise 8")
    public void testWaysToRepresentNCents() {
        assertThat(chapter.waysToRepresentNCents(50)).isEqualTo(49);
    }

    @Test
    @Description("Exercise 9")
    public void testQueensOnChessBoard() {
        assertThat(chapter.queensOnChessBoard().size()).isEqualTo(92);
    }
}
