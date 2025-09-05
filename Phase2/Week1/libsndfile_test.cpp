#include <sndfile.hh>
#include <vector>

int main(int argc, char const *argv[])
{
    SndfileHandle file("Spirited_Away-Always_With_Me.wav");
    if (!file) return 1;
    std::vector<float> data(file.frames() * file.channels());
    file.readf(data.data(), file.frames());
    return 0;
}
