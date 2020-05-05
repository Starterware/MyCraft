package com.gildedrose.UpdateStrategy;

import com.gildedrose.Item;

import java.util.Map;
import java.util.TreeMap;

public class UpdateStrategyFactory {
    private Map<String, UpdateStrategy> exactKeyUpdateStrategyMap = new TreeMap<>();
    private Map<String, UpdateStrategy> containsKeyUpdateStrategyMap = new TreeMap<>();
    private UpdateStrategy defaultUpdateStrategy = new DefaultUpdateStrategy();

    public UpdateStrategyFactory() {
        exactKeyUpdateStrategyMap.put("Sulfuras, Hand of Ragnaros", new DoNothingUpdateStrategy());
        exactKeyUpdateStrategyMap.put("Backstage passes to a TAFKAL80ETC concert", new TicketUpdateStrategy());
        exactKeyUpdateStrategyMap.put("Aged Brie", new GetBetterWithTimeUpdateStrategy());

        containsKeyUpdateStrategyMap.put("Conjured", new ConjuredUpdateStrategy());
    }

    public UpdateStrategy getStrategy(Item item) {
        if (exactKeyUpdateStrategyMap.containsKey(item.name)) {
            return exactKeyUpdateStrategyMap.get(item.name);
        }

        for (Map.Entry<String, UpdateStrategy> entry : containsKeyUpdateStrategyMap.entrySet()) {
            if (item.name.contains(entry.getKey())) {
                return entry.getValue();
            }
        }

        return defaultUpdateStrategy;
    }
}
