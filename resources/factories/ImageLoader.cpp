#include "../../logger/logger.hpp"
#include "../../renderer/resources/texture/image/image.hpp"
#include "../resource_list.hpp"
#include "factories.hpp"

#include <opencv2/opencv.hpp>

#include <cstddef>

namespace factories {
    resourceTypes::Resource* ImageLoader::operator()(std::vector<std::byte> bytes) {
        Logger logger("ImageLoader");

        cv::Mat image = cv::imdecode(bytes, cv::IMREAD_UNCHANGED);
        if (image.empty()) {
            logger.log("Failed to load image!");
            return nullptr;
        }
        if (image.channels() == 1)
            cv::cvtColor(image, image, cv::COLOR_GRAY2RGBA);
        else if (image.channels() == 3)
            cv::cvtColor(image, image, cv::COLOR_RGB2RGBA);
        else if (image.channels() != 4) {
            logger.log("Unsupported image channel type!");
            return nullptr;
        }
        //cv::flip(image, image, 0);
        return new resourceTypes::ResourceImage(Image(
            std::vector<std::byte>(reinterpret_cast<const std::byte*>(image.datastart), reinterpret_cast<const std::byte*>(image.dataend)), glm::uvec2(image.cols, image.rows)));

    }
}