#include "StringUtils.h"
#include <algorithm>
#include <cctype>
#include <sstream>
#include <vector>
#include <iterator>
#include <numeric> 

namespace StringUtils {

std::string Slice(const std::string &str, ssize_t start, ssize_t end) noexcept {
    const auto sz = static_cast<ssize_t>(str.size());
    end = (end == 0) ? sz : (end < 0 ? sz + end : end);
    start = (start < 0) ? sz + start : start;
    start = std::clamp(start, static_cast<ssize_t>(0), sz);
    end = std::clamp(end, start, sz);
    return std::string(str.begin() + start, str.begin() + end);
}

std::string Capitalize(const std::string &str) noexcept {
    if (str.empty()) return {};
    std::string res(1, static_cast<char>(std::toupper(str.front())));
    for (auto it = str.begin() + 1; it != str.end(); ++it) {
        res += static_cast<char>(std::tolower(*it));
    }
    return res;
}

std::string Upper(const std::string &str) noexcept {
    std::string res;
    res.reserve(str.size());
    for (unsigned char c : str) res += static_cast<char>(std::toupper(c));
    return res;
}

std::string Lower(const std::string &str) noexcept {
    std::string res;
    res.reserve(str.size());
    for (unsigned char c : str) res += static_cast<char>(std::tolower(c));
    return res;
}

std::string LStrip(const std::string &str) noexcept {
    auto first = std::find_if_not(str.begin(), str.end(), [](int c) { 
        return std::isspace(c); 
    });
    return std::string(first, str.end());
}

std::string RStrip(const std::string &str) noexcept {
    auto last = std::find_if_not(str.rbegin(), str.rend(), [](int c) { 
        return std::isspace(c); 
    }).base();
    return std::string(str.begin(), last);
}

std::string Strip(const std::string &str) noexcept {
    return LStrip(RStrip(str));
}

std::string Center(const std::string &str, int width, char fill) noexcept {
    if (width <= static_cast<int>(str.size())) return str;
    int total_pad = width - str.size();
    int right_pad = total_pad / 2;
    int left_pad = total_pad - right_pad;
    return std::string(left_pad, fill) + str + std::string(right_pad, fill);
}

std::string LJust(const std::string &str, int width, char fill) noexcept {
    return (width > static_cast<int>(str.size())) ? 
        str + std::string(width - str.size(), fill) : str;
}

std::string RJust(const std::string &str, int width, char fill) noexcept {
    return (width > static_cast<int>(str.size())) ? 
        std::string(width - str.size(), fill) + str : str;
}

std::string Replace(const std::string &str, const std::string &old, const std::string &rep) noexcept {
    if (old.empty()) return str;
    std::string result;
    size_t last_pos = 0, pos;
    while ((pos = str.find(old, last_pos)) != std::string::npos) {
        result.append(str, last_pos, pos - last_pos);
        result += rep;
        last_pos = pos + old.size();
    }
    result.append(str, last_pos, str.size() - last_pos);
    return result;
}

std::vector<std::string> Split(const std::string &str, const std::string &splt) noexcept {
    std::vector<std::string> tokens;
    if (splt.empty()) {
        std::string token;
        for (char c : str) {
            if (std::isspace(c)) {
                if (!token.empty()) {
                    tokens.push_back(token);
                    token.clear();
                }
            } else {
                token += c;
            }
        }
        if (!token.empty()) tokens.push_back(token);
        return tokens;
    }

    size_t start = 0, end;
    while ((end = str.find(splt, start)) != std::string::npos) {
        tokens.emplace_back(str.substr(start, end - start));
        start = end + splt.size();
    }
    tokens.emplace_back(str.substr(start));
    return tokens;
}

std::string Join(const std::string &sep, const std::vector<std::string> &vect) noexcept {
    if (vect.empty()) return "";
    std::ostringstream oss;
    std::copy(vect.begin(), vect.end() - 1, 
              std::ostream_iterator<std::string>(oss, sep.c_str()));
    oss << vect.back();
    return oss.str();
}

std::string ExpandTabs(const std::string &str, int tabsize) noexcept {
    std::string result;
    size_t col = 0;
    for (char c : str) {
        if (c == '\t') {
            int spaces = tabsize - (col % tabsize);
            result.append(spaces, ' ');
            col += spaces;
        } else {
            result += c;
            col = (c == '\n') ? 0 : col + 1;
        }
    }
    return result;
}

int EditDistance(const std::string &a, const std::string &b, bool nocase) noexcept {
    const auto &left = nocase ? Lower(a) : a;
    const auto &right = nocase ? Lower(b) : b;
    const size_t m = left.size(), n = right.size();
    
    std::vector<int> dp(n + 1);
    // Initialize dp with 0, 1, 2, ..., n
    for (size_t i = 0; i <= n; ++i) {
        dp[i] = static_cast<int>(i);
    }

    for (size_t i = 1; i <= m; ++i) {
        int prev = dp[0];
        dp[0] = static_cast<int>(i);
        for (size_t j = 1; j <= n; ++j) {
            int temp = dp[j];
            dp[j] = std::min({
                dp[j] + 1,
                dp[j - 1] + 1,
                prev + (left[i - 1] != right[j - 1])
            });
            prev = temp;
        }
    }
    return dp[n];
}

} 
// namespace StringUtils