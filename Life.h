#include <vector>
#include <string>

class Life {
public:
	Life(std::uint16_t width, std::uint16_t height);
	std::size_t get_width() const { return desk[0].size(); }
	std::size_t get_height() const { return desk.size(); }
	
	void eval();
	bool get(std::int32_t x, std::int32_t y) const;
	void set(std::int32_t x, std::int32_t y, bool value);
    void set_string(std::int32_t x, std::int32_t y, const std::string& data);

private:
	bool get_prev(std::int32_t x, std::int32_t y) const;
	std::int32_t rem(std::int32_t a, std::int32_t b) const {
		std::int32_t r = a % b;
		return r >= 0 ? r : r + std::abs(b);
	}
	std::int32_t get_num_neighbours(std::int32_t x, std::int32_t y) const;
	std::vector<std::vector<bool>> desk;
	std::vector<std::vector<bool>> desk_prev;
};
