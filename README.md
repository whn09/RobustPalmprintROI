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
sudo make install
```

```
cd test
mkdir build
cd build
cmake ..
make gtest_main
make ft_prdt/make # 会报错
```

```
cd samples/cpp_sample
mkdir build
cd build
cmake ..
make
cd ..
./build/run_cpp_sample -i palm_test_date/palm_image.jpg
```