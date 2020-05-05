package CrackingTheCodingInterviewExercices;

import java.awt.*;
import java.util.List;
import java.util.*;

public class NinthChapter {
    private int[] dpStairs = new int[100];

    public int countWaysToRunUpStairs(int numberOfStairs) {
        if (numberOfStairs < 0) {
            return 0;
        } else if (numberOfStairs == 0) {
            return 1;
        } else if (dpStairs[numberOfStairs] != 0) {
            return dpStairs[numberOfStairs];
        } else {
            dpStairs[numberOfStairs] = countWaysToRunUpStairs(numberOfStairs - 1)
                        + countWaysToRunUpStairs(numberOfStairs - 2)
                        + countWaysToRunUpStairs(numberOfStairs - 3);
            return dpStairs[numberOfStairs];
        }
    }

    private int[] factorials = new int[100];

    public int countPathsRobotCanTake(int x, int y) {
        if (x < 0 || y < 0)
            return 0;
        return factorial(x+y) / (factorial(x) * factorial(y));
    }

    private int factorial(int i) {
        if (i == 0)
            return 1;
        if (factorials[i] == 0)
            factorials[i] =  factorial(i-1) * i;
        return factorials[i];
    }

    public List<Point> findPathRobotCanTake(int x, int y, Set<Point> blockedSpots) {
        List<Point> path = new ArrayList<>();
        boolean found = findPath(new Point(x, y), path, new HashSet<>(blockedSpots));
        if (!found)
            return null;
        return path;
    }

    private boolean findPath(Point p, List<Point> path, Set<Point> blockedSpots) {
        if (blockedSpots.contains(p))
            return false;
        if (isStartPoint(p)
                || (p.x > 0 && findPath(new Point(p.x - 1, p.y), path, blockedSpots))
                || (p.y > 0 && findPath(new Point(p.x, p.y - 1), path, blockedSpots))) {
            path.add(p);
            return true;
        }
        blockedSpots.add(p);
        return false;
    }

    private boolean isStartPoint(Point p) {
        return p.equals(new Point(0, 0));
    }

    public int hasMagicIndex(List<Integer> l) {
        int start = 0;
        int end = l.size()-1;
        while (start <= end) {
            int middle = (start + end) / 2;
            if (l.get(middle) == middle)
                return middle;
            else if (l.get(middle) > middle)
                end = middle - 1;
            else
                start = middle + 1;
        }
        return -1;
    }

    public int hasMagicIndexNotDistinct(List<Integer> l) {
        return hasMagicIndexNotDistinct(l, 0, l.size()-1);
    }

    private int hasMagicIndexNotDistinct(List<Integer> l, int start, int end) {
        if (start > end)
            return -1;
        int middle = (start + end) / 2;
        if (l.get(middle) == middle)
            return middle;
        int left = hasMagicIndexNotDistinct(l, Math.max(middle + 1, l.get(middle)), end);
        if (left != -1)
            return left;
        return hasMagicIndexNotDistinct(l, start, Math.min(middle - 1, l.get(middle)));
    }

    public List<List<Object>> subsetOfSet(List<Object> l) {
        return subsetOfSet(l, l.size());
    }

    private List<List<Object>> subsetOfSet(List<Object> l, int n) {
        List<List<Object>> newSubsets = new ArrayList<>();
        if (n == 0) {
            newSubsets.add(new ArrayList<>());
        } else {
            List<List<Object>> subsets = subsetOfSet(l, n - 1);
            newSubsets.addAll(subsets);
            for (List<Object> subset : subsets) {
                List<Object> newSubset = new ArrayList<>(subset);
                newSubset.add(l.get(n - 1));
                newSubsets.add(newSubset);
            }
        }
        return newSubsets;
    }

    public List<String> stringPermutations(String s) {
        if (s.length() == 0)
            return new ArrayList<>(List.of(""));
        return stringPermutations(s, s.length());
    }

    private List<String> stringPermutations(String s, int n) {
        List<String> newPermutations = new ArrayList<>();
        String currentChar = String.valueOf(s.charAt(n-1));
        if (n == 1) {
            newPermutations.add(currentChar);
        } else {
            List<String> permutations = stringPermutations(s, n - 1);
            for (String permutation : permutations) {
                for (int i = 0; i < n; i++) {
                    newPermutations.add(insertAt(permutation, currentChar, i));
                }
            }
        }
        return newPermutations;
    }

