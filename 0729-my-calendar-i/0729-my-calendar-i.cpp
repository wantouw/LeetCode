#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

typedef tree<int, null_type, less_equal<int>, rb_tree_tag,
             tree_order_statistics_node_update>
    ordered_set;

class MyCalendar {
public:
    ordered_set dateStart;
    ordered_set dateEnd;
    MyCalendar() {
        // dates.insert(1);
        // dates.insert(1);
        // cout << (dates.order_of_key(1));
    }

    bool book(int start, int end) {
        int smallerStart = dateStart.order_of_key(start);
        int smallerEnd = dateEnd.order_of_key(end);
        if ((smallerStart == smallerEnd) &&
            (dateEnd.find_by_order(smallerStart - 1) == dateEnd.end() ||
             start >= *(dateEnd.find_by_order(smallerStart - 1))) &&
            (dateStart.find_by_order(smallerEnd) == dateStart.end() ||
             end <= *(dateStart.find_by_order(smallerEnd)))) {
            cout << start << ' ' << *(dateEnd.find_by_order(smallerStart - 1))
                 << endl;
            dateStart.insert(start);
            dateEnd.insert(end);
            return true;
        }
        return false;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */