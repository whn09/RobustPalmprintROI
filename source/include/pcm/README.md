# PRDT Control Module

PRDT(`Palmprint ROI Based on Distance Transform`)算法逻辑控制模块，负责控制其他模块间协调工作。

- 向上：对接PRDT算法提供的API接口，
- 向下：控制PDM PPM ERM模块对掌纹图像提取感兴趣区域。

功能：

1. extractROI(src, dst, bAsync);