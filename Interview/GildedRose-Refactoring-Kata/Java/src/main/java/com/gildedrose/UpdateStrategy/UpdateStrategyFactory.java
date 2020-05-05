package com.gildedrose.UpdateStrategy;

import com.gildedrose.Item;

import java.util.Map;
import java.util.TreeMap;

public class UpdateStrategyFactory {
    private Map<String, UpdateStrategy> exactKeyUpdateStrategyMap = new TreeMap<>();
    private UpdateStrategy defaultUpdateStrategy = new DefaultUpdateStrategy();

    public UpdateStrategyFactory() {
        exactKeyUpdateStrategyMap.put("Sulfuras, Hand of Ragnaros", new DoNothingUpdateStrategy());
        exactKeyUpdateStrategyMap.put("Backstage passes to a TAFKAL80ETC concert", new TicketUpdateStrategy());
        exactKeyUpdateStrategyMap.put("Aged Brie", new GetBetterWithTimeUpdateStrategy());
    }

    public UpdateStrategy getStrategy(Item item) {
        if (exactKeyUpdateStrategyMap.containsKey(item.name)) {
            return exactKeyUpdateStrategyMap.get(item.name);
        }

        return defaultUpdateStrategy;
    }
}
