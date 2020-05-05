package com.gildedrose;

import com.gildedrose.UpdateStrategy.UpdateStrategyFactory;

class GildedRose {
    private Item[] items;
    private UpdateStrategyFactory updateStrategyFactory = new UpdateStrategyFactory();

    public GildedRose(Item[] items) {
        this.items = items;
    }

    public void updateQuality() {
        for (Item item : items) {
            updateStrategyFactory.getStrategy(item).update(item);
        }
    }

    public Item[] items() {
        return items;
    }
}