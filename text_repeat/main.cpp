#include <iostream>
void shiftLeft(int n, const char *orig)
{
    char str[500] = {'\0'};
    int l = strlen(orig) - 1;
    for (size_t i = 0; i <= l; i++)
    {
        str[i] = orig[i];
    }

    char t;

    for (int i = 0; i < n; i++)
    {
        t = str[l];
        // std::cout << t << '\n';
        for (int j = l - 1; j >= 0; j--)
        {
            // std::cout << j << ':' << l << '\n';
            str[j + 1] = str[j];
            // std::cout << str << '\n';
        }
        str[0] = t;
    }

    std::cout << str << '\n';
}
int main()
{
    // char str1[100];
    // char str2[100];
    // //"abcdef" , "abc"
    // std::cin >> str1;
    // std::cin >> str2;
    // int l1 = strlen(str1);
    // int l2 = strlen(str2);
    // int found = 0;

    // for (int i = 0; i < l1; i++)
    // {
    //     if (str1[i] == str2[0])
    //     {
    //         // first letter matches
    //         for (int j = 0; j < l2; j++)
    //         {
    //             if (str1[i + j] != str2[j])
    //             {
    //                 break;
    //             }
    //             else if (j + 1 == l2)
    //             {
    //                 found++;
    //             }
    //         }
    //     }
    // }
    // std::cout << found << '\n';
    shiftLeft(3, "abcdef");
    return 0;
}
