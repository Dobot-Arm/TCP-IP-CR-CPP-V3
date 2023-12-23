#pragma once
#include <sstream>
#include <string>

namespace Dobot
{
    struct CDescartesPoint
    {
    public:
        /// <summary>
        /// X 轴位置，单位：毫米
        /// </summary>
        double x;

        /// <summary>
        /// Y 轴位置，单位：毫米
        /// </summary>
        double y;

        /// <summary>
        /// Z 轴位置，单位：毫米
        /// </summary>
        double z;

        /// <summary>
        /// Rx 轴位置，单位：度
        /// </summary>
        double rx;

        /// <summary>
        /// Ry 轴位置，单位：度
        /// </summary>
        double ry;

        /// <summary>
        /// Rz 轴位置，单位：度
        /// </summary>
        double rz;

        std::string ToString()
        {
            std::ostringstream oss;
            oss << x << ',' << y << ',' << z << ',' << rx << ',' << ry << ',' << rz;
            return oss.str();
        }
    };
}
