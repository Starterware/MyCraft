package Excercices;

import java.util.*;

public class FirstChapter {
    public boolean hasUniqueChars(String input) {
        if (input.length() > 256) return false;
        byte[] set = new byte[256/8];
        for (char c : input.toCharArray()) {
            if ((set[c/8] & (1 << c%8)) > 0)
                return false;
            set[c/8] |= (1 << c%8);
        }
        return true;
    }

    public boolean hasUniqueCharsWithBitSet(String input) {
        if (input.length() > 256) return false;
        BitSet set = new BitSet(256);
        for (char c : input.toCharArray()) {
            if (set.get(c))
                return false;
            set.set(c, true);
        }
        return true;
    }

    public boolean hasUniqueCharsWithMap(String input) {
        Set<Character> s = new HashSet<>(input.length());
        for (char c : input.toCharArray()) {
            if (s.contains(c))
                return false;
            s.add(c);
        }
        return true;
    }

    // Could use sorting but in Java it would require an array as input to not add space usage
    public boolean hasUniqueCharsWithoutDataStructure(String input) {
        for (int i = 0; i < input.length(); i++)
            for (int j = i + 1; j < input.length(); j++)
                if (input.charAt(i) == input.charAt(j))
                    return false;
        return true;
    }

    public boolean isPermutation(String s1, String s2) {
        if (s1.length() != s2.length()) return false;
        int[] l = new int[256];
        for (char c : s1.toCharArray())
            l[c]++;
        for (char c : s2.toCharArray())
            if (--l[c] < 0)
                return false;
        return true;
    }

    public boolean isPermutationWithHashMap(String s1, String s2) {
        if (s1.length() != s2.length()) return false;
        Map<Character, Integer> m = new HashMap<>();
        for (char c : s1.toCharArray())
            m.put(c, m.getOrDefault(c, 0) + 1);
        for (char c : s2.toCharArray()) {
            m.put(c, m.getOrDefault(c, 0) - 1);
            if (m.get(c) < 0)
                return false;
        }
        return true;
    }

    public void replaceSpaces(char[] s, int l) {
        int end = 0;
        for (int i = 0; i < l; i++)
            end += (s[i] == ' ') ? 3 : 1;
        s[end] = '\0';
        for (int i = l-1; i >= 0; i--) {
            if (s[i] == ' ') {
                s[--end] = '0';
                s[--end] = '2';
                s[--end] = '%';
            } else {
                s[--end] = s[i];
            }
        }
    }

    public String compress(String s) {
        if (s == null || s.isEmpty()) return s;
        String cs = getCompressedString(s);
        return cs.length() < s.length() ? cs : s;
    }

    private String getCompressedString(String s) {
        StringBuilder sb = new StringBuilder();
        int count = 1;
        char c = s.charAt(0);
        for (int i = 1; i < s.length(); i++) {
            if (c == s.charAt(i)) {
                count++;
            } else {
                sb.append(c).append(count);
                c = s.charAt(i);
                count = 1;
            }
        }
        sb.append(c).append(count);
        return sb.toString();
    }

    public void rotate(int[][] m, int l) {
        for (int first = 0; first < l/2; first++) {
            int last = l-1-first;
            for (int i = first; i < last; i++) {
                int tmp = m[first][i];
                m[first][i] = m[last-i][first];
                m[last-i][first] = m[last][last-i];
                m[last][last-i] = m[i][last];
                m[i][last] = tmp;
            }
        }
    }

    public void setZeros(int[][] m) {
        BitSet line = new BitSet(m.length);
        BitSet row = new BitSet(m[0].length);
        for (int i = 0; i < m.length; i++) {
            for (int j = 0; j < m[0].length; j++) {
                if (m[i][j] == 0) {
                    line.set(i, true);
                    row.set(j, true);
                }
            }
        }
        for (int i = 0; i < m.length; i++) {
            for (int j = 0; j < m[0].length; j++) {
                if (line.get(i) || row.get(j)) {
                    m[i][j] = 0;
                }
            }
        }
    }

    public boolean isRotation(String s1, String s2) {
        if (s1.length() == s2.length()) {
            return (s1+s1).contains(s2);
        }
        return false;
    }
}
