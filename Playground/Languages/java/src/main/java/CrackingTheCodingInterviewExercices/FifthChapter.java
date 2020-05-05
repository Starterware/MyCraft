package CrackingTheCodingInterviewExercices;

import java.util.ArrayList;
import java.util.List;

public class FifthChapter {
    public int insertBitNumberInBitNumber(int n, int m, int start, int end) {
        int mShifted = m << end;
        int clearMask = ~(((1 << (start - end)) - 1) << end);
        return (n & clearMask) ^ mShifted;
    }

    public String convertToBinary(double d) {
        if (d >= 1 || d <= 0) return "ERROR";
        double unit = 1;
        StringBuilder n = new StringBuilder("0.");
        for (int i = 0; i < 32; i++) {
            unit /= 2;
            if (d >= unit) {
                d -= unit;
                n.append("1");
            } else {
                n.append("0");
            }
        }
        if (d != 0.0) return "ERROR";
        return n.toString();
    }

    public int getNextBiggestBinaryNumber(int n) {
        int c0 = getNumberOfTrailingB(n, 0);
        int c1 = getNumberOfFirstNonTrailingB(n, 1);
        if (c0 + c1 == 31) return -1;
        return n + (1 << (c0 + c1 - 1));
    }

    public int getNextSmallestBinaryNumber(int n) {
        int c1 = getNumberOfTrailingB(n, 1);
        int c0 = getNumberOfFirstNonTrailingB(n, 0);
        if (c1 + c0 == 31) return -1;
        return n - (1 << c1) - (1 << (c0 - 1)) + 1;
    }

    private int getNumberOfTrailingB(int n, int b) {
        int count = 0;
        while (n%2 == b) {
            n >>= 1;
            count++;
        }
        return count;
    }

    public int getNumberOfFirstNonTrailingB(int n, int b) {
        while (n%2 != b) {
            n >>= 1;
        }
        return getNumberOfTrailingB(n, b);
    }

    private int getNextNumber(int n, int first, int second) {
        int result = 0;
        int factor = 1;
        int i = 0;

        for (; i < 32 && n % 2 == first; i++) {
            result += factor * first;
            factor *= 2;
            n /= 2;
        }
        for (; i < 32 && n % 2 == second; i++) {
            result += factor * second;
            factor *= 2;
            n /= 2;
        }
        if (i < 32) {
            result += factor/2;
            factor *= 2;
            n /= 2;
            i++;
        }
        for (; i < 32 && n != 0; i++) {
            result += factor * (n%2);
            factor *= 2;
            n /= 2;
        }

        return result;
    }

    public int getNumberOfDifferentBits(int a, int b) {
        int count = 0;
        for (int c = a ^ b; c != 0; c >>= 1) {
            count += c & 1;
        }
        return count;
    }

    public int getNumberOfDifferentBitsWithBitFlip(int a, int b) {
        int count = 0;
        for (int c = a ^ b; c != 0; c &= (c-1)) {
            count++;
        }
        return count;
    }

    public int swapEvenAndOddBits(int n) {
        return  ((n & 0xaaaaaaaa) >> 1) | ((n & 0x55555555) << 1);
    }

    public static int MAX_SIZE = 4;

    public String findMissingNumber(List<String> l) {
        return findMissingNumber(l, 0);
    }

    public String findMissingNumber(List<String> l, int pos) {
        if (pos == MAX_SIZE) return "";

        List<String> zeros = new ArrayList<>();
        List<String> ones = new ArrayList<>();

        for (String e : l) {
            if (e.charAt(e.length() - pos - 1) == '0')
                zeros.add(e);
            else
                ones.add(e);
        }

        if (zeros.size() <= ones.size())
            return findMissingNumber(zeros, pos+1) + "0";
        return findMissingNumber(ones, pos+1) + "1";
    }

    public void drawHorizontalLine(byte[] screen, int w, int x1, int x2, int y) {
        int startByte = (w * y + x1) / 8;
        int startOffset = x1 % 8;
        int endByte = (w * y + x2) / 8;
        int endOffset = x2 % 8;

        for (int i = startByte + 1; i < endByte; i++) {
            screen[i] = (byte) 0xFF;
        }

        byte firstByteMask = (byte) (0xFF >> startOffset);
        byte endByteMask = (byte) (0xFF << endOffset);

        if (x1 / 8 == x2 / 8) {
            screen[startByte] |= (firstByteMask & endByteMask);
        } else {
            screen[startByte] |= firstByteMask;
            screen[endByte] |= endByteMask;
        }
    }
}
