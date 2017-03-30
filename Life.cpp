#include "Life.h"
#include <array>

Life::Life(std::uint16_t width, std::uint16_t height)
	: desk(height, std::vector<bool>(width, false))
	, desk_prev(desk) {}

void Life::eval() {
	desk_prev = desk;

    for(std::int32_t y = 0; y < get_height(); ++y) {
        for(std::int32_t x = 0; x < get_width(); ++x) {
			const auto neighbours = get_num_neighbours(x, y);
			
			if(neighbours == 3) {
				set(x, y, true);
			}
			if(neighbours < 2 || neighbours > 3) {
				set(x, y, false);
			}
		}
	}
}
bool Life::get(std::int32_t x, std::int32_t y) const {
	return desk[rem(y, get_height())][rem(x, get_width())];
}
bool Life::get_prev(std::int32_t x, std::int32_t y) const {
	return desk_prev[rem(y, get_height())][rem(x, get_width())];
}
void Life::set(std::int32_t x, std::int32_t y, bool value) {
	desk[rem(y, get_height())][rem(x, get_width())] = value;
}
void Life::set_string(std::int32_t x, std::int32_t y, const std::string& data) {
	auto p_x = x;
	auto p_y = y;

	for(const auto c : data) {
		switch(c) {
        case ' ':
            set(p_x++, p_y, false);
			break;
        case '\n':
            ++p_y;
            p_x = x;
            break;
		default:
			set(p_x++, p_y, true);
			break;
		}
	}
}
std::int32_t Life::get_num_neighbours(std::int32_t x, std::int32_t y) const {
    const std::array<bool, 8> neighbours {
		get_prev(x - 1, y - 1),
		get_prev(x - 0, y - 1),
		get_prev(x + 1, y - 1),
		get_prev(x + 1, y - 0),
		get_prev(x + 1, y + 1),
		get_prev(x + 0, y + 1),
		get_prev(x - 1, y + 1),
		get_prev(x - 1, y + 0),
};
    std::int32_t result = 0;
	for(const bool neighbour : neighbours) {
		result += neighbour ? 1 : 0;
	}
    return result;
}
