package CrackingTheCodingInterviewExercices;

import javafx.util.Pair;

import java.util.*;

import static java.lang.Math.abs;

public class FourthChapter {
    public static class Tree {
        Node root;

        public Tree(Node root) {
            this.root = root;
        }

        public Node getRoot() { return root; };

        public static class Node {
            String value;
            Node left;
            Node right;
            Node parent;

            public Node(String value, Node left, Node right) {
                this(value, null, left, right);
            }

            public Node(String value, Node parent, Node left, Node right) {
                this.value = value;
                this.left = left;
                this.right = right;
                this.parent = parent;
            }

            @Override
            public boolean equals(Object o) {
                if (this == o) return true;
                if (!(o instanceof Node)) return false;
                Node node = (Node) o;
                return Objects.equals(value, node.value);
            }

            @Override
            public int hashCode() {
                return Objects.hash(value);
            }
        }
    }

    public static class Graph {
        public static class Vertex {
            String label;
            public Vertex(String label) {
                this.label = label;
            }

            @Override
            public boolean equals(Object o) {
                if (this == o) return true;
                if (!(o instanceof Vertex)) return false;
                Vertex vertex = (Vertex) o;
                return Objects.equals(label, vertex.label);
            }

            @Override
            public int hashCode() {
                return Objects.hash(label);
            }
        }

        Map<Vertex, List<Vertex>> edges = new HashMap<>();

        public void addDirectedEdge(String fromLabel, String toLabel) {
            Vertex from = new Vertex(fromLabel);
            Vertex to = new Vertex(toLabel);
            edges.putIfAbsent(from, new ArrayList<>());
            edges.putIfAbsent(to, new ArrayList<>());
            List<Vertex> vertices = edges.get(from);
            if (!vertices.contains(to))
                vertices.add(to);
        }
    }

    public boolean isBalanced(Tree.Node n) {
        return checkHeight(n) != -1;
    }

    private int checkHeight(Tree.Node n) {
        if (n == null) return 0;
        int leftHeight = checkHeight(n.left);
        if (leftHeight == -1) return leftHeight;
        int rightHeight = checkHeight(n.right);
        if (rightHeight == -1) return rightHeight;

        if (abs(leftHeight - rightHeight) > 1) return -1;
        return 1 + Math.max(leftHeight, rightHeight);
    }

    public boolean routeExists(Graph g, String from, String to) {
        Graph.Vertex start = new Graph.Vertex(from);
        Graph.Vertex end = new Graph.Vertex(to);
        if (!g.edges.containsKey(start) || !g.edges.containsKey(end)) return false;

        Set<Graph.Vertex> visited = new HashSet<>();
        Deque<Graph.Vertex> stack = new ArrayDeque<>();
        stack.push(start);
        while (!stack.isEmpty()) {
            Graph.Vertex v = stack.pop();
            if (v.equals(end)) return true;
            for (Graph.Vertex v2 : g.edges.get(v)) {
                if (!visited.contains(v2)) {
                    visited.add(v2);
                    stack.push(v2);
                }
            }
        }

        return false;
    }

    public Tree createBinarySearchTree(List<String> sortedList) {
        if (sortedList.size() == 0) return new Tree(null);
        Tree.Node root = createBinarySearchTree(sortedList, 0, sortedList.size()-1);
        return new Tree(root);
    }

    public List<List<Tree.Node>> createLinkedListOfNodeLevels(Tree tree) {
        List<List<Tree.Node>> l = new ArrayList<>();
        if (tree.getRoot() == null) return l;
        Deque<Pair<Tree.Node, Integer>> stack = new ArrayDeque<>();
        stack.push(new Pair<>(tree.getRoot(), 0));
        while (!stack.isEmpty()) {
            Pair<Tree.Node, Integer> p = stack.pop();
            Tree.Node n = p.getKey();
            int level = p.getValue();
            if (l.size() <= level) l.add(new LinkedList<>());
            l.get(level).add(n);
            if (n.left != null) stack.push(new Pair<>(n.left, level+1));
            if (n.right != null) stack.push(new Pair<>(n.right, level+1));
        }
        return l;
    }

