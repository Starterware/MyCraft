package DataStructures;

import org.junit.jupiter.api.Test;

import java.util.LinkedList;
import java.util.List;

import static com.google.common.truth.Truth.assertThat;
import static org.junit.jupiter.api.Assertions.assertThrows;

public class ListTest {
    @Test
    void linkedList() {
        LinkedList<String> list = new LinkedList<>();

        // How to append elements - O(1) - because linked list is doubly linked
        list.add("key");
        list.add(1, "key2"); // will be more efficient than an array - no need to shift the values
        list.addAll(List.of("key3", "key4"));

        // How to search elements - O(n)
        assertThat(list.get(0)).isEqualTo("key");
        assertThrows(IndexOutOfBoundsException.class, () -> list.get(5));
        assertThat(list.contains("key2")).isTrue(); // O(n)

        // List properties
        assertThat(list.size()).isEqualTo(4);
        assertThat(list.isEmpty()).isFalse();

        // How to loop
        int count = 0;
        for(var elem : list)
            count++;
        assertThat(count).isEqualTo(4);
    }
}
