// 아래와 같이 main함수에서 여러분이 작성한 stock.h와 transaction.h 파일을
// include 하여 주어진 동작을 실행하게 됩니다.
// *** 주의! 아래의 내용을 변경할 경우 오답처리될 수 있습니다. **
#include <iostream>
#include <string>
#include <sstream>
#include "stock.h"
#include "transaction.h"

using namespace std;

int main(void)
{
    char action;
    int quantity, price;
    StockTrade s;
    
    while (cin >> action) {
        if (action == 'b' || action == 's') {
            cin >> quantity >> price;
            if (action == 'b') {
                s.buy(Transaction(quantity, price));
            } else {
                try {
                    s.sell(Transaction(quantity, price));
                } catch (const SellMoreSharesException &e) {
                    cout << "Insufficient shares:" << e.getInsufficientQuantity() << endl;
                    return -1;
                }
            }
        } else if (action == 'g') {
            cout << s.getTotalGain() << endl;
        } else if (action == 'q') {
            break;
        }
    }
    
    return 0;
}