import org.junit.jupiter.api.Test;

import java.util.Collections;

import static com.google.common.truth.Truth.assertThat;
import static org.junit.jupiter.api.Assertions.assertThrows;

public class BowlingGameTest {
    BowlingGame game = new BowlingGame();

    @Test
    public void testComputeScoreOfGutterGame() {
        String frames = repeatFrame("--", 10);
        assertThat(game.computeScore(frames)).isEqualTo(0);
    }

    @Test
    public void testComputeScoreFailsWhenItDoesNotContain10Frames() {
        String notEnoughFrames = repeatFrame("--", 9);
        String tooMuchFrames = repeatFrame("--", 11);

        assertThrows(IllegalArgumentException.class, () -> game.computeScore(notEnoughFrames));
        assertThrows(IllegalArgumentException.class, () -> game.computeScore(tooMuchFrames));
    }

    @Test
    public void testComputeScoreFailsWhenContaining0AsARoll() {
        String rolls = concatenateFrames("-0", repeatFrame("--", 9));
        assertThrows(IllegalArgumentException.class, () -> game.computeScore(rolls));
    }

    @Test
    public void testComputeScoreOfOnlyOneThrows() {
        String rolls = repeatFrame("11", 10);
        assertThat(game.computeScore(rolls)).isEqualTo(20);
    }

    @Test
    public void testComputeScoreFailsWhenContainingANotAllowedChar() {
        String rolls = concatenateFrames("-A", repeatFrame("--", 9));
        assertThrows(IllegalArgumentException.class, () -> game.computeScore(rolls));
    }

    @Test
    public void testComputeScoreFailsForFrameValueBiggerThan9IfNotSpare() {
        String rolls = concatenateFrames(repeatFrame("--", 9) + "46");
        assertThrows(IllegalArgumentException.class, () -> game.computeScore(rolls));
    }

    @Test
    public void testComputeScoreFailsForFrameContainingASpareForFirstThrow() {
        String rolls = concatenateFrames(repeatFrame("--", 9) + "/6");
        assertThrows(IllegalArgumentException.class, () -> game.computeScore(rolls));
    }

    @Test
    public void testComputeScoreOfOneSpare() {
        String rolls = concatenateFrames(spareFrame(), "3-", repeatFrame("--", 8));
        assertThat(game.computeScore(rolls)).isEqualTo(10 + 3 + 3);
    }

    @Test
    public void testComputeScoreOfOneStrike() {
        String rolls = concatenateFrames(strikeFrame(), "34", repeatFrame("--", 8));
        assertThat(game.computeScore(rolls)).isEqualTo(10 + 3 + 4 + 3 + 4);
    }

    @Test
    public void testComputeScoreOfSpareInLastFrame() {
        String rolls = concatenateFrames(repeatFrame("--", 9), "4/4");
        assertThat(game.computeScore(rolls)).isEqualTo(10 + 4);
    }

    @Test
    public void testComputeScoreOfPerfectGame() {
        String rolls = concatenateFrames(repeatFrame(strikeFrame(), 9), "XXX");
        assertThat(game.computeScore(rolls)).isEqualTo(300);
    }

    @Test
    public void testComputeScoreFailsForStrikeFollowedByAThrowInSameFrame() {
        String rolls = concatenateFrames("X4", repeatFrame("--", 9));
        assertThrows(IllegalArgumentException.class, () -> game.computeScore(rolls));
    }

    @Test
    public void testComputeScoreFailsWithEmptyFrame() {
        String rolls = concatenateFrames("--", "", repeatFrame("--", 8));
        assertThrows(IllegalArgumentException.class, () -> game.computeScore(rolls));
    }

    @Test
    public void testComputeScoreFailsForLastFrameWith3ThrowsWithoutStrikeOrSpare() {
        String rolls = concatenateFrames(repeatFrame("--", 9), "123");
        assertThrows(IllegalArgumentException.class, () -> game.computeScore(rolls));
    }

    @Test
    public void testComputeScoreFailsForLastFrameWithStrikeFollowedByThrowsAdditionHigherThan10() {
        String rolls = concatenateFrames(repeatFrame("--", 9), "X65");
        assertThrows(IllegalArgumentException.class, () -> game.computeScore(rolls));
    }

    @Test
    public void testComputeScoreFailsForLastFrameWithStrikeFollowedByOnlyOneThrow() {
        String rolls = concatenateFrames(repeatFrame("--", 9), "X6");
        assertThrows(IllegalArgumentException.class, () -> game.computeScore(rolls));
    }

    @Test
    public void testComputeScoreFailsForFrameWithOnlyOneRollThatIsNotAStrike() {
        String rolls = concatenateFrames("-", repeatFrame("--", 9));
        assertThrows(IllegalArgumentException.class, () -> game.computeScore(rolls));
    }

    private String repeatFrame(String frame, int n) {
        return String.join(" ", Collections.nCopies(n, frame));
    }
    
    private String spareFrame() {
        return "1/";
    }

    private String strikeFrame() {
        return "X";
    }

    private String concatenateFrames(String... frames) {
        return String.join(" ", frames);
    }
}
