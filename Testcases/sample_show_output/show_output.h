#include "study_in_pink2.h"

void tc_1001() {
    cout << "----- Testcase 01 -----" << endl;
    Path path = Path();
    cout << path.getType();
}

class TestStudyInPink {
public:
    TestStudyInPink() = default;
    
    static void tc_1001() {
        ::tc_1001();
    }
};

void test() {
    TestStudyInPink::tc_1001();
}