package CrackingTheCodingInterviewExercices;

import jdk.jfr.Description;
import org.junit.jupiter.api.Test;

import java.util.List;

import static com.google.common.truth.Truth.assertThat;

/**
 * Exercises from Cracking the code interview - Chapter 4 - Trees and Graphs
 */
public class FourthChapterTest {
    FourthChapter chapter = new FourthChapter();

    @Test
    @Description("Exercise 1")
    void testIsBalanced() {
        FourthChapter.Tree.Node d = buildNode("d", null, null);
        FourthChapter.Tree.Node b = buildNode("b", d, null);
        FourthChapter.Tree.Node c = buildNode("c", null, null);
        FourthChapter.Tree.Node a = buildNode("a", b, c);

        assertThat(chapter.isBalanced(a)).isTrue();

        FourthChapter.Tree.Node e = buildNode("e", null, null);
        d.right = e;

        assertThat(chapter.isBalanced(a)).isFalse();
    }

    @Test
    @Description("Exercise 2")
    void testRouteExists() {
        FourthChapter.Graph g = new FourthChapter.Graph();
        g.addDirectedEdge("a", "b");
        g.addDirectedEdge("a", "c");
        g.addDirectedEdge("c", "d");
        g.addDirectedEdge("b", "d");
        g.addDirectedEdge("b", "e");
        assertThat(chapter.routeExists(g, "c", "e")).isFalse();

        g.addDirectedEdge("d", "e");
        assertThat(chapter.routeExists(g, "c", "e")).isTrue();
    }

    @Test
    @Description("Exercise 3")
    void testCreateBinarySearchTree() {
        List<String> sortedList = List.of("a", "b", "c", "d", "e");
        FourthChapter.Tree tree = chapter.createBinarySearchTree(sortedList);
        assertThat(tree.getRoot().value).isEqualTo("c");
        assertThat(tree.getRoot().left.value).isEqualTo("b");
        assertThat(tree.getRoot().left.left.value).isEqualTo("a");
        assertThat(tree.getRoot().right.value).isEqualTo("e");
        assertThat(tree.getRoot().right.left.value).isEqualTo("d");

        List<String> sortedList2 = List.of("a", "b", "c", "d");
        FourthChapter.Tree tree2 = chapter.createBinarySearchTree(sortedList2);
        assertThat(tree2.getRoot().value).isEqualTo("c");
        assertThat(tree2.getRoot().left.value).isEqualTo("b");
        assertThat(tree2.getRoot().left.left.value).isEqualTo("a");
        assertThat(tree2.getRoot().right.value).isEqualTo("d");
    }

    @Test
    @Description("Exercise 4")
    void testCreateLinkedListOfNodeLevels() {
        FourthChapter.Tree tree = chapter.createBinarySearchTree(List.of("a", "b", "c", "d", "e", "f", "g", "h", "i", "j"));
        List<List<FourthChapter.Tree.Node>> l = chapter.createLinkedListOfNodeLevels(tree);
        assertThat(l.get(0)).containsExactly(buildNode("f"));
        assertThat(l.get(1)).containsExactly(buildNode("c"), buildNode("i"));
        assertThat(l.get(2)).containsExactly(buildNode("b"), buildNode("e"), buildNode("h"), buildNode("j"));
        assertThat(l.get(3)).containsExactly(buildNode("a"), buildNode("d"), buildNode("g"));
    }

    @Test
    @Description("Exercise 5")
    void testIsBinarySearchTree() {
        FourthChapter.Tree tree = chapter.createBinarySearchTree(List.of("a", "b", "c", "d", "e", "f", "g", "h", "i", "j"));
        assertThat(chapter.isBinarySearchTree(tree)).isTrue();
        tree.getRoot().left.left.right = buildNode("z");
        assertThat(chapter.isBinarySearchTree(tree)).isFalse();
        FourthChapter.Tree aaTree = chapter.createBinarySearchTree(List.of("a", "a"));
        assertThat(chapter.isBinarySearchTree(aaTree)).isTrue();
        aaTree.getRoot().right = aaTree.getRoot().left;
        aaTree.getRoot().left = null;
        assertThat(chapter.isBinarySearchTree(aaTree)).isFalse();
    }

    @Test
    @Description("Exercise 6")
    void testFindNextInOrderNode() {
        FourthChapter.Tree tree = chapter.createBinarySearchTree(List.of("a", "b", "c", "d", "e", "f", "g", "h", "i", "j"));
        assertThat(chapter.findNextInOrderNode(tree.getRoot().left).value).isEqualTo("d");
        assertThat(chapter.findNextInOrderNode(tree.getRoot().right).value).isEqualTo("j");
        assertThat(chapter.findNextInOrderNode(tree.getRoot()).value).isEqualTo("g");
        assertThat(chapter.findNextInOrderNode(tree.getRoot().left.right).value).isEqualTo("f");
        assertThat(chapter.findNextInOrderNode(tree.getRoot().right.right)).isNull();
    }

    @Test
    @Description("Exercise 7")
    void testFindCommonAncestor() {
        FourthChapter.Tree tree = chapter.createBinarySearchTree(List.of("a", "b", "c", "d", "e", "f", "g", "h", "i", "j"));
        FourthChapter.Tree.Node n1 = tree.getRoot().left.left.left;
        FourthChapter.Tree.Node n2 = tree.getRoot().left.right.left;
        assertThat(chapter.findCommonAncestor(n1, n2).value).isEqualTo("c");
        n2 = tree.getRoot().right.left.left;
        assertThat(chapter.findCommonAncestor(n1, n2).value).isEqualTo("f");
    }

    @Test
    @Description("Exercise 8")
    void testIsSubTree() {
        FourthChapter.Tree tree = chapter.createBinarySearchTree(List.of("a", "b", "c", "d", "e", "f", "g", "h", "i", "j"));
        FourthChapter.Tree subTree = chapter.createBinarySearchTree(List.of("g", "h", "i", "j"));
        FourthChapter.Tree notASubTree = chapter.createBinarySearchTree(List.of("g", "h", "i", "k"));

        assertThat(chapter.isSubTree(tree, subTree)).isTrue();
        assertThat(chapter.isSubTree(tree, notASubTree)).isFalse();
    }

    @Test
    @Description("Exercise 9")
    void testPathsOfSum() {
        FourthChapter.Tree t = chapter.createBinarySearchTree(List.of("1", "2", "3", "4", "5", "6", "7"));
        t.getRoot().left.left.left = buildNode("8");
        t.getRoot().right.left.left = buildNode("-2");

        List<String> paths = chapter.pathsOfSum(t, 3);
        assertThat(paths).containsExactly("2:1", "3", "5:-2");
    }

    private FourthChapter.Tree.Node buildNode(String s) {
        return buildNode(s, null, null);
    }

    private FourthChapter.Tree.Node buildNode(String s, FourthChapter.Tree.Node left, FourthChapter.Tree.Node right) {
        return new FourthChapter.Tree.Node(s, left, right);
    }
}
