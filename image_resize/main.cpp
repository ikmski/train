#include <iostream>
#include <boost/gil/gil_all.hpp>
#include <boost/gil/extension/io/png_io.hpp>
#include <boost/gil/extension/io/jpeg_io.hpp>

namespace gil = boost::gil;

int main(int argc, char* argv[])
{
    // 読み込み
    gil::rgb8_image_t src;
    gil::png_read_image("/usr/local/train/20140729/input/test01.png", src);

    // 変換
    gil::rgb_image_t dst;

    dst = src;


    // 書き込み
    png_write_view("output.png", view(dst));

    return 0;
}

