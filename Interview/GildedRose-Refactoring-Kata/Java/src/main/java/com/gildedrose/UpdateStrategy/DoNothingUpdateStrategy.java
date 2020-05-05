package com.gildedrose.UpdateStrategy;

import com.gildedrose.Item;

public class DoNothingUpdateStrategy implements UpdateStrategy {
    @Override
    public void update(Item item) {
        // Do nothing
    }
}
