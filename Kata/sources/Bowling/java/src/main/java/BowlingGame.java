import java.util.ArrayList;
import java.util.List;

public class BowlingGame {
    private static final int NBR_FRAMES = 10;
    
    private static final int STRIKE_VALUE = 10;
    private static final int SPARE_VALUE = 10;
    private static final int GUTTER_VALUE = 0;

    public int computeScore(String game) {
        List<Integer> rolls = new ArrayList<>();
         extractRolls(game, rolls);
        return computeScore(rolls);
    }

    private void extractRolls(String game, List<Integer> rolls) {
        String[] frames = game.split(" ");
        if (frames.length != NBR_FRAMES)
            throw new IllegalArgumentException();
        appendRollValues(rolls, frames);
    }

    private void appendRollValues(List<Integer> rolls, String[] frames) {
        for (int i = 0; i < NBR_FRAMES; i++) {
            String frame = frames[i];
            if (frame.length() < 1)
                throw new IllegalArgumentException();
            if (isStrike(frame.charAt(0))) {
                appendStrikeRollValues(rolls, isLastFrame(i), frame);
            } else {
                appendRollValues(rolls, isLastFrame(i), frame);
            }
        }
    }

    private boolean isLastFrame(int i) {
        return i == NBR_FRAMES - 1;
    }

    private void appendRollValues(List<Integer> rolls, boolean isLastFrame, String frame) {
        if (frame.length() < 2)
            throw new IllegalArgumentException();
        int firstRoll = getRollValue(frame.charAt(0));
        rolls.add(firstRoll);
        rolls.add(getRollValue(firstRoll, frame.charAt(1)));
        if (isLastFrame && isSpare(frame.charAt(1))) {
           rolls.add(getRollValue(frame.charAt(2)));
        } else if (frame.length() != 2) {
            throw new IllegalArgumentException();
        }
    }

    private void appendStrikeRollValues(List<Integer> rolls, boolean isLastFrame, String frame) {
        rolls.add(getRollValue(frame.charAt(0)));
        if (isLastFrame && frame.length() == 3) {
            int secondRoll = getRollValue(frame.charAt(1));
            rolls.add(secondRoll);
            if (isStrike(frame.charAt(1)))
                rolls.add(getRollValue(frame.charAt(2)));
            else
                rolls.add(getRollValue(secondRoll, frame.charAt(2)));
        } else if (frame.length() != 1) {
            throw new IllegalArgumentException();
        }
    }

    private int computeScore(List<Integer> rolls) {
        int result = 0;
        int frameIndex = 0;
        for (int i = 0; i < NBR_FRAMES; i++) {
            if (isStrike(rolls, frameIndex)) {
                result += strikeBonus(rolls, frameIndex);
                frameIndex += 1;
            } else if (isSpare(rolls, frameIndex)) {
                result += spareBonus(rolls, frameIndex);
                frameIndex += 2;
            } else {
                result += rolls.get(frameIndex) + rolls.get(frameIndex + 1);
                frameIndex += 2;
            }
        }
        return result;
    }

    private boolean isStrike(List<Integer> rolls, int frameIndex) {
        return rolls.get(frameIndex) == STRIKE_VALUE;
    }

    private int strikeBonus(List<Integer> rolls, int frameIndex) {
        return STRIKE_VALUE + rolls.get(frameIndex + 1) + rolls.get(frameIndex + 2);
    }

    private boolean isSpare(List<Integer> rolls, int frameIndex) {
        return rolls.get(frameIndex) + rolls.get(frameIndex + 1) == SPARE_VALUE;
    }

    private int spareBonus(List<Integer> rolls, int frameIndex) {
        return SPARE_VALUE + rolls.get(frameIndex + 2);
    }

    private int getRollValue(char roll) {
        if (isStrike(roll))
            return STRIKE_VALUE;
        if (isGutter(roll))
            return GUTTER_VALUE;
        if (roll > '0' && roll <= '9')
            return roll - '0';
        throw new IllegalArgumentException();
    }

    private int getRollValue(int previousRollValue, char roll) {
        if (isSpare(roll))
            return SPARE_VALUE - previousRollValue;
        int currentRollValue = getRollValue(roll);
        if (previousRollValue + currentRollValue >= SPARE_VALUE)
            throw new IllegalArgumentException();
        return currentRollValue;
    }

    private boolean isStrike(char roll) {
        return roll == 'X';
    }

    private boolean isGutter(char roll) {
        return roll == '-';
    }

    private boolean isSpare(char roll) {
        return roll == '/';
    }
}
