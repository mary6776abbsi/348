#include <iostream>
#include <string>
using namespace std;

// تابع برای اعتبار سنجی شماره کارت
bool validateCard(const string& cardNumber) {
    // در اینجا اعتبار سنجی شماره کارت انجام می‌شود
    // در این مثال، ما فقط یک شماره کارت معتبر داریم که آن را در نظر می‌گیریم
    string validCardNumber = "1234567890123456";
    return (cardNumber == validCardNumber);
}

// تابع برای جدا کردن شماره کارت به دسته‌های ۴ رقمی و چاپ
void splitAndPrintCardNumber(const string& cardNumber) {
    cout << "Separated card number:" << endl;
    for (int i = 0; i < 16; i += 4) {
        cout << cardNumber.substr(i, 4) << endl;
    }
}

int main() {
    string cardNumber;

    cout << "Enter your card number: ";
    cin >> cardNumber;

    // تا اندازه‌ی کافی ورودی گرفته شود
    while (cardNumber.length() < 16) {
        cout << "Please enter the next digit: ";
        string digit;
        cin >> digit;

        // اگر عدد وارد شده صحیح نبود، خطا را چاپ کنید و به ورودی بعدی بروید
        if (digit.length() != 1 || !isdigit(digit[0])) {
            cout << "Error: Please enter a valid digit." << endl;
            continue;
        }

        // نمایش اطلاعات ورودی پیشین
        cout << "Previous input: " << cardNumber << endl;

        // افزودن رقم جدید به شماره کارت
        cardNumber += digit;

        // اعتبار سنجی کارت برای حالتی که ۴ رقم ورودی شده است
        if (cardNumber.length() >= 4 && cardNumber.length() % 4 == 0) {
            if (!validateCard(cardNumber)) {
                cout << "Error: Invalid card number." << endl;
                return 1;
            }
        }
    }

    // اعتبار سنجی کارت برای حالتی که ۱۶ رقم ورودی شده است
    if (!validateCard(cardNumber)) {
        cout << "Error: Invalid card number." << endl;
        return 1;
    }

    // نمایش شماره کارت جدا شده به دسته‌های ۴ رقمی
    splitAndPrintCardNumber(cardNumber);

    return 0;
}
