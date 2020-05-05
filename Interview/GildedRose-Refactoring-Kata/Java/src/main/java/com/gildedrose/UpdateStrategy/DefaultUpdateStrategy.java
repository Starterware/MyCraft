package com.gildedrose.UpdateStrategy;

import com.gildedrose.Item;

public class DefaultUpdateStrategy implements UpdateStrategy {
    protected static final int LOWEST_QUALITY_VALUE = 0;

    @Override
    public void update(Item item) {
        updateSellIn(item);
        updateQuality(item);
    }

    protected void updateSellIn(Item item) {
        item.sellIn--;
    }

    protected void updateQuality(Item item) {
        item.quality -= sellDateHasPassed(item) ? 2 : 1;
        if (item.quality < LOWEST_QUALITY_VALUE)
            item.quality = LOWEST_QUALITY_VALUE;
    }

    protected boolean sellDateHasPassed(Item item) {
        return item.sellIn < 0;
    }
}
