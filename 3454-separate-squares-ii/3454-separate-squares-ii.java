import java.util.*;

class Solution {
    static class Event {
        double y;
        int type; // +1 start, -1 end
        double x1, x2;
        Event(double y, int type, double x1, double x2) {
            this.y = y;
            this.type = type;
            this.x1 = x1;
            this.x2 = x2;
        }
    }

    public double separateSquares(int[][] squares) {
        double total = unionArea(squares, Double.POSITIVE_INFINITY);
        double half = total / 2.0;

        double lo = Double.MAX_VALUE, hi = Double.MIN_VALUE;
        for (int[] s : squares) {
            lo = Math.min(lo, s[1]);
            hi = Math.max(hi, s[1] + s[2]);
        }

        for (int i = 0; i < 70; i++) {
            double mid = (lo + hi) / 2.0;
            if (unionArea(squares, mid) < half) lo = mid;
            else hi = mid;
        }
        return lo;
    }

    private double unionArea(int[][] squares, double yLimit) {
        List<Event> events = new ArrayList<>();

        for (int[] s : squares) {
            double x1 = s[0];
            double x2 = s[0] + s[2];
            double y1 = s[1];
            double y2 = Math.min(s[1] + s[2], yLimit);

            if (y1 < y2) {
                events.add(new Event(y1, 1, x1, x2));
                events.add(new Event(y2, -1, x1, x2));
            }
        }

        if (events.isEmpty()) return 0.0;

        events.sort(Comparator.comparingDouble(e -> e.y));

        TreeMap<Double, Integer> active = new TreeMap<>();
        double prevY = events.get(0).y;
        double area = 0.0;

        for (Event e : events) {
            double curY = e.y;
            double dy = curY - prevY;
            if (dy > 0) {
                area += dy * mergedWidth(active);
            }

            active.put(e.x1, active.getOrDefault(e.x1, 0) + e.type);
            active.put(e.x2, active.getOrDefault(e.x2, 0) - e.type);
            if (active.get(e.x1) == 0) active.remove(e.x1);
            if (active.get(e.x2) == 0) active.remove(e.x2);

            prevY = curY;
        }
        return area;
    }

    private double mergedWidth(TreeMap<Double, Integer> map) {
        double width = 0.0;
        double prevX = 0.0;
        int count = 0;
        boolean first = true;

        for (Map.Entry<Double, Integer> e : map.entrySet()) {
            double x = e.getKey();
            if (!first && count > 0) {
                width += x - prevX;
            }
            count += e.getValue();
            prevX = x;
            first = false;
        }
        return width;
    }
}
