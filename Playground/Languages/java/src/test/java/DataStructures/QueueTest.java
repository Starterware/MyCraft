package DataStructures;

import org.junit.jupiter.api.Test;

import java.util.LinkedList;
import java.util.PriorityQueue;
import java.util.Queue;

import static com.google.common.truth.Truth.assertThat;

public class QueueTest {
    @Test
    void linkedList() {
        Queue<Integer> queue = new LinkedList<>();

        // How to add elements - O(1)
        queue.add(1);
        queue.add(2);
        queue.add(3);

        // Queue properties
        assertThat(queue.isEmpty()).isFalse();
        assertThat(queue.size()).isEqualTo(3);

        // Operations on the next item - O(1)
        // FIFO - first in first out
        assertThat(queue.peek()).isEqualTo(1);
        assertThat(queue.poll()).isEqualTo(1);
        assertThat(queue.poll()).isEqualTo(2);
        assertThat(queue.poll()).isEqualTo(3);

        // Stack properties
        assertThat(queue.isEmpty()).isTrue();
        assertThat(queue.size()).isEqualTo(0);
    }

    /**
     * It is a queue that is not in FIFO mode but gives the element with the biggest priority
     * Therefore you must create a Comparator for the given type or use a Comparable type
     * class c implements Comparable<Type> {
     *     @Override
     *     public int compareTo(Type other) {
     *      // compare
     *     }
     * }
     * class c implements Comparator<Player> {
     *     @Override
     *     public int compare(Type first, Type second) {
     *      // compare
     *     }
     * }
     * A negative value = less than, 0 is equal to and a positive is bigger than
     * With Java 8, lambda expressions can be used (a, b) ->
     */
    @Test
    void priorityQueue() {
        Queue<Integer> queue = new PriorityQueue<>();

        // How to add elements - O(1)
        queue.add(4);
        queue.add(2);
        queue.add(3);

        // Queue properties
        assertThat(queue.isEmpty()).isFalse();
        assertThat(queue.size()).isEqualTo(3);

        // Operations on the next item - O(1)
        assertThat(queue.peek()).isEqualTo(2);
        assertThat(queue.poll()).isEqualTo(2);
        assertThat(queue.poll()).isEqualTo(3);
        assertThat(queue.poll()).isEqualTo(4);

        // Stack properties
        assertThat(queue.isEmpty()).isTrue();
        assertThat(queue.size()).isEqualTo(0);
    }
}