    private Tree.Node createBinarySearchTree(List<String> sortedList, int start, int end) {
        if (start > end) return null;
        int rootPos = (end + 1 + start)/2;
        Tree.Node leftTree = createBinarySearchTree(sortedList, start, rootPos - 1);
        Tree.Node rightTree = createBinarySearchTree(sortedList, rootPos + 1, end);
        Tree.Node node = new Tree.Node(sortedList.get(rootPos), leftTree, rightTree);
        if (leftTree != null) leftTree.parent = node;
        if (rightTree != null) rightTree.parent = node;
        return node;
    }

    public boolean isBinarySearchTree(Tree tree) {
        return isBinarySearchTree(tree.getRoot(), null, null);
    }

    private boolean isBinarySearchTree(Tree.Node n, String min, String max) {
        if (n == null) return true;
        if (min != null && n.value.compareTo(min) <= 0) return false;
        if (max != null && n.value.compareTo(max) > 0) return false;
        return isBinarySearchTree(n.left, min, n.value) && isBinarySearchTree(n.right, n.value, max);
    }

    public Tree.Node findNextInOrderNode(Tree.Node n) {
        if (n.right != null)
            return findMostLeft(n.right);
        return findFirstParentOnRight(n);
    }

    private Tree.Node findFirstParentOnRight(Tree.Node n) {
        while (n.parent != null && n.parent.right.equals(n))
            n = n.parent;
        return n.parent;
    }

    private Tree.Node findMostLeft(Tree.Node n) {
        while (n.left != null)
            n = n.left;
        return n;
    }

    public Tree.Node findCommonAncestor(Tree.Node n1, Tree.Node n2) {
        Tree.Node root = n1;
        while (root.parent != null)
            root = root.parent;
        return findCommonAncestor(root, new HashSet<>(List.of(n1, n2)));
    }

    private Tree.Node findCommonAncestor(Tree.Node n, Set<Tree.Node> l) {
        if (n == null)
            return null;
        l.remove(n);
        if (l.isEmpty())
            return n;
        Tree.Node commonAncestor = findCommonAncestor(n.left, l);
        if (commonAncestor != null)
            return commonAncestor;
        if (findCommonAncestor(n.right, l) != null)
            return n;
        return null;
    }

    public boolean isSubTree(Tree tree, Tree subTree) {
        if (subTree.getRoot() == null)
            return true;
        return isSubTree(tree.getRoot(), subTree.getRoot());
    }

    private boolean isSubTree(Tree.Node tree, Tree.Node subTree) {
        if (tree == null) return false;
        if (tree.value.equals(subTree.value) && areTreesEqual(tree, subTree))
            return true;
        return isSubTree(tree.left, subTree) || isSubTree(tree.right, subTree);
    }

    private boolean areTreesEqual(Tree.Node tree, Tree.Node subTree) {
        if (tree == null && subTree == null)
            return true;
        if (tree == null || subTree == null)
            return false;
        if (!tree.value.equals(subTree.value))
            return false;
        return areTreesEqual(tree.right, subTree.right) && areTreesEqual(tree.left, subTree.left);
    }

    public List<String> pathsOfSum(Tree t, int sum) {
        return pathsOfSum(t.getRoot(), sum, new Stack<>());
    }

    private List<String> pathsOfSum(Tree.Node n, int sum, Stack<Tree.Node> parents) {
        List<String> solutions = new ArrayList<>();
        if (n != null) {
            parents.push(n);
            solutions.addAll(pathsOfSumFromNode(parents, sum));
            solutions.addAll(pathsOfSum(n.left, sum, parents));
            solutions.addAll(pathsOfSum(n.right, sum, parents));
            parents.pop();
        }
        return solutions;
    }

    private List<String> pathsOfSumFromNode(Vector<Tree.Node> nodes, int sum) {
        int curSum = 0;
        List<String> solutions = new ArrayList<>();
        StringBuilder path = new StringBuilder();
        for (int i = nodes.size()-1; i >= 0; i--) {
            if (path.length() != 0)
                path.insert(0, ":");
            path.insert(0, nodes.get(i).value);
            curSum += Integer.parseInt(nodes.get(i).value);
            if (curSum == sum)
                solutions.add(path.toString());
        }
        return solutions;
    }
}
