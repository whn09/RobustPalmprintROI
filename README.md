# PRDT

Palmprint ROI Based on Distance Transform.

## Binari

- RGB2YCrCb
- OTSU

## AdjAngle

- CenGra
- RotatePalm

## DTHandle

- DTAverage
- RegenerateBinImg
 
## GenCirReferPoint

- DetectPeak
- DetecValley
- GenReferncePoint

## GenROI
 
- GenMaxCir
- RotateCir
- GenRoiFromOriImg

# RUN

```
mkdir build
cd build
cmake ..
make
```

```
cd test
mkdir build
cd build
cmake ..
make gtest_main
make ft_prdt/make # 会报错
```