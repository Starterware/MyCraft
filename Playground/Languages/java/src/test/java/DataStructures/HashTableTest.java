package DataStructures;

import org.junit.jupiter.api.Test;

import java.util.HashMap;
import java.util.Map;

import static com.google.common.truth.Truth.assertThat;

public class HashTableTest {
   /**
    * In java, the load factor is 0.75 and the buckets are then doubled. The default capacity is of 16.
    * The implementation is not synchronized.
    * In case of a collision, it uses a liked list and if there are more than TREEIFY_THRESHOLD(8) elements, then
    * it uses a tree instead. It allows to have a worst case of log(n)
    * HashTable can also be used but it is synchronised and therefore slower. To make HashMap thread safe,
    * use Collections.synchronizedMap(map)
    * */
   @Test
   public void HashMapTest() {
      Map<String, String> map = new HashMap<>();
      // How to insert elements
      map.put("key", "value");
      map.put("key2", "value2");
      map.putAll(Map.of("key3", "value3", "key4", "value4"));

      // How to search elements
      assertThat(map.get("key")).isEqualTo("value");
      assertThat(map.get("other")).isNull();
      assertThat(map.containsKey("key")).isTrue();

      // Map properties
      assertThat(map.size()).isEqualTo(4);
      assertThat(map.isEmpty()).isFalse();

      // How to loop
      int count = 0;
      for(var entry : map.entrySet())
         count++;
      assertThat(count).isEqualTo(4);
   }
}
