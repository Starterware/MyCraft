package com.gildedrose.UpdateStrategy;

import com.gildedrose.Item;

public class DefaultUpdateStrategy implements UpdateStrategy {
    @Override
    public void update(Item item) {
        updateSellIn(item);
        updateQuality(item);
    }

    protected void updateSellIn(Item item) {
        item.sellIn--;
    }

    protected void updateQuality(Item item) {
        item.quality -= (item.sellIn < 0) ? 2 : 1;
        if (item.quality < 0)
            item.quality = 0;
    }
}
