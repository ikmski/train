#include <iostream>
#include <boost/multiprecision/cpp_dec_float.hpp>

namespace mp = boost::multiprecision;
typedef mp::number<mp::cpp_dec_float<10000> > cpp_dec_float;

int main()
{
    cpp_dec_float a  = 1.0;
    cpp_dec_float b  = mp::sqrt((cpp_dec_float)0.5);
    cpp_dec_float t  = 0.25;
    cpp_dec_float x  = 1.0;
    cpp_dec_float an = 0.0;
    cpp_dec_float p  = 0.0;

    cpp_dec_float aStock  = 0.0;
    cpp_dec_float bStock  = 0.0;

    while (a != aStock && b != bStock) {

        aStock = a;
        bStock = b;

        an = (a + b) / 2.0;
        b = mp::sqrt(a * b);
        t -= x * (an - a) * (an - a);
        x *= 2.0;
        a = an;
        p = (a + b) * (a + b) / (4.0 * t);

    }


    std::string strPi = p.str(0, std::ios_base::fixed);
    std::string outStr = "3.\n";

    strPi = strPi.substr(2, strPi.length()-1);

    for (int i = 0; i < 100; ++i) {
        for (int j = 0; j < 10; ++j) {

            int index = i*10*10 + j*10;
            outStr += strPi.substr(index, 10);
            outStr += " ";
        }

        outStr += "\n";

        if ((i+1)%10 == 0) {
            outStr += "\n";
        }
    }

    std::cout << outStr << std::endl;

    return 0;
}