    private String insertAt(String s, String toInsert, int i) {
        return s.substring(0, i) + toInsert + s.substring(i);
    }

    public List<String> parenthesesCombinations(int n) {
        return parenthesesCombinations("", n, 0, 0);
    }

    private List<String> parenthesesCombinations(String current, int n, int open, int closed) {
        List<String> l = new ArrayList<>();
        if (open == n) {
            l.add(current + ")".repeat(n - closed));
        } else {
            l.addAll(parenthesesCombinations(current + "(", n, open + 1, closed));
            if (closed < open) {
                l.addAll(parenthesesCombinations(current + ")", n, open, closed + 1));
            }
        }
        return l;
    }

    public boolean paintFill(Color[][] picture, int x, int y, Color c) {
        if (x < 0 || y < 0 || x >= picture[0].length || y >= picture.length) {
            return false;
        }
        return paintFill(picture, x, y, picture[y][x], c);
    }

    public boolean paintFill(Color[][] picture, int x, int y, Color oldColor, Color newColor) {
        Stack<Point> s = new Stack<>();
        s.push(new Point(x, y));
        while (!s.empty()) {
            Point cur = s.pop();
            picture[cur.y][cur.x] = newColor;
            if (cur.x != 0 && picture[cur.y][cur.x-1] == oldColor)
                s.push(new Point(cur.x-1, cur.y));
            if (cur.x != picture[0].length-1 && picture[cur.y][cur.x+1] == oldColor)
                s.push(new Point(cur.x+1, cur.y));
            if (cur.y != 0 && picture[cur.y-1][cur.x] == oldColor)
                s.push(new Point(cur.x, cur.y-1));
            if (cur.y != picture.length-1 && picture[cur.y+1][cur.x] == oldColor)
                s.push(new Point(cur.x, cur.y+1));
        }
        return true;
    }

    private enum Piece {
        PENNY(1, null),
        NICKEL(5, PENNY),
        DIME(10, NICKEL),
        QUARTER(25, DIME);

        Piece(int value, Piece next) {
            this.value = value;
            this.next = next;
        }
        public int value;
        public Piece next;
    }

    public int waysToRepresentNCents(int n) {
        return waysToRepresentNCents(n, Piece.QUARTER);
    }

    private int waysToRepresentNCents(int n, Piece p) {
        if (p == Piece.PENNY)
            return 1;
        int count = 0;
        for (int i = 0; i <= n/p.value; i++) {
            count += waysToRepresentNCents(n - i*p.value, p.next);
        }
        return count;
    }

    private static final int BOARD_SIZE = 8;

    public List<String> queensOnChessBoard() {
        return queensOnChessBoard(new Stack<>());
    }

    private List<String> queensOnChessBoard(Stack<Integer> queens) {
        List<String> l = new ArrayList<>();
        if (queens.size() == BOARD_SIZE) {
            l.add(printBoard(queens));
        } else {
            for (int i = 0; i < BOARD_SIZE; i++) {
                if (isValid(queens, i)) {
                    queens.add(i);
                    l.addAll(queensOnChessBoard(queens));
                    queens.pop();
                }
            }
        }
        return l;
    }

    private boolean isValid(List<Integer> queens, int pos) {
        for (int i = 0; i < queens.size(); i++) {
            if (queens.get(i) == pos || queens.get(i) == pos - (queens.size()-i) || queens.get(i) == pos + (queens.size()-i))
                return false;
        }
        return true;
    }

    private String printBoard(List<Integer> queens) {
        StringBuilder solution = new StringBuilder();
        solution.append("-".repeat(8*2+1)).append("\n");
        for (int i = 0; i < 8; i++) {
            solution.append("|");
            for (int j = 0; j < 8; j++) {
                solution.append((queens.get(i) == j) ? "Q" : " ").append("|");
            }
            solution.append("\n");
            solution.append("-".repeat(8*2+1)).append("\n");
        }
        solution.append("\n\n");
        return solution.toString();
    }
}
