#include <SPI.h>


// pins used for the connection with the sensor
// the other you need are controlled by the SPI library):
const int dataReadyPin = 9;
const int chipSelectPin = 10;

void setup() {
  Serial.begin(9600);

  // initalize the  data ready and chip select pins:
  pinMode(dataReadyPin, INPUT);
  pinMode(chipSelectPin, OUTPUT);

  digitalWrite(chipSelectPin, HIGH);


  // start the SPI library:
  SPI.begin();

  delay(800);

  byte result = 0x00;
  
  writeRegister(0x1A, 0xB3); // RST Phase 1 - 509451 to 509531
  writeRegister(0x1A, 0x5E); // RST Phase 2 - 509536 to 509615
  writeRegister(0x00, 0xFF); // CS0 - 509625 to 509705
  writeRegister(0x01, 0xFF); // CS1 - 509710 to 509789
  writeRegister(0x1B, 0x74); // Unknown - 509796 to 509875
  writeRegister(0x1B, 0x9B); // Unknown - 509881 to 509960
  writeRegister(0x2A, 0x7B); // Unknown - 509966 to 510045
  writeRegister(0x2B, 0x14); // Unknown - 510052 to 510128
  writeRegister(0x22, 0x60); // Unknown - 510136 to 510211
  writeRegister(0x35, 0x41); // Unknown - 510219 to 510296
  writeRegister(0x34, 0x02); // Unknown - 510303 to 510378
  writeRegister(0x36, 0x03); // Unknown - 510386 to 510463
  writeRegister(0x24, 0x10); // Unknown - 510470 to 510546
  writeRegister(0x32, 0x33); // Unknown - 510552 to 510630
  writeRegister(0x33, 0x44); // Unknown - 510637 to 510713
  writeRegister(0x31, 0x87); // Unknown - 510721 to 510799
  writeRegister(0x32, 0x11); // Unknown - 510805 to 510882
  writeRegister(0x33, 0x22); // Unknown - 510889 to 510965
  writeRegister(0x31, 0x88); // Unknown - 510973 to 511050
  writeRegister(0x32, 0xFF); // Unknown - 511056 to 511136
  writeRegister(0x33, 0x00); // Unknown - 511143 to 511218
  writeRegister(0x31, 0x89); // Unknown - 511226 to 511303
  writeRegister(0x32, 0xEE); // Unknown - 511310 to 511389
  writeRegister(0x33, 0xEE); // Unknown - 511395 to 511475
  writeRegister(0x31, 0x8A); // Unknown - 511481 to 511559
  writeRegister(0x22, 0x00); // Unknown - 511565 to 511641
  writeRegister(0x04, 0x02); // RX Enable - 511647 to 511723
  writeRegister(0x00, 0xFF); // CS0 - 511729 to 511808
  writeRegister(0x01, 0xFF); // CS1 - 511814 to 511893
  writeRegister(0x02, 0x00); // Int1Msk - 511900 to 511975
  writeRegister(0x03, 0x01); // Int2Msk - 511981 to 512057
  writeRegister(0x06, 0x37); // PWR-CFG - 512069 to 512147
  writeRegister(0x06, 0x17); // PWR-CFG - 512636 to 512715
  writeRegister(0x04, 0x00); // RDO-OFF - 512720 to 512794
  writeRegister(0x0B, 0x1D); // RC Ack Config - 512802 to 512880
  result = readRegister(0x3D); // Unknown - Expect 0x08 - 512890 to 513038
  writeRegister(0x3D, 0x32); // Unknown - 513065 to 513143
  writeRegister(0x07, 0x1A); // Channel Selection - 513153 to 513231
  writeRegister(0x16, 0x10); // FIFO CTRL - 513237 to 513314
  writeRegister(0x00, 0xFF); // CS0 - 513320 to 513399
  writeRegister(0x01, 0xFF); // CS1 - 513405 to 513484
  writeRegister(0x0E, 0x5A); // ADDR - 513491 to 513569
  writeRegister(0x0F, 0x00); // ADDR - 513575 to 513652
  writeRegister(0x10, 0x5A); // ADDR - 513658 to 513734
  writeRegister(0x11, 0x5A); // PEER - 513742 to 513818
  writeRegister(0x12, 0x00); // PEER - 513826 to 513900
  writeRegister(0x13, 0x5A); // PEER - 513908 to 513986

  writeRegister(0x04, 0x02); // RX Enable - 513992 to 514068
  writeRegister(0x02, 0x80); // Int1Msk - 514074 to 514150
  writeRegister(0x03, 0x00); // Int2Msk - 514156 to 514232
  writeRegister(0x00, 0xFF); // CS0 - 514239 to 514317
  writeRegister(0x01, 0xFF); // CS1 - 514323 to 514402
  delay(24); // Delay 24065 cycles
  writeRegister(0x09, 0x10); // Unknown - 538391 to 538467
  delay(24); // Delay 24137 cycles
  result = readRegister(0x09); // Unknown - Expect 0x10 - 562457 to 562604
  writeRegister(0x09, 0x00); // Unknown - 562616 to 562692
  writeRegister(0x04, 0x00); // RDO-OFF - 562698 to 562772
  writeRegister(0x00, 0xFF); // CS0 - 562780 to 562858
  writeRegister(0x07, 0x0F); // Channel Selection - 562865 to 562943
  writeRegister(0x16, 0x10); // FIFO CTRL - 562949 to 563026
  writeRegister(0x00, 0xFF); // CS0 - 563032 to 563111
  writeRegister(0x01, 0xFF); // CS1 - 563117 to 563196
  
  
  
  
  
  
  writeRegister(0x04, 0x02); // RX Enable - 563704 to 563780
  writeRegister(0x02, 0x80); // Int1Msk - 563786 to 563862
  writeRegister(0x03, 0x00); // Int2Msk - 563868 to 563944
  writeRegister(0x00, 0xFF); // CS0 - 563950 to 564029
  writeRegister(0x01, 0xFF); // CS1 - 564035 to 564114
  delay(24); // Delay 24044 cycles
  writeRegister(0x09, 0x10); // Unknown - 588082 to 588158
  delay(24); // Delay 24139 cycles
  result = readRegister(0x09); // Unknown - Expect 0x11 - 612148 to 612297
  writeRegister(0x09, 0x00); // Unknown - 612309 to 612383
  writeRegister(0x04, 0x00); // RDO-OFF - 612391 to 612466
  writeRegister(0x00, 0xFF); // CS0 - 612472 to 612551
  writeRegister(0x07, 0x05); // Channel Selection - 612557 to 612634
  writeRegister(0x16, 0x10); // FIFO CTRL - 612641 to 612716
  writeRegister(0x00, 0xFF); // CS0 - 612724 to 612802
  writeRegister(0x01, 0xFF); // CS1 - 612809 to 612888
  
  
  
  
  
  
  writeRegister(0x04, 0x02); // RX Enable - 613396 to 613470
  writeRegister(0x02, 0x80); // Int1Msk - 613478 to 613552
  writeRegister(0x03, 0x00); // Int2Msk - 613560 to 613634
  writeRegister(0x00, 0xFF); // CS0 - 613642 to 613720
  writeRegister(0x01, 0xFF); // CS1 - 613727 to 613806
  delay(24); // Delay 24044 cycles
  writeRegister(0x09, 0x10); // Unknown - 637773 to 637850
  delay(24); // Delay 24137 cycles
  result = readRegister(0x09); // Unknown - Expect 0x10 - 661840 to 661987
  writeRegister(0x09, 0x00); // Unknown - 661999 to 662075
  writeRegister(0x04, 0x00); // RDO-OFF - 662081 to 662157
  writeRegister(0x00, 0xFF); // CS0 - 662163 to 662243
  writeRegister(0x06, 0x13); // PWR-CFG - 662276 to 662353
  delay(41); // Delay 41077 cycles
  writeRegister(0x0B, 0x1D); // RC Ack Config - 703293 to 703430
  writeRegister(0x07, 0x05); // Channel Selection - 703445 to 703584
  writeRegister(0x16, 0x10); // FIFO CTRL - 703601 to 703739
  writeRegister(0x00, 0xFF); // CS0 - 703749 to 703890
  writeRegister(0x01, 0xFF); // CS1 - 703903 to 704047
  
  
  
  
  
  
  writeRegister(0x04, 0x02); // RX Enable - 704944 to 705077
  writeRegister(0x02, 0x80); // Int1Msk - 705091 to 705224
  writeRegister(0x03, 0x00); // Int2Msk - 705238 to 705371
  writeRegister(0x00, 0xFF); // CS0 - 705382 to 705521
  writeRegister(0x01, 0xFF); // CS1 - 705535 to 705673
  delay(44); // Delay 44440 cycles
  writeRegister(0x04, 0x00); // RDO-OFF - 749976 to 750113
  writeRegister(0x00, 0xFF); // CS0 - 750119 to 750258
  writeRegister(0x0B, 0x0D); // RC Ack Config - 750269 to 750407
  writeRegister(0x08, 0x31); // Unknown - 750421 to 750555
  writeRegister(0x0C, 0x02); // Unknown - 750566 to 750703
  writeRegister(0x07, 0x05); // Channel Selection - 750719 to 750853
  writeRegister(0x00, 0xFF); // CS0 - 750875 to 751012
  writeRegister(0x01, 0xFF); // CS1 - 751024 to 751166
  
  
  
  
  
  
  writeRegister(0x14, 0x1F); // TX Length - 752069 to 752205
  writeRegister(0x02, 0x40); // Int1Msk - 752219 to 752352
  writeRegister(0x03, 0x00); // Int2Msk - 752362 to 752496
  writeRegister(0x00, 0xFF); // CS0 - 752509 to 752649
  writeRegister(0x01, 0xFF); // CS1 - 752659 to 752799
  writeRegister(0x00, 0xFF); // CS0 - 757961 to 758097
  writeRegister(0x01, 0xFF); // CS1 - 758111 to 758252
  writeRegister(0x16, 0xC0); // FIFO CTRL - 758261 to 758399
  
  
  
  
  
  writeRegister(0x04, 0x02); // RX Enable - 3753526 to 3753659
  writeRegister(0x02, 0x80); // Int1Msk - 3753673 to 3753806
  writeRegister(0x03, 0x00); // Int2Msk - 3753820 to 3753953
  writeRegister(0x00, 0xFF); // CS0 - 3753964 to 3754103
  writeRegister(0x01, 0xFF); // CS1 - 3754117 to 3754255
  delay(52); // Delay 52158 cycles
  writeRegister(0x04, 0x00); // RDO-OFF - 3806279 to 3806413
  writeRegister(0x00, 0xFF); // CS0 - 3806425 to 3806561
  writeRegister(0x0B, 0x0D); // RC Ack Config - 3806575 to 3806710
  writeRegister(0x08, 0x31); // Unknown - 3806724 to 3806858
  writeRegister(0x0C, 0x02); // Unknown - 3806872 to 3807006
  writeRegister(0x07, 0x0F); // Channel Selection - 3807022 to 3807162
  writeRegister(0x00, 0xFF); // CS0 - 3807179 to 3807320
  writeRegister(0x01, 0xFF); // CS1 - 3807333 to 3807477
  
  
  
  
  
  
  writeRegister(0x16, 0xC0); // FIFO CTRL - 3822460 to 3822601
  
  writeRegister(0x04, 0x00); // RDO-OFF - 6807794 to 6807926
  writeRegister(0x00, 0xFF); // CS0 - 6807937 to 6808076
  writeRegister(0x0B, 0x1D); // RC Ack Config - 6808090 to 6808227
  writeRegister(0x07, 0x1A); // Channel Selection - 6808241 to 6808380
  writeRegister(0x16, 0x10); // FIFO CTRL - 6808403 to 6808537
  writeRegister(0x00, 0xFF); // CS0 - 6808551 to 6808688
  writeRegister(0x01, 0xFF); // CS1 - 6808700 to 6808842
  
  
  delay(50);
  
  
  
  writeRegister(0x04, 0x02); // RX Enable - 6809745 to 6809879
  writeRegister(0x02, 0x80); // Int1Msk - 6809889 to 6810022
  writeRegister(0x03, 0x00); // Int2Msk - 6810036 to 6810169
  writeRegister(0x00, 0xFF); // CS0 - 6810183 to 6810319
  writeRegister(0x01, 0xFF); // CS1 - 6810333 to 6810474
  delay(52); // Delay 52159 cycles
  writeRegister(0x04, 0x00); // RDO-OFF - 6862500 to 6862633
  writeRegister(0x00, 0xFF); // CS0 - 6862643 to 6862784
  writeRegister(0x0B, 0x0D); // RC Ack Config - 6862797 to 6862933
  writeRegister(0x08, 0x31); // Unknown - 6862946 to 6863081
  writeRegister(0x0C, 0x02); // Unknown - 6863094 to 6863227
  writeRegister(0x07, 0x1A); // Channel Selection - 6863243 to 6863378
  writeRegister(0x00, 0xFF); // CS0 - 6863401 to 6863540
  writeRegister(0x01, 0xFF); // CS1 - 6863551 to 6863692
  
  
  
  delay(50);
  
  
  writeRegister(0x14, 0x1F); // TX Length - 6864596 to 6864739
  writeRegister(0x02, 0x40); // Int1Msk - 6864745 to 6864878
  writeRegister(0x03, 0x00); // Int2Msk - 6864892 to 6865025
  writeRegister(0x00, 0xFF); // CS0 - 6865039 to 6865175
  writeRegister(0x01, 0xFF); // CS1 - 6865189 to 6865330
  writeRegister(0x00, 0xFF); // CS0 - 6870402 to 6870543
  writeRegister(0x01, 0xFF); // CS1 - 6870556 to 6870700
  writeRegister(0x16, 0xC0); // FIFO CTRL - 6870706 to 6870844
  writeRegister(0x40, 0x03); // TX Buffer - 6870855 to 6870988
  writeRegister(0x41, 0x0E); // TX Buffer - 6871002 to 6871137
  writeRegister(0x44, 0x23); // TX Buffer - 6871151 to 6871285
  writeRegister(0x45, 0x11); // TX Buffer - 6871299 to 6871435
  writeRegister(0x46, 0x13); // TX Buffer - 6871447 to 6871584
  writeRegister(0x04, 0x07); // TX - 6871596 to 6871732
  writeRegister(0x00, 0xFF); // CS0 - 6878377 to 6878521
  writeRegister(0x01, 0xFF); // CS1 - 6878527 to 6878667
  writeRegister(0x16, 0xC0); // FIFO CTRL - 6878681 to 6878816
  writeRegister(0x40, 0x03); // TX Buffer - 6878830 to 6878963
  writeRegister(0x41, 0x0E); // TX Buffer - 6878974 to 6879112
  writeRegister(0x44, 0x23); // TX Buffer - 6879122 to 6879260
  writeRegister(0x45, 0x11); // TX Buffer - 6879271 to 6879410
  writeRegister(0x46, 0x13); // TX Buffer - 6879419 to 6879559
  writeRegister(0x04, 0x07); // TX - 6879571 to 6879707
  writeRegister(0x00, 0xFF); // CS0 - 6886434 to 6886573
  writeRegister(0x01, 0xFF); // CS1 - 6886584 to 6886725
  writeRegister(0x16, 0xC0); // FIFO CTRL - 6886737 to 6886872
  writeRegister(0x40, 0x03); // TX Buffer - 6886886 to 6887021
  writeRegister(0x41, 0x0E); // TX Buffer - 6887033 to 6887168
  writeRegister(0x44, 0x23); // TX Buffer - 6887182 to 6887316
  writeRegister(0x45, 0x11); // TX Buffer - 6887330 to 6887466
  writeRegister(0x46, 0x13); // TX Buffer - 6887479 to 6887615
  writeRegister(0x04, 0x07); // TX - 6887628 to 6887763
  writeRegister(0x00, 0xFF); // CS0 - 6894409 to 6894546
  writeRegister(0x01, 0xFF); // CS1 - 6894559 to 6894700
  writeRegister(0x16, 0xC0); // FIFO CTRL - 6894709 to 6894847
  writeRegister(0x40, 0x03); // TX Buffer - 6894857 to 6894999
  writeRegister(0x41, 0x0E); // TX Buffer - 6895005 to 6895143
  writeRegister(0x44, 0x23); // TX Buffer - 6895153 to 6895295
  writeRegister(0x45, 0x11); // TX Buffer - 6895302 to 6895444
  writeRegister(0x46, 0x13); // TX Buffer - 6895450 to 6895590
  writeRegister(0x04, 0x07); // TX - 6895599 to 6895741
  writeRegister(0x00, 0xFF); // CS0 - 6902380 to 6902521
  writeRegister(0x01, 0xFF); // CS1 - 6902530 to 6902670
  writeRegister(0x16, 0xC0); // FIFO CTRL - 6902684 to 6902819
  writeRegister(0x40, 0x03); // TX Buffer - 6902832 to 6902966
  writeRegister(0x41, 0x0E); // TX Buffer - 6902980 to 6903116
  writeRegister(0x44, 0x23); // TX Buffer - 6903128 to 6903264
  writeRegister(0x45, 0x11); // TX Buffer - 6903277 to 6903411
  writeRegister(0x46, 0x13); // TX Buffer - 6903425 to 6903560
  writeRegister(0x04, 0x07); // TX - 6903574 to 6903708
  writeRegister(0x00, 0xFF); // CS0 - 6910436 to 6910577
  writeRegister(0x01, 0xFF); // CS1 - 6910590 to 6910734
  writeRegister(0x16, 0xC0); // FIFO CTRL - 6910740 to 6910881
  writeRegister(0x40, 0x03); // TX Buffer - 6910889 to 6911022
  writeRegister(0x41, 0x0E); // TX Buffer - 6911036 to 6911171
  writeRegister(0x44, 0x23); // TX Buffer - 6911185 to 6911319
  writeRegister(0x45, 0x11); // TX Buffer - 6911333 to 6911469
  writeRegister(0x46, 0x13); // TX Buffer - 6911481 to 6911618
  writeRegister(0x04, 0x07); // TX - 6911630 to 6911766
  writeRegister(0x00, 0xFF); // CS0 - 6918411 to 6918555
  writeRegister(0x01, 0xFF); // CS1 - 6918561 to 6918701
  writeRegister(0x16, 0xC0); // FIFO CTRL - 6918715 to 6918850
  writeRegister(0x40, 0x03); // TX Buffer - 6918864 to 6918997
  writeRegister(0x41, 0x0E); // TX Buffer - 6919008 to 6919146
  writeRegister(0x44, 0x23); // TX Buffer - 6919156 to 6919294
  writeRegister(0x45, 0x11); // TX Buffer - 6919305 to 6919444
  writeRegister(0x46, 0x13); // TX Buffer - 6919453 to 6919593
  writeRegister(0x04, 0x07); // TX - 6919605 to 6919741
  writeRegister(0x00, 0xFF); // CS0 - 6926383 to 6926524
  writeRegister(0x01, 0xFF); // CS1 - 6926536 to 6926680
  writeRegister(0x16, 0xC0); // FIFO CTRL - 6926687 to 6926829
  writeRegister(0x40, 0x03); // TX Buffer - 6926835 to 6926970
  writeRegister(0x41, 0x0E); // TX Buffer - 6926983 to 6927117
  writeRegister(0x44, 0x23); // TX Buffer - 6927131 to 6927267
  writeRegister(0x45, 0x11); // TX Buffer - 6927279 to 6927414
  writeRegister(0x46, 0x13); // TX Buffer - 6927428 to 6927563
  writeRegister(0x04, 0x07); // TX - 6927577 to 6927711
  writeRegister(0x00, 0xFF); // CS0 - 6934443 to 6934580
  writeRegister(0x01, 0xFF); // CS1 - 6934593 to 6934734
  writeRegister(0x16, 0xC0); // FIFO CTRL - 6934743 to 6934881
  writeRegister(0x40, 0x03); // TX Buffer - 6934891 to 6935033
  writeRegister(0x41, 0x0E); // TX Buffer - 6935039 to 6935180
  writeRegister(0x44, 0x23); // TX Buffer - 6935187 to 6935329
  writeRegister(0x45, 0x11); // TX Buffer - 6935336 to 6935478
  writeRegister(0x46, 0x13); // TX Buffer - 6935484 to 6935627
  writeRegister(0x04, 0x07); // TX - 6935633 to 6935775
  writeRegister(0x00, 0xFF); // CS0 - 6942414 to 6942555
  writeRegister(0x01, 0xFF); // CS1 - 6942564 to 6942704
  writeRegister(0x16, 0xC0); // FIFO CTRL - 6942718 to 6942853
  writeRegister(0x40, 0x03); // TX Buffer - 6942866 to 6943000
  writeRegister(0x41, 0x0E); // TX Buffer - 6943014 to 6943150
  writeRegister(0x44, 0x23); // TX Buffer - 6943162 to 6943298
  writeRegister(0x45, 0x11); // TX Buffer - 6943311 to 6943445
  writeRegister(0x46, 0x13); // TX Buffer - 6943459 to 6943594
  writeRegister(0x04, 0x07); // TX - 6943608 to 6943742
  writeRegister(0x00, 0xFF); // CS0 - 6950389 to 6950525
  writeRegister(0x01, 0xFF); // CS1 - 6950539 to 6950679
  writeRegister(0x16, 0xC0); // FIFO CTRL - 6950689 to 6950828
  writeRegister(0x40, 0x03); // TX Buffer - 6950838 to 6950979
  writeRegister(0x41, 0x0E); // TX Buffer - 6950985 to 6951128
  writeRegister(0x44, 0x23); // TX Buffer - 6951134 to 6951276
  writeRegister(0x45, 0x11); // TX Buffer - 6951282 to 6951424
  writeRegister(0x46, 0x13); // TX Buffer - 6951431 to 6951573
  writeRegister(0x04, 0x07); // TX - 6951580 to 6951721
  writeRegister(0x00, 0xFF); // CS0 - 6958445 to 6958589
  writeRegister(0x01, 0xFF); // CS1 - 6958595 to 6958735
  writeRegister(0x16, 0xC0); // FIFO CTRL - 6958749 to 6958884
  writeRegister(0x40, 0x03); // TX Buffer - 6958898 to 6959031
  writeRegister(0x41, 0x0E); // TX Buffer - 6959042 to 6959180
  writeRegister(0x44, 0x23); // TX Buffer - 6959190 to 6959328
  writeRegister(0x45, 0x11); // TX Buffer - 6959339 to 6959478
  writeRegister(0x46, 0x13); // TX Buffer - 6959487 to 6959627
  writeRegister(0x04, 0x07); // TX - 6959636 to 6959775
  writeRegister(0x00, 0xFF); // CS0 - 6966417 to 6966558
  writeRegister(0x01, 0xFF); // CS1 - 6966570 to 6966708
  writeRegister(0x16, 0xC0); // FIFO CTRL - 6966721 to 6966855
  writeRegister(0x40, 0x03); // TX Buffer - 6966869 to 6967004
  writeRegister(0x41, 0x0E); // TX Buffer - 6967017 to 6967151
  writeRegister(0x44, 0x23); // TX Buffer - 6967165 to 6967301
  writeRegister(0x45, 0x11); // TX Buffer - 6967314 to 6967448
  writeRegister(0x46, 0x13); // TX Buffer - 6967462 to 6967597
  writeRegister(0x04, 0x07); // TX - 6967611 to 6967745
  writeRegister(0x00, 0xFF); // CS0 - 6974392 to 6974536
  writeRegister(0x01, 0xFF); // CS1 - 6974542 to 6974683
  writeRegister(0x16, 0xC0); // FIFO CTRL - 6974696 to 6974830
  writeRegister(0x40, 0x03); // TX Buffer - 6974844 to 6974979
  writeRegister(0x41, 0x0E); // TX Buffer - 6974988 to 6975126
  writeRegister(0x44, 0x23); // TX Buffer - 6975137 to 6975276
  writeRegister(0x45, 0x11); // TX Buffer - 6975285 to 6975423
  writeRegister(0x46, 0x13); // TX Buffer - 6975434 to 6975572
  writeRegister(0x04, 0x07); // TX - 6975582 to 6975720
  writeRegister(0x00, 0xFF); // CS0 - 6982448 to 6982589
  writeRegister(0x01, 0xFF); // CS1 - 6982598 to 6982738
  writeRegister(0x16, 0xC0); // FIFO CTRL - 6982752 to 6982887
  writeRegister(0x40, 0x03); // TX Buffer - 6982900 to 6983034
  writeRegister(0x41, 0x0E); // TX Buffer - 6983048 to 6983183
  writeRegister(0x44, 0x23); // TX Buffer - 6983196 to 6983332
  writeRegister(0x45, 0x11); // TX Buffer - 6983345 to 6983479
  writeRegister(0x46, 0x13); // TX Buffer - 6983493 to 6983628
  writeRegister(0x04, 0x07); // TX - 6983642 to 6983776
  writeRegister(0x00, 0xFF); // CS0 - 6990423 to 6990559
  writeRegister(0x01, 0xFF); // CS1 - 6990573 to 6990713
  writeRegister(0x16, 0xC0); // FIFO CTRL - 6990723 to 6990862
  writeRegister(0x40, 0x03); // TX Buffer - 6990872 to 6991007
  writeRegister(0x41, 0x0E); // TX Buffer - 6991019 to 6991154
  writeRegister(0x44, 0x23); // TX Buffer - 6991168 to 6991304
  writeRegister(0x45, 0x11); // TX Buffer - 6991316 to 6991452
  writeRegister(0x46, 0x13); // TX Buffer - 6991465 to 6991607
  writeRegister(0x04, 0x07); // TX - 6991614 to 6991749
  writeRegister(0x00, 0xFF); // CS0 - 6998395 to 6998534
  writeRegister(0x01, 0xFF); // CS1 - 6998545 to 6998686
  writeRegister(0x16, 0xC0); // FIFO CTRL - 6998698 to 6998833
  writeRegister(0x40, 0x03); // TX Buffer - 6998847 to 6998982
  writeRegister(0x41, 0x0E); // TX Buffer - 6998994 to 6999129
  writeRegister(0x44, 0x23); // TX Buffer - 6999143 to 6999279
  writeRegister(0x45, 0x11); // TX Buffer - 6999291 to 6999427
  writeRegister(0x46, 0x13); // TX Buffer - 6999440 to 6999576
  writeRegister(0x04, 0x07); // TX - 6999589 to 6999724
  writeRegister(0x00, 0xFF); // CS0 - 7006443 to 7006584
  writeRegister(0x01, 0xFF); // CS1 - 7006596 to 7006734
  writeRegister(0x16, 0xC0); // FIFO CTRL - 7006747 to 7006881
  writeRegister(0x40, 0x03); // TX Buffer - 7006895 to 7007030
  writeRegister(0x41, 0x0E); // TX Buffer - 7007043 to 7007177
  writeRegister(0x44, 0x23); // TX Buffer - 7007191 to 7007327
  writeRegister(0x45, 0x11); // TX Buffer - 7007339 to 7007474
  writeRegister(0x46, 0x13); // TX Buffer - 7007488 to 7007623
  writeRegister(0x04, 0x07); // TX - 7007637 to 7007771
  writeRegister(0x00, 0xFF); // CS0 - 7014418 to 7014554
  writeRegister(0x01, 0xFF); // CS1 - 7014568 to 7014709
  writeRegister(0x16, 0xC0); // FIFO CTRL - 7014718 to 7014856
  writeRegister(0x40, 0x03); // TX Buffer - 7014867 to 7015008
  writeRegister(0x41, 0x0E); // TX Buffer - 7015014 to 7015152
  writeRegister(0x44, 0x23); // TX Buffer - 7015163 to 7015305
  writeRegister(0x45, 0x11); // TX Buffer - 7015311 to 7015453
  writeRegister(0x46, 0x13); // TX Buffer - 7015459 to 7015598
  writeRegister(0x04, 0x07); // TX - 7015608 to 7015750
  writeRegister(0x00, 0xFF); // CS0 - 7022389 to 7022529
  writeRegister(0x01, 0xFF); // CS1 - 7022543 to 7022679
  writeRegister(0x16, 0xC0); // FIFO CTRL - 7022693 to 7022828
  writeRegister(0x40, 0x03); // TX Buffer - 7022842 to 7022975
  writeRegister(0x41, 0x0E); // TX Buffer - 7022989 to 7023124
  writeRegister(0x44, 0x23); // TX Buffer - 7023138 to 7023272
  writeRegister(0x45, 0x11); // TX Buffer - 7023286 to 7023422
  writeRegister(0x46, 0x13); // TX Buffer - 7023434 to 7023571
  writeRegister(0x04, 0x07); // TX - 7023583 to 7023719
  writeRegister(0x00, 0xFF); // CS0 - 7030446 to 7030585
  writeRegister(0x01, 0xFF); // CS1 - 7030599 to 7030743
  writeRegister(0x16, 0xC0); // FIFO CTRL - 7030749 to 7030888
  writeRegister(0x40, 0x03); // TX Buffer - 7030898 to 7031033
  writeRegister(0x41, 0x0E); // TX Buffer - 7031045 to 7031180
  writeRegister(0x44, 0x23); // TX Buffer - 7031194 to 7031330
  writeRegister(0x45, 0x11); // TX Buffer - 7031342 to 7031478
  writeRegister(0x46, 0x13); // TX Buffer - 7031491 to 7031627
  writeRegister(0x04, 0x07); // TX - 7031640 to 7031775
  writeRegister(0x00, 0xFF); // CS0 - 7038421 to 7038564
  writeRegister(0x01, 0xFF); // CS1 - 7038571 to 7038712
  writeRegister(0x16, 0xC0); // FIFO CTRL - 7038724 to 7038859
  writeRegister(0x40, 0x03); // TX Buffer - 7038873 to 7039008
  writeRegister(0x41, 0x0E); // TX Buffer - 7039017 to 7039155
  writeRegister(0x44, 0x23); // TX Buffer - 7039165 to 7039305
  writeRegister(0x45, 0x11); // TX Buffer - 7039314 to 7039453
  writeRegister(0x46, 0x13); // TX Buffer - 7039462 to 7039602
  writeRegister(0x04, 0x07); // TX - 7039615 to 7039750
  writeRegister(0x00, 0xFF); // CS0 - 7046392 to 7046533
  writeRegister(0x01, 0xFF); // CS1 - 7046546 to 7046690
  writeRegister(0x16, 0xC0); // FIFO CTRL - 7046696 to 7046834
  writeRegister(0x40, 0x03); // TX Buffer - 7046844 to 7046978
  writeRegister(0x41, 0x0E); // TX Buffer - 7046992 to 7047127
  writeRegister(0x44, 0x23); // TX Buffer - 7047140 to 7047275
  writeRegister(0x45, 0x11); // TX Buffer - 7047289 to 7047425
  writeRegister(0x46, 0x13); // TX Buffer - 7047437 to 7047572
  writeRegister(0x04, 0x07); // TX - 7047586 to 7047720
  writeRegister(0x00, 0xFF); // CS0 - 7054452 to 7054588
  writeRegister(0x01, 0xFF); // CS1 - 7054602 to 7054743
  writeRegister(0x16, 0xC0); // FIFO CTRL - 7054752 to 7054890
  writeRegister(0x40, 0x03); // TX Buffer - 7054901 to 7055042
  writeRegister(0x41, 0x0E); // TX Buffer - 7055048 to 7055186
  writeRegister(0x44, 0x23); // TX Buffer - 7055197 to 7055339
  writeRegister(0x45, 0x11); // TX Buffer - 7055345 to 7055487
  writeRegister(0x46, 0x13); // TX Buffer - 7055494 to 7055632
  writeRegister(0x04, 0x07); // TX - 7055642 to 7055784
  writeRegister(0x00, 0xFF); // CS0 - 7062423 to 7062563
  writeRegister(0x01, 0xFF); // CS1 - 7062573 to 7062713
  writeRegister(0x16, 0xC0); // FIFO CTRL - 7062727 to 7062862
  writeRegister(0x40, 0x03); // TX Buffer - 7062876 to 7063009
  writeRegister(0x41, 0x0E); // TX Buffer - 7063023 to 7063158
  writeRegister(0x44, 0x23); // TX Buffer - 7063172 to 7063306
  writeRegister(0x45, 0x11); // TX Buffer - 7063320 to 7063456
  writeRegister(0x46, 0x13); // TX Buffer - 7063468 to 7063605
  writeRegister(0x04, 0x07); // TX - 7063617 to 7063753
  writeRegister(0x00, 0xFF); // CS0 - 7070398 to 7070536
  writeRegister(0x01, 0xFF); // CS1 - 7070548 to 7070688
  writeRegister(0x16, 0xC0); // FIFO CTRL - 7070699 to 7070837
  writeRegister(0x40, 0x03); // TX Buffer - 7070847 to 7070988
  writeRegister(0x41, 0x0E); // TX Buffer - 7070995 to 7071133
  writeRegister(0x44, 0x23); // TX Buffer - 7071143 to 7071285
  writeRegister(0x45, 0x11); // TX Buffer - 7071292 to 7071434
  writeRegister(0x46, 0x13); // TX Buffer - 7071440 to 7071580
  writeRegister(0x04, 0x07); // TX - 7071589 to 7071731
  writeRegister(0x00, 0xFF); // CS0 - 7078455 to 7078598
  writeRegister(0x01, 0xFF); // CS1 - 7078605 to 7078746
  writeRegister(0x16, 0xC0); // FIFO CTRL - 7078758 to 7078893
  writeRegister(0x40, 0x03); // TX Buffer - 7078907 to 7079042
  writeRegister(0x41, 0x0E); // TX Buffer - 7079051 to 7079189
  writeRegister(0x44, 0x23); // TX Buffer - 7079199 to 7079339
  writeRegister(0x45, 0x11); // TX Buffer - 7079348 to 7079487
  writeRegister(0x46, 0x13); // TX Buffer - 7079496 to 7079636
  writeRegister(0x04, 0x07); // TX - 7079649 to 7079784
  writeRegister(0x00, 0xFF); // CS0 - 7086426 to 7086567
  writeRegister(0x01, 0xFF); // CS1 - 7086580 to 7086724
  writeRegister(0x16, 0xC0); // FIFO CTRL - 7086730 to 7086871
  writeRegister(0x40, 0x03); // TX Buffer - 7086878 to 7087012
  writeRegister(0x41, 0x0E); // TX Buffer - 7087026 to 7087161
  writeRegister(0x44, 0x23); // TX Buffer - 7087174 to 7087309
  writeRegister(0x45, 0x11); // TX Buffer - 7087323 to 7087459
  writeRegister(0x46, 0x13); // TX Buffer - 7087471 to 7087606
  writeRegister(0x04, 0x07); // TX - 7087620 to 7087754
  writeRegister(0x00, 0xFF); // CS0 - 7094401 to 7094545
  writeRegister(0x01, 0xFF); // CS1 - 7094551 to 7094691
  writeRegister(0x16, 0xC0); // FIFO CTRL - 7094705 to 7094840
  writeRegister(0x40, 0x03); // TX Buffer - 7094853 to 7094987
  writeRegister(0x41, 0x0E); // TX Buffer - 7094997 to 7095136
  writeRegister(0x44, 0x23); // TX Buffer - 7095146 to 7095284
  writeRegister(0x45, 0x11); // TX Buffer - 7095294 to 7095434
  writeRegister(0x46, 0x13); // TX Buffer - 7095443 to 7095581
  writeRegister(0x04, 0x07); // TX - 7095595 to 7095729
  writeRegister(0x00, 0xFF); // CS0 - 7102458 to 7102597
  writeRegister(0x01, 0xFF); // CS1 - 7102607 to 7102749
  writeRegister(0x16, 0xC0); // FIFO CTRL - 7102761 to 7102896
  writeRegister(0x40, 0x03); // TX Buffer - 7102910 to 7103043
  writeRegister(0x41, 0x0E); // TX Buffer - 7103057 to 7103192
  writeRegister(0x44, 0x23); // TX Buffer - 7103206 to 7103340
  writeRegister(0x45, 0x11); // TX Buffer - 7103354 to 7103490
  writeRegister(0x46, 0x13); // TX Buffer - 7103503 to 7103639
  writeRegister(0x04, 0x07); // TX - 7103651 to 7103787
  writeRegister(0x00, 0xFF); // CS0 - 7110432 to 7110570
  writeRegister(0x01, 0xFF); // CS1 - 7110582 to 7110722
  writeRegister(0x16, 0xC0); // FIFO CTRL - 7110733 to 7110871
  writeRegister(0x40, 0x03); // TX Buffer - 7110881 to 7111022
  writeRegister(0x41, 0x0E); // TX Buffer - 7111029 to 7111171
  writeRegister(0x44, 0x23); // TX Buffer - 7111177 to 7111319
  writeRegister(0x45, 0x11); // TX Buffer - 7111326 to 7111468
  writeRegister(0x46, 0x13); // TX Buffer - 7111474 to 7111617
  writeRegister(0x04, 0x07); // TX - 7111623 to 7111765
  writeRegister(0x00, 0xFF); // CS0 - 7118404 to 7118545
  writeRegister(0x01, 0xFF); // CS1 - 7118554 to 7118695
  writeRegister(0x16, 0xC0); // FIFO CTRL - 7118708 to 7118842
  writeRegister(0x40, 0x03); // TX Buffer - 7118856 to 7118991
  writeRegister(0x41, 0x0E); // TX Buffer - 7119004 to 7119138
  writeRegister(0x44, 0x23); // TX Buffer - 7119152 to 7119288
  writeRegister(0x45, 0x11); // TX Buffer - 7119301 to 7119435
  writeRegister(0x46, 0x13); // TX Buffer - 7119449 to 7119584
  writeRegister(0x04, 0x07); // TX - 7119598 to 7119732
  writeRegister(0x00, 0xFF); // CS0 - 7126460 to 7126601
  writeRegister(0x01, 0xFF); // CS1 - 7126614 to 7126750
  writeRegister(0x16, 0xC0); // FIFO CTRL - 7126764 to 7126899
  writeRegister(0x40, 0x03); // TX Buffer - 7126912 to 7127046
  writeRegister(0x41, 0x0E); // TX Buffer - 7127060 to 7127195
  writeRegister(0x44, 0x23); // TX Buffer - 7127208 to 7127343
  writeRegister(0x45, 0x11); // TX Buffer - 7127357 to 7127493
  writeRegister(0x46, 0x13); // TX Buffer - 7127505 to 7127642
  writeRegister(0x04, 0x07); // TX - 7127654 to 7127788
  writeRegister(0x00, 0xFF); // CS0 - 7134435 to 7134579
  writeRegister(0x01, 0xFF); // CS1 - 7134585 to 7134725
  writeRegister(0x16, 0xC0); // FIFO CTRL - 7134739 to 7134874
  writeRegister(0x40, 0x03); // TX Buffer - 7134887 to 7135021
  writeRegister(0x41, 0x0E); // TX Buffer - 7135032 to 7135170
  writeRegister(0x44, 0x23); // TX Buffer - 7135180 to 7135318
  writeRegister(0x45, 0x11); // TX Buffer - 7135328 to 7135468
  writeRegister(0x46, 0x13); // TX Buffer - 7135477 to 7135615
  writeRegister(0x04, 0x07); // TX - 7135626 to 7135763
  writeRegister(0x00, 0xFF); // CS0 - 7142407 to 7142546
  writeRegister(0x01, 0xFF); // CS1 - 7142560 to 7142698
  writeRegister(0x16, 0xC0); // FIFO CTRL - 7142711 to 7142845
  writeRegister(0x40, 0x03); // TX Buffer - 7142859 to 7142994
  writeRegister(0x41, 0x0E); // TX Buffer - 7143006 to 7143141
  writeRegister(0x44, 0x23); // TX Buffer - 7143155 to 7143291
  writeRegister(0x45, 0x11); // TX Buffer - 7143303 to 7143438
  writeRegister(0x46, 0x13); // TX Buffer - 7143452 to 7143588
  writeRegister(0x04, 0x07); // TX - 7143601 to 7143736
  writeRegister(0x00, 0xFF); // CS0 - 7150467 to 7150604
  writeRegister(0x01, 0xFF); // CS1 - 7150616 to 7150758
  writeRegister(0x16, 0xC0); // FIFO CTRL - 7150767 to 7150905
  writeRegister(0x40, 0x03); // TX Buffer - 7150915 to 7151050
  writeRegister(0x41, 0x0E); // TX Buffer - 7151063 to 7151197
  writeRegister(0x44, 0x23); // TX Buffer - 7151211 to 7151347
  writeRegister(0x45, 0x11); // TX Buffer - 7151360 to 7151494
  writeRegister(0x46, 0x13); // TX Buffer - 7151508 to 7151651
  writeRegister(0x04, 0x07); // TX - 7151657 to 7151791
  writeRegister(0x00, 0xFF); // CS0 - 7158438 to 7158579
  writeRegister(0x01, 0xFF); // CS1 - 7158588 to 7158728
  writeRegister(0x16, 0xC0); // FIFO CTRL - 7158742 to 7158878
  writeRegister(0x40, 0x03); // TX Buffer - 7158890 to 7159025
  writeRegister(0x41, 0x0E); // TX Buffer - 7159038 to 7159172
  writeRegister(0x44, 0x23); // TX Buffer - 7159186 to 7159322
  writeRegister(0x45, 0x11); // TX Buffer - 7159335 to 7159469
  writeRegister(0x46, 0x13); // TX Buffer - 7159483 to 7159618
  writeRegister(0x04, 0x07); // TX - 7159632 to 7159766
  writeRegister(0x00, 0xFF); // CS0 - 7166413 to 7166549
  writeRegister(0x01, 0xFF); // CS1 - 7166563 to 7166704
  writeRegister(0x16, 0xC0); // FIFO CTRL - 7166713 to 7166851
  writeRegister(0x40, 0x03); // TX Buffer - 7166862 to 7166997
  writeRegister(0x41, 0x0E); // TX Buffer - 7167009 to 7167144
  writeRegister(0x44, 0x23); // TX Buffer - 7167158 to 7167292
  writeRegister(0x45, 0x11); // TX Buffer - 7167306 to 7167442
  writeRegister(0x46, 0x13); // TX Buffer - 7167455 to 7167597
  writeRegister(0x04, 0x07); // TX - 7167604 to 7167739
  writeRegister(0x00, 0xFF); // CS0 - 7174469 to 7174605
  writeRegister(0x01, 0xFF); // CS1 - 7174619 to 7174759
  writeRegister(0x16, 0xC0); // FIFO CTRL - 7174773 to 7174908
  writeRegister(0x40, 0x03); // TX Buffer - 7174921 to 7175055
  writeRegister(0x41, 0x0E); // TX Buffer - 7175066 to 7175204
  writeRegister(0x44, 0x23); // TX Buffer - 7175214 to 7175352
  writeRegister(0x45, 0x11); // TX Buffer - 7175362 to 7175502
  writeRegister(0x46, 0x13); // TX Buffer - 7175511 to 7175649
  writeRegister(0x04, 0x07); // TX - 7175660 to 7175797
  writeRegister(0x00, 0xFF); // CS0 - 7182441 to 7182580
  writeRegister(0x01, 0xFF); // CS1 - 7182594 to 7182732
  writeRegister(0x16, 0xC0); // FIFO CTRL - 7182745 to 7182879
  writeRegister(0x40, 0x03); // TX Buffer - 7182893 to 7183028
  writeRegister(0x41, 0x0E); // TX Buffer - 7183040 to 7183175
  writeRegister(0x44, 0x23); // TX Buffer - 7183189 to 7183325
  writeRegister(0x45, 0x11); // TX Buffer - 7183337 to 7183472
  writeRegister(0x46, 0x13); // TX Buffer - 7183486 to 7183621
  writeRegister(0x04, 0x07); // TX - 7183635 to 7183770
  writeRegister(0x00, 0xFF); // CS0 - 7190416 to 7190553
  writeRegister(0x01, 0xFF); // CS1 - 7190566 to 7190707
  writeRegister(0x16, 0xC0); // FIFO CTRL - 7190720 to 7190854
  writeRegister(0x40, 0x03); // TX Buffer - 7190868 to 7191003
  writeRegister(0x41, 0x0E); // TX Buffer - 7191012 to 7191150
  writeRegister(0x44, 0x23); // TX Buffer - 7191160 to 7191300
  writeRegister(0x45, 0x11); // TX Buffer - 7191309 to 7191447
  writeRegister(0x46, 0x13); // TX Buffer - 7191457 to 7191597
  writeRegister(0x04, 0x07); // TX - 7191606 to 7191745
  writeRegister(0x00, 0xFF); // CS0 - 7198387 to 7198528
  writeRegister(0x01, 0xFF); // CS1 - 7198541 to 7198677
  writeRegister(0x16, 0xC0); // FIFO CTRL - 7198691 to 7198826
  writeRegister(0x40, 0x03); // TX Buffer - 7198840 to 7198973
  writeRegister(0x41, 0x0E); // TX Buffer - 7198987 to 7199122
  writeRegister(0x44, 0x23); // TX Buffer - 7199135 to 7199270
  writeRegister(0x45, 0x11); // TX Buffer - 7199284 to 7199420
  writeRegister(0x46, 0x13); // TX Buffer - 7199432 to 7199569
  writeRegister(0x04, 0x07); // TX - 7199581 to 7199717
  writeRegister(0x00, 0xFF); // CS0 - 7206444 to 7206583
  writeRegister(0x01, 0xFF); // CS1 - 7206597 to 7206741
  writeRegister(0x16, 0xC0); // FIFO CTRL - 7206747 to 7206885
  writeRegister(0x40, 0x03); // TX Buffer - 7206896 to 7207031
  writeRegister(0x41, 0x0E); // TX Buffer - 7207043 to 7207178
  writeRegister(0x44, 0x23); // TX Buffer - 7207192 to 7207326
  writeRegister(0x45, 0x11); // TX Buffer - 7207340 to 7207476
  writeRegister(0x46, 0x13); // TX Buffer - 7207489 to 7207631
  writeRegister(0x04, 0x07); // TX - 7207638 to 7207773
  writeRegister(0x00, 0xFF); // CS0 - 7214419 to 7214558
  writeRegister(0x01, 0xFF); // CS1 - 7214569 to 7214710
  writeRegister(0x16, 0xC0); // FIFO CTRL - 7214722 to 7214857
  writeRegister(0x40, 0x03); // TX Buffer - 7214871 to 7215006
  writeRegister(0x41, 0x0E); // TX Buffer - 7215018 to 7215153
  writeRegister(0x44, 0x23); // TX Buffer - 7215167 to 7215301
  writeRegister(0x45, 0x11); // TX Buffer - 7215315 to 7215451
  writeRegister(0x46, 0x13); // TX Buffer - 7215464 to 7215600
  writeRegister(0x04, 0x07); // TX - 7215613 to 7215748
  writeRegister(0x00, 0xFF); // CS0 - 7222390 to 7222531
  writeRegister(0x01, 0xFF); // CS1 - 7222543 to 7222688
  writeRegister(0x16, 0xC0); // FIFO CTRL - 7222694 to 7222832
  writeRegister(0x40, 0x03); // TX Buffer - 7222842 to 7222976
  writeRegister(0x41, 0x0E); // TX Buffer - 7222990 to 7223126
  writeRegister(0x44, 0x23); // TX Buffer - 7223138 to 7223274
  writeRegister(0x45, 0x11); // TX Buffer - 7223287 to 7223421
  writeRegister(0x46, 0x13); // TX Buffer - 7223435 to 7223578
  writeRegister(0x04, 0x07); // TX - 7223584 to 7223718
  writeRegister(0x00, 0xFF); // CS0 - 7230450 to 7230587
  writeRegister(0x01, 0xFF); // CS1 - 7230600 to 7230741
  writeRegister(0x16, 0xC0); // FIFO CTRL - 7230750 to 7230888
  writeRegister(0x40, 0x03); // TX Buffer - 7230899 to 7231040
  writeRegister(0x41, 0x0E); // TX Buffer - 7231046 to 7231184
  writeRegister(0x44, 0x23); // TX Buffer - 7231195 to 7231337
  writeRegister(0x45, 0x11); // TX Buffer - 7231343 to 7231485
  writeRegister(0x46, 0x13); // TX Buffer - 7231491 to 7231631
  writeRegister(0x04, 0x07); // TX - 7231640 to 7231782
  writeRegister(0x00, 0xFF); // CS0 - 7238421 to 7238562
  writeRegister(0x01, 0xFF); // CS1 - 7238575 to 7238711
  writeRegister(0x16, 0xC0); // FIFO CTRL - 7238725 to 7238860
  writeRegister(0x40, 0x03); // TX Buffer - 7238874 to 7239007
  writeRegister(0x41, 0x0E); // TX Buffer - 7239021 to 7239156
  writeRegister(0x44, 0x23); // TX Buffer - 7239169 to 7239304
  writeRegister(0x45, 0x11); // TX Buffer - 7239318 to 7239454
  writeRegister(0x46, 0x13); // TX Buffer - 7239466 to 7239603
  writeRegister(0x04, 0x07); // TX - 7239615 to 7239751
  writeRegister(0x00, 0xFF); // CS0 - 7246396 to 7246534
  writeRegister(0x01, 0xFF); // CS1 - 7246546 to 7246686
  writeRegister(0x16, 0xC0); // FIFO CTRL - 7246697 to 7246835
  writeRegister(0x40, 0x03); // TX Buffer - 7246845 to 7246986
  writeRegister(0x41, 0x0E); // TX Buffer - 7246993 to 7247131
  writeRegister(0x44, 0x23); // TX Buffer - 7247141 to 7247283
  writeRegister(0x45, 0x11); // TX Buffer - 7247289 to 7247432
  writeRegister(0x46, 0x13); // TX Buffer - 7247438 to 7247578
  writeRegister(0x04, 0x07); // TX - 7247587 to 7247729
  writeRegister(0x00, 0xFF); // CS0 - 7254453 to 7254596
  writeRegister(0x01, 0xFF); // CS1 - 7254603 to 7254744
  writeRegister(0x16, 0xC0); // FIFO CTRL - 7254756 to 7254891
  writeRegister(0x40, 0x03); // TX Buffer - 7254905 to 7255040
  writeRegister(0x41, 0x0E); // TX Buffer - 7255049 to 7255187
  writeRegister(0x44, 0x23); // TX Buffer - 7255197 to 7255335
  writeRegister(0x45, 0x11); // TX Buffer - 7255346 to 7255485
  writeRegister(0x46, 0x13); // TX Buffer - 7255494 to 7255634
  writeRegister(0x04, 0x07); // TX - 7255647 to 7255782
  writeRegister(0x00, 0xFF); // CS0 - 7262424 to 7262565
  writeRegister(0x01, 0xFF); // CS1 - 7262578 to 7262722
  writeRegister(0x16, 0xC0); // FIFO CTRL - 7262728 to 7262866
  writeRegister(0x40, 0x03); // TX Buffer - 7262876 to 7263010
  writeRegister(0x41, 0x0E); // TX Buffer - 7263024 to 7263160
  writeRegister(0x44, 0x23); // TX Buffer - 7263172 to 7263308
  writeRegister(0x45, 0x11); // TX Buffer - 7263321 to 7263455
  writeRegister(0x46, 0x13); // TX Buffer - 7263469 to 7263604
  writeRegister(0x04, 0x07); // TX - 7263618 to 7263752
  writeRegister(0x00, 0xFF); // CS0 - 7270399 to 7270543
  writeRegister(0x01, 0xFF); // CS1 - 7270549 to 7270689
  writeRegister(0x16, 0xC0); // FIFO CTRL - 7270703 to 7270838
  writeRegister(0x40, 0x03); // TX Buffer - 7270851 to 7270985
  writeRegister(0x41, 0x0E); // TX Buffer - 7270995 to 7271135
  writeRegister(0x44, 0x23); // TX Buffer - 7271144 to 7271283
  writeRegister(0x45, 0x11); // TX Buffer - 7271292 to 7271430
  writeRegister(0x46, 0x13); // TX Buffer - 7271441 to 7271579
  writeRegister(0x04, 0x07); // TX - 7271593 to 7271727
  writeRegister(0x00, 0xFF); // CS0 - 7278455 to 7278596
  writeRegister(0x01, 0xFF); // CS1 - 7278605 to 7278745
  writeRegister(0x16, 0xC0); // FIFO CTRL - 7278759 to 7278894
  writeRegister(0x40, 0x03); // TX Buffer - 7278908 to 7279041
  writeRegister(0x41, 0x0E); // TX Buffer - 7279055 to 7279190
  writeRegister(0x44, 0x23); // TX Buffer - 7279204 to 7279338
  writeRegister(0x45, 0x11); // TX Buffer - 7279352 to 7279488
  writeRegister(0x46, 0x13); // TX Buffer - 7279500 to 7279637
  writeRegister(0x04, 0x07); // TX - 7279649 to 7279785
  writeRegister(0x00, 0xFF); // CS0 - 7286430 to 7286568
  writeRegister(0x01, 0xFF); // CS1 - 7286580 to 7286720
  writeRegister(0x16, 0xC0); // FIFO CTRL - 7286731 to 7286869
  writeRegister(0x40, 0x03); // TX Buffer - 7286879 to 7287020
  writeRegister(0x41, 0x0E); // TX Buffer - 7287027 to 7287165
  writeRegister(0x44, 0x23); // TX Buffer - 7287175 to 7287317
  writeRegister(0x45, 0x11); // TX Buffer - 7287324 to 7287466
  writeRegister(0x46, 0x13); // TX Buffer - 7287472 to 7287612
  writeRegister(0x04, 0x07); // TX - 7287621 to 7287763
  writeRegister(0x00, 0xFF); // CS0 - 7294402 to 7294543
  writeRegister(0x01, 0xFF); // CS1 - 7294552 to 7294693
  writeRegister(0x16, 0xC0); // FIFO CTRL - 7294706 to 7294840
  writeRegister(0x40, 0x03); // TX Buffer - 7294854 to 7294989
  writeRegister(0x41, 0x0E); // TX Buffer - 7295002 to 7295136
  writeRegister(0x44, 0x23); // TX Buffer - 7295150 to 7295286
  writeRegister(0x45, 0x11); // TX Buffer - 7295298 to 7295433
  writeRegister(0x46, 0x13); // TX Buffer - 7295447 to 7295582
  writeRegister(0x04, 0x07); // TX - 7295596 to 7295730
  writeRegister(0x00, 0xFF); // CS0 - 7302458 to 7302599
  writeRegister(0x01, 0xFF); // CS1 - 7302612 to 7302756
  writeRegister(0x16, 0xC0); // FIFO CTRL - 7302762 to 7302903
  writeRegister(0x40, 0x03); // TX Buffer - 7302910 to 7303044
  writeRegister(0x41, 0x0E); // TX Buffer - 7303058 to 7303193
  writeRegister(0x44, 0x23); // TX Buffer - 7303206 to 7303342
  writeRegister(0x45, 0x11); // TX Buffer - 7303355 to 7303489
  writeRegister(0x46, 0x13); // TX Buffer - 7303503 to 7303638
  writeRegister(0x04, 0x07); // TX - 7303652 to 7303786
  writeRegister(0x00, 0xFF); // CS0 - 7310433 to 7310577
  writeRegister(0x01, 0xFF); // CS1 - 7310583 to 7310723
  writeRegister(0x16, 0xC0); // FIFO CTRL - 7310737 to 7310872
  writeRegister(0x40, 0x03); // TX Buffer - 7310885 to 7311019
  writeRegister(0x41, 0x0E); // TX Buffer - 7311029 to 7311169
  writeRegister(0x44, 0x23); // TX Buffer - 7311178 to 7311317
  writeRegister(0x45, 0x11); // TX Buffer - 7311326 to 7311464
  writeRegister(0x46, 0x13); // TX Buffer - 7311475 to 7311613
  writeRegister(0x04, 0x07); // TX - 7311627 to 7311761
  writeRegister(0x00, 0xFF); // CS0 - 7318405 to 7318544
  writeRegister(0x01, 0xFF); // CS1 - 7318558 to 7318702
  writeRegister(0x16, 0xC0); // FIFO CTRL - 7318708 to 7318851
  writeRegister(0x40, 0x03); // TX Buffer - 7318857 to 7318992
  writeRegister(0x41, 0x0E); // TX Buffer - 7319004 to 7319139
  writeRegister(0x44, 0x23); // TX Buffer - 7319153 to 7319289
  writeRegister(0x45, 0x11); // TX Buffer - 7319301 to 7319437
  writeRegister(0x46, 0x13); // TX Buffer - 7319450 to 7319586
  writeRegister(0x04, 0x07); // TX - 7319599 to 7319734
  writeRegister(0x00, 0xFF); // CS0 - 7326464 to 7326602
  writeRegister(0x01, 0xFF); // CS1 - 7326614 to 7326754
  writeRegister(0x16, 0xC0); // FIFO CTRL - 7326765 to 7326903
  writeRegister(0x40, 0x03); // TX Buffer - 7326913 to 7327054
  writeRegister(0x41, 0x0E); // TX Buffer - 7327061 to 7327203
  writeRegister(0x44, 0x23); // TX Buffer - 7327209 to 7327351
  writeRegister(0x45, 0x11); // TX Buffer - 7327358 to 7327500
  writeRegister(0x46, 0x13); // TX Buffer - 7327506 to 7327649
  writeRegister(0x04, 0x07); // TX - 7327655 to 7327797
  writeRegister(0x00, 0xFF); // CS0 - 7334436 to 7334577
  writeRegister(0x01, 0xFF); // CS1 - 7334586 to 7334727
  writeRegister(0x16, 0xC0); // FIFO CTRL - 7334740 to 7334874
  writeRegister(0x40, 0x03); // TX Buffer - 7334888 to 7335023
  writeRegister(0x41, 0x0E); // TX Buffer - 7335036 to 7335170
  writeRegister(0x44, 0x23); // TX Buffer - 7335184 to 7335320
  writeRegister(0x45, 0x11); // TX Buffer - 7335333 to 7335467
  writeRegister(0x46, 0x13); // TX Buffer - 7335481 to 7335616
  writeRegister(0x04, 0x07); // TX - 7335630 to 7335764
  writeRegister(0x00, 0xFF); // CS0 - 7342411 to 7342547
  writeRegister(0x01, 0xFF); // CS1 - 7342561 to 7342702
  writeRegister(0x16, 0xC0); // FIFO CTRL - 7342711 to 7342849
  writeRegister(0x40, 0x03); // TX Buffer - 7342860 to 7343001
  writeRegister(0x41, 0x0E); // TX Buffer - 7343007 to 7343148
  writeRegister(0x44, 0x23); // TX Buffer - 7343156 to 7343298
  writeRegister(0x45, 0x11); // TX Buffer - 7343304 to 7343446
  writeRegister(0x46, 0x13); // TX Buffer - 7343453 to 7343595
  writeRegister(0x04, 0x07); // TX - 7343601 to 7343743
  writeRegister(0x00, 0xFF); // CS0 - 7350467 to 7350611
  writeRegister(0x01, 0xFF); // CS1 - 7350617 to 7350757
  writeRegister(0x16, 0xC0); // FIFO CTRL - 7350771 to 7350906
  writeRegister(0x40, 0x03); // TX Buffer - 7350919 to 7351053
  writeRegister(0x41, 0x0E); // TX Buffer - 7351063 to 7351202
  writeRegister(0x44, 0x23); // TX Buffer - 7351212 to 7351351
  writeRegister(0x45, 0x11); // TX Buffer - 7351360 to 7351498
  writeRegister(0x46, 0x13); // TX Buffer - 7351509 to 7351647
  writeRegister(0x04, 0x07); // TX - 7351658 to 7351795
  writeRegister(0x00, 0xFF); // CS0 - 7358431 to 7358570
  writeRegister(0x01, 0xFF); // CS1 - 7358584 to 7358722
  writeRegister(0x16, 0xC0); // FIFO CTRL - 7358734 to 7358869
  writeRegister(0x40, 0x03); // TX Buffer - 7358883 to 7359018
  writeRegister(0x41, 0x0E); // TX Buffer - 7359030 to 7359165
  writeRegister(0x44, 0x23); // TX Buffer - 7359179 to 7359315
  writeRegister(0x45, 0x11); // TX Buffer - 7359327 to 7359463
  writeRegister(0x46, 0x13); // TX Buffer - 7359476 to 7359612
  writeRegister(0x04, 0x07); // TX - 7359625 to 7359760
  writeRegister(0x00, 0xFF); // CS0 - 7366406 to 7366543
  writeRegister(0x01, 0xFF); // CS1 - 7366556 to 7366697
  writeRegister(0x16, 0xC0); // FIFO CTRL - 7366709 to 7366844
  writeRegister(0x40, 0x03); // TX Buffer - 7366858 to 7366993
  writeRegister(0x41, 0x0E); // TX Buffer - 7367002 to 7367140
  writeRegister(0x44, 0x23); // TX Buffer - 7367150 to 7367288
  writeRegister(0x45, 0x11); // TX Buffer - 7367299 to 7367438
  writeRegister(0x46, 0x13); // TX Buffer - 7367447 to 7367587
  writeRegister(0x04, 0x07); // TX - 7367596 to 7367735
  writeRegister(0x00, 0xFF); // CS0 - 7374462 to 7374603
  writeRegister(0x01, 0xFF); // CS1 - 7374612 to 7374753
  writeRegister(0x16, 0xC0); // FIFO CTRL - 7374766 to 7374900
  writeRegister(0x40, 0x03); // TX Buffer - 7374914 to 7375049
  writeRegister(0x41, 0x0E); // TX Buffer - 7375062 to 7375196
  writeRegister(0x44, 0x23); // TX Buffer - 7375210 to 7375346
  writeRegister(0x45, 0x11); // TX Buffer - 7375358 to 7375493
  writeRegister(0x46, 0x13); // TX Buffer - 7375507 to 7375642
  writeRegister(0x04, 0x07); // TX - 7375656 to 7375790
  writeRegister(0x00, 0xFF); // CS0 - 7382433 to 7382573
  writeRegister(0x01, 0xFF); // CS1 - 7382587 to 7382731
  writeRegister(0x16, 0xC0); // FIFO CTRL - 7382737 to 7382875
  writeRegister(0x40, 0x03); // TX Buffer - 7382886 to 7383019
  writeRegister(0x41, 0x0E); // TX Buffer - 7383033 to 7383168
  writeRegister(0x44, 0x23); // TX Buffer - 7383182 to 7383316
  writeRegister(0x45, 0x11); // TX Buffer - 7383330 to 7383466
  writeRegister(0x46, 0x13); // TX Buffer - 7383478 to 7383621
  writeRegister(0x04, 0x07); // TX - 7383627 to 7383763
  writeRegister(0x00, 0xFF); // CS0 - 7390408 to 7390549
  writeRegister(0x01, 0xFF); // CS1 - 7390558 to 7390698
  writeRegister(0x16, 0xC0); // FIFO CTRL - 7390712 to 7390847
  writeRegister(0x40, 0x03); // TX Buffer - 7390861 to 7390994
  writeRegister(0x41, 0x0E); // TX Buffer - 7391008 to 7391143
  writeRegister(0x44, 0x23); // TX Buffer - 7391157 to 7391291
  writeRegister(0x45, 0x11); // TX Buffer - 7391305 to 7391441
  writeRegister(0x46, 0x13); // TX Buffer - 7391453 to 7391590
  writeRegister(0x04, 0x07); // TX - 7391602 to 7391738
  writeRegister(0x00, 0xFF); // CS0 - 7398465 to 7398604
  writeRegister(0x01, 0xFF); // CS1 - 7398618 to 7398756
  writeRegister(0x16, 0xC0); // FIFO CTRL - 7398768 to 7398903
  writeRegister(0x40, 0x03); // TX Buffer - 7398917 to 7399052
  writeRegister(0x41, 0x0E); // TX Buffer - 7399064 to 7399199
  writeRegister(0x44, 0x23); // TX Buffer - 7399213 to 7399349
  writeRegister(0x45, 0x11); // TX Buffer - 7399361 to 7399497
  writeRegister(0x46, 0x13); // TX Buffer - 7399510 to 7399646
  writeRegister(0x04, 0x07); // TX - 7399659 to 7399794
  writeRegister(0x00, 0xFF); // CS0 - 7406440 to 7406577
  writeRegister(0x01, 0xFF); // CS1 - 7406590 to 7406731
  writeRegister(0x16, 0xC0); // FIFO CTRL - 7406740 to 7406878
  writeRegister(0x40, 0x03); // TX Buffer - 7406888 to 7407030
  writeRegister(0x41, 0x0E); // TX Buffer - 7407036 to 7407174
  writeRegister(0x44, 0x23); // TX Buffer - 7407184 to 7407325
  writeRegister(0x45, 0x11); // TX Buffer - 7407333 to 7407475
  writeRegister(0x46, 0x13); // TX Buffer - 7407481 to 7407621
  writeRegister(0x04, 0x07); // TX - 7407630 to 7407772
  writeRegister(0x00, 0xFF); // CS0 - 7414411 to 7414552
  writeRegister(0x01, 0xFF); // CS1 - 7414565 to 7414701
  writeRegister(0x16, 0xC0); // FIFO CTRL - 7414715 to 7414850
  writeRegister(0x40, 0x03); // TX Buffer - 7414863 to 7414997
  writeRegister(0x41, 0x0E); // TX Buffer - 7415011 to 7415146
  writeRegister(0x44, 0x23); // TX Buffer - 7415159 to 7415294
  writeRegister(0x45, 0x11); // TX Buffer - 7415308 to 7415442
  writeRegister(0x46, 0x13); // TX Buffer - 7415456 to 7415591
  writeRegister(0x04, 0x07); // TX - 7415605 to 7415739
  writeRegister(0x00, 0xFF); // CS0 - 7422467 to 7422607
  writeRegister(0x01, 0xFF); // CS1 - 7422621 to 7422765
  writeRegister(0x16, 0xC0); // FIFO CTRL - 7422771 to 7422909
  writeRegister(0x40, 0x03); // TX Buffer - 7422920 to 7423053
  writeRegister(0x41, 0x0E); // TX Buffer - 7423067 to 7423202
  writeRegister(0x44, 0x23); // TX Buffer - 7423216 to 7423350
  writeRegister(0x45, 0x11); // TX Buffer - 7423364 to 7423500
  writeRegister(0x46, 0x13); // TX Buffer - 7423512 to 7423649
  writeRegister(0x04, 0x07); // TX - 7423661 to 7423797
  writeRegister(0x00, 0xFF); // CS0 - 7430442 to 7430586
  writeRegister(0x01, 0xFF); // CS1 - 7430592 to 7430732
  writeRegister(0x16, 0xC0); // FIFO CTRL - 7430746 to 7430881
  writeRegister(0x40, 0x03); // TX Buffer - 7430895 to 7431028
  writeRegister(0x41, 0x0E); // TX Buffer - 7431039 to 7431177
  writeRegister(0x44, 0x23); // TX Buffer - 7431187 to 7431325
  writeRegister(0x45, 0x11); // TX Buffer - 7431336 to 7431475
  writeRegister(0x46, 0x13); // TX Buffer - 7431484 to 7431624
  writeRegister(0x04, 0x07); // TX - 7431636 to 7431772
  writeRegister(0x00, 0xFF); // CS0 - 7438414 to 7438555
  writeRegister(0x01, 0xFF); // CS1 - 7438567 to 7438711
  writeRegister(0x16, 0xC0); // FIFO CTRL - 7438718 to 7438856
  writeRegister(0x40, 0x03); // TX Buffer - 7438866 to 7439001
  writeRegister(0x41, 0x0E); // TX Buffer - 7439014 to 7439148
  writeRegister(0x44, 0x23); // TX Buffer - 7439162 to 7439298
  writeRegister(0x45, 0x11); // TX Buffer - 7439311 to 7439445
  writeRegister(0x46, 0x13); // TX Buffer - 7439459 to 7439594
  writeRegister(0x04, 0x07); // TX - 7439608 to 7439742
  writeRegister(0x00, 0xFF); // CS0 - 7446474 to 7446611
  writeRegister(0x01, 0xFF); // CS1 - 7446624 to 7446765
  writeRegister(0x16, 0xC0); // FIFO CTRL - 7446774 to 7446912
  writeRegister(0x40, 0x03); // TX Buffer - 7446922 to 7447064
  writeRegister(0x41, 0x0E); // TX Buffer - 7447070 to 7447208
  writeRegister(0x44, 0x23); // TX Buffer - 7447218 to 7447361
  writeRegister(0x45, 0x11); // TX Buffer - 7447367 to 7447509
  writeRegister(0x46, 0x13); // TX Buffer - 7447515 to 7447655
  writeRegister(0x04, 0x07); // TX - 7447664 to 7447806
  writeRegister(0x00, 0xFF); // CS0 - 7454445 to 7454586
  writeRegister(0x01, 0xFF); // CS1 - 7454595 to 7454735
  writeRegister(0x16, 0xC0); // FIFO CTRL - 7454749 to 7454884
  writeRegister(0x40, 0x03); // TX Buffer - 7454897 to 7455031
  writeRegister(0x41, 0x0E); // TX Buffer - 7455045 to 7455180
  writeRegister(0x44, 0x23); // TX Buffer - 7455193 to 7455328
  writeRegister(0x45, 0x11); // TX Buffer - 7455342 to 7455478
  writeRegister(0x46, 0x13); // TX Buffer - 7455490 to 7455625
  writeRegister(0x04, 0x07); // TX - 7455639 to 7455773
  writeRegister(0x00, 0xFF); // CS0 - 7462420 to 7462556
  writeRegister(0x01, 0xFF); // CS1 - 7462570 to 7462710
  writeRegister(0x16, 0xC0); // FIFO CTRL - 7462721 to 7462859
  writeRegister(0x40, 0x03); // TX Buffer - 7462869 to 7463010
  writeRegister(0x41, 0x0E); // TX Buffer - 7463016 to 7463155
  writeRegister(0x44, 0x23); // TX Buffer - 7463165 to 7463307
  writeRegister(0x45, 0x11); // TX Buffer - 7463313 to 7463454
  writeRegister(0x46, 0x13); // TX Buffer - 7463462 to 7463600
  writeRegister(0x04, 0x07); // TX - 7463611 to 7463752
  writeRegister(0x00, 0xFF); // CS0 - 7470476 to 7470620
  writeRegister(0x01, 0xFF); // CS1 - 7470626 to 7470766
  writeRegister(0x16, 0xC0); // FIFO CTRL - 7470780 to 7470915
  writeRegister(0x40, 0x03); // TX Buffer - 7470929 to 7471062
  writeRegister(0x41, 0x0E); // TX Buffer - 7471073 to 7471211
  writeRegister(0x44, 0x23); // TX Buffer - 7471221 to 7471359
  writeRegister(0x45, 0x11); // TX Buffer - 7471370 to 7471509
  writeRegister(0x46, 0x13); // TX Buffer - 7471518 to 7471658
  writeRegister(0x04, 0x07); // TX - 7471670 to 7471806
  writeRegister(0x00, 0xFF); // CS0 - 7478448 to 7478589
  writeRegister(0x01, 0xFF); // CS1 - 7478601 to 7478745
  writeRegister(0x16, 0xC0); // FIFO CTRL - 7478752 to 7478894
  writeRegister(0x40, 0x03); // TX Buffer - 7478900 to 7479035
  writeRegister(0x41, 0x0E); // TX Buffer - 7479048 to 7479182
  writeRegister(0x44, 0x23); // TX Buffer - 7479196 to 7479332
  writeRegister(0x45, 0x11); // TX Buffer - 7479345 to 7479479
  writeRegister(0x46, 0x13); // TX Buffer - 7479493 to 7479628
  writeRegister(0x04, 0x07); // TX - 7479642 to 7479776
  writeRegister(0x00, 0xFF); // CS0 - 7486423 to 7486567
  writeRegister(0x01, 0xFF); // CS1 - 7486573 to 7486714
  writeRegister(0x16, 0xC0); // FIFO CTRL - 7486727 to 7486861
  writeRegister(0x40, 0x03); // TX Buffer - 7486875 to 7487010
  writeRegister(0x41, 0x0E); // TX Buffer - 7487019 to 7487157
  writeRegister(0x44, 0x23); // TX Buffer - 7487168 to 7487307
  writeRegister(0x45, 0x11); // TX Buffer - 7487316 to 7487454
  writeRegister(0x46, 0x13); // TX Buffer - 7487465 to 7487603
  writeRegister(0x04, 0x07); // TX - 7487617 to 7487751
  writeRegister(0x00, 0xFF); // CS0 - 7494479 to 7494620
  writeRegister(0x01, 0xFF); // CS1 - 7494629 to 7494769
  writeRegister(0x16, 0xC0); // FIFO CTRL - 7494783 to 7494918
  writeRegister(0x40, 0x03); // TX Buffer - 7494931 to 7495065
  writeRegister(0x41, 0x0E); // TX Buffer - 7495079 to 7495214
  writeRegister(0x44, 0x23); // TX Buffer - 7495227 to 7495362
  writeRegister(0x45, 0x11); // TX Buffer - 7495376 to 7495512
  writeRegister(0x46, 0x13); // TX Buffer - 7495524 to 7495659
  writeRegister(0x04, 0x07); // TX - 7495673 to 7495807
  writeRegister(0x00, 0xFF); // CS0 - 7502454 to 7502590
  writeRegister(0x01, 0xFF); // CS1 - 7502604 to 7502744
  writeRegister(0x16, 0xC0); // FIFO CTRL - 7502755 to 7502893
  writeRegister(0x40, 0x03); // TX Buffer - 7502903 to 7503044
  writeRegister(0x41, 0x0E); // TX Buffer - 7503050 to 7503193
  writeRegister(0x44, 0x23); // TX Buffer - 7503199 to 7503341
  writeRegister(0x45, 0x11); // TX Buffer - 7503347 to 7503490
  writeRegister(0x46, 0x13); // TX Buffer - 7503496 to 7503638
  writeRegister(0x04, 0x07); // TX - 7503645 to 7503786
  writeRegister(0x00, 0xFF); // CS0 - 7510426 to 7510565
  writeRegister(0x01, 0xFF); // CS1 - 7510576 to 7510717
  writeRegister(0x16, 0xC0); // FIFO CTRL - 7510730 to 7510864
  writeRegister(0x40, 0x03); // TX Buffer - 7510878 to 7511013
  writeRegister(0x41, 0x0E); // TX Buffer - 7511025 to 7511160
  writeRegister(0x44, 0x23); // TX Buffer - 7511174 to 7511310
  writeRegister(0x45, 0x11); // TX Buffer - 7511322 to 7511457
  writeRegister(0x46, 0x13); // TX Buffer - 7511471 to 7511607
  writeRegister(0x04, 0x07); // TX - 7511620 to 7511755
  writeRegister(0x00, 0xFF); // CS0 - 7518482 to 7518623
  writeRegister(0x01, 0xFF); // CS1 - 7518635 to 7518772
  writeRegister(0x16, 0xC0); // FIFO CTRL - 7518786 to 7518922
  writeRegister(0x40, 0x03); // TX Buffer - 7518934 to 7519069
  writeRegister(0x41, 0x0E); // TX Buffer - 7519082 to 7519216
  writeRegister(0x44, 0x23); // TX Buffer - 7519230 to 7519366
  writeRegister(0x45, 0x11); // TX Buffer - 7519379 to 7519513
  writeRegister(0x46, 0x13); // TX Buffer - 7519527 to 7519662
  writeRegister(0x04, 0x07); // TX - 7519676 to 7519810
  writeRegister(0x00, 0xFF); // CS0 - 7526457 to 7526601
  writeRegister(0x01, 0xFF); // CS1 - 7526607 to 7526748
  writeRegister(0x16, 0xC0); // FIFO CTRL - 7526761 to 7526895
  writeRegister(0x40, 0x03); // TX Buffer - 7526909 to 7527044
  writeRegister(0x41, 0x0E); // TX Buffer - 7527053 to 7527191
  writeRegister(0x44, 0x23); // TX Buffer - 7527202 to 7527341
  writeRegister(0x45, 0x11); // TX Buffer - 7527350 to 7527488
  writeRegister(0x46, 0x13); // TX Buffer - 7527499 to 7527637
  writeRegister(0x04, 0x07); // TX - 7527648 to 7527785
  writeRegister(0x00, 0xFF); // CS0 - 7534429 to 7534568
  writeRegister(0x01, 0xFF); // CS1 - 7534582 to 7534720
  writeRegister(0x16, 0xC0); // FIFO CTRL - 7534732 to 7534867
  writeRegister(0x40, 0x03); // TX Buffer - 7534881 to 7535016
  writeRegister(0x41, 0x0E); // TX Buffer - 7535028 to 7535163
  writeRegister(0x44, 0x23); // TX Buffer - 7535177 to 7535311
  writeRegister(0x45, 0x11); // TX Buffer - 7535325 to 7535461
  writeRegister(0x46, 0x13); // TX Buffer - 7535474 to 7535610
  writeRegister(0x04, 0x07); // TX - 7535623 to 7535758
  writeRegister(0x00, 0xFF); // CS0 - 7542488 to 7542624
  writeRegister(0x01, 0xFF); // CS1 - 7542638 to 7542778
  writeRegister(0x16, 0xC0); // FIFO CTRL - 7542789 to 7542927
  writeRegister(0x40, 0x03); // TX Buffer - 7542937 to 7543072
  writeRegister(0x41, 0x0E); // TX Buffer - 7543085 to 7543219
  writeRegister(0x44, 0x23); // TX Buffer - 7543233 to 7543369
  writeRegister(0x45, 0x11); // TX Buffer - 7543381 to 7543516
  writeRegister(0x46, 0x13); // TX Buffer - 7543530 to 7543671
  writeRegister(0x04, 0x07); // TX - 7543679 to 7543814
  writeRegister(0x00, 0xFF); // CS0 - 7550460 to 7550599
  writeRegister(0x01, 0xFF); // CS1 - 7550610 to 7550751
  writeRegister(0x16, 0xC0); // FIFO CTRL - 7550764 to 7550898
  writeRegister(0x40, 0x03); // TX Buffer - 7550912 to 7551047
  writeRegister(0x41, 0x0E); // TX Buffer - 7551059 to 7551194
  writeRegister(0x44, 0x23); // TX Buffer - 7551208 to 7551344
  writeRegister(0x45, 0x11); // TX Buffer - 7551356 to 7551491
  writeRegister(0x46, 0x13); // TX Buffer - 7551505 to 7551641
  writeRegister(0x04, 0x07); // TX - 7551654 to 7551789
  writeRegister(0x00, 0xFF); // CS0 - 7558435 to 7558572
  writeRegister(0x01, 0xFF); // CS1 - 7558585 to 7558726
  writeRegister(0x16, 0xC0); // FIFO CTRL - 7558735 to 7558873
  writeRegister(0x40, 0x03); // TX Buffer - 7558884 to 7559017
  writeRegister(0x41, 0x0E); // TX Buffer - 7559031 to 7559166
  writeRegister(0x44, 0x23); // TX Buffer - 7559179 to 7559314
  writeRegister(0x45, 0x11); // TX Buffer - 7559328 to 7559464
  writeRegister(0x46, 0x13); // TX Buffer - 7559476 to 7559619
  writeRegister(0x04, 0x07); // TX - 7559625 to 7559761
  writeRegister(0x00, 0xFF); // CS0 - 7566491 to 7566627
  writeRegister(0x01, 0xFF); // CS1 - 7566641 to 7566781
  writeRegister(0x16, 0xC0); // FIFO CTRL - 7566795 to 7566931
  writeRegister(0x40, 0x03); // TX Buffer - 7566943 to 7567078
  writeRegister(0x41, 0x0E); // TX Buffer - 7567087 to 7567225
  writeRegister(0x44, 0x23); // TX Buffer - 7567236 to 7567375
  writeRegister(0x45, 0x11); // TX Buffer - 7567384 to 7567522
  writeRegister(0x46, 0x13); // TX Buffer - 7567533 to 7567671
  writeRegister(0x04, 0x07); // TX - 7567682 to 7567819
  writeRegister(0x00, 0xFF); // CS0 - 7574463 to 7574602
  writeRegister(0x01, 0xFF); // CS1 - 7574616 to 7574754
  writeRegister(0x16, 0xC0); // FIFO CTRL - 7574766 to 7574901
  writeRegister(0x40, 0x03); // TX Buffer - 7574915 to 7575050
  writeRegister(0x41, 0x0E); // TX Buffer - 7575062 to 7575197
  writeRegister(0x44, 0x23); // TX Buffer - 7575211 to 7575345
  writeRegister(0x45, 0x11); // TX Buffer - 7575359 to 7575495
  writeRegister(0x46, 0x13); // TX Buffer - 7575508 to 7575644
  writeRegister(0x04, 0x07); // TX - 7575657 to 7575792
  writeRegister(0x00, 0xFF); // CS0 - 7582438 to 7582575
  writeRegister(0x01, 0xFF); // CS1 - 7582587 to 7582729
  writeRegister(0x16, 0xC0); // FIFO CTRL - 7582741 to 7582876
  writeRegister(0x40, 0x03); // TX Buffer - 7582890 to 7583025
  writeRegister(0x41, 0x0E); // TX Buffer - 7583034 to 7583172
  writeRegister(0x44, 0x23); // TX Buffer - 7583182 to 7583320
  writeRegister(0x45, 0x11); // TX Buffer - 7583331 to 7583470
  writeRegister(0x46, 0x13); // TX Buffer - 7583479 to 7583619
  writeRegister(0x04, 0x07); // TX - 7583628 to 7583767
  writeRegister(0x00, 0xFF); // CS0 - 7590494 to 7590633
  writeRegister(0x01, 0xFF); // CS1 - 7590644 to 7590785
  writeRegister(0x16, 0xC0); // FIFO CTRL - 7590798 to 7590932
  writeRegister(0x40, 0x03); // TX Buffer - 7590946 to 7591081
  writeRegister(0x41, 0x0E); // TX Buffer - 7591094 to 7591228
  writeRegister(0x44, 0x23); // TX Buffer - 7591242 to 7591378
  writeRegister(0x45, 0x11); // TX Buffer - 7591390 to 7591525
  writeRegister(0x46, 0x13); // TX Buffer - 7591539 to 7591674
  writeRegister(0x04, 0x07); // TX - 7591688 to 7591823
  writeRegister(0x00, 0xFF); // CS0 - 7598465 to 7598606
  writeRegister(0x01, 0xFF); // CS1 - 7598619 to 7598763
  writeRegister(0x16, 0xC0); // FIFO CTRL - 7598769 to 7598907
  writeRegister(0x40, 0x03); // TX Buffer - 7598918 to 7599051
  writeRegister(0x41, 0x0E); // TX Buffer - 7599065 to 7599200
  writeRegister(0x44, 0x23); // TX Buffer - 7599214 to 7599348
  writeRegister(0x45, 0x11); // TX Buffer - 7599362 to 7599498
  writeRegister(0x46, 0x13); // TX Buffer - 7599510 to 7599653
  writeRegister(0x04, 0x07); // TX - 7599659 to 7599795
  writeRegister(0x00, 0xFF); // CS0 - 7606440 to 7606581
  writeRegister(0x01, 0xFF); // CS1 - 7606590 to 7606730
  writeRegister(0x16, 0xC0); // FIFO CTRL - 7606744 to 7606879
  writeRegister(0x40, 0x03); // TX Buffer - 7606893 to 7607026
  writeRegister(0x41, 0x0E); // TX Buffer - 7607040 to 7607175
  writeRegister(0x44, 0x23); // TX Buffer - 7607188 to 7607323
  writeRegister(0x45, 0x11); // TX Buffer - 7607337 to 7607473
  writeRegister(0x46, 0x13); // TX Buffer - 7607485 to 7607622
  writeRegister(0x04, 0x07); // TX - 7607634 to 7607770
  writeRegister(0x00, 0xFF); // CS0 - 7614497 to 7614636
  writeRegister(0x01, 0xFF); // CS1 - 7614650 to 7614788
  writeRegister(0x16, 0xC0); // FIFO CTRL - 7614800 to 7614935
  writeRegister(0x40, 0x03); // TX Buffer - 7614949 to 7615084
  writeRegister(0x41, 0x0E); // TX Buffer - 7615096 to 7615231
  writeRegister(0x44, 0x23); // TX Buffer - 7615245 to 7615379
  writeRegister(0x45, 0x11); // TX Buffer - 7615393 to 7615529
  writeRegister(0x46, 0x13); // TX Buffer - 7615542 to 7615678
  writeRegister(0x04, 0x07); // TX - 7615691 to 7615826
  writeRegister(0x00, 0xFF); // CS0 - 7622472 to 7622609
  writeRegister(0x01, 0xFF); // CS1 - 7622622 to 7622763
  writeRegister(0x16, 0xC0); // FIFO CTRL - 7622772 to 7622910
  writeRegister(0x40, 0x03); // TX Buffer - 7622920 to 7623062
  writeRegister(0x41, 0x0E); // TX Buffer - 7623068 to 7623206
  writeRegister(0x44, 0x23); // TX Buffer - 7623216 to 7623358
  writeRegister(0x45, 0x11); // TX Buffer - 7623365 to 7623507
  writeRegister(0x46, 0x13); // TX Buffer - 7623513 to 7623653
  writeRegister(0x04, 0x07); // TX - 7623662 to 7623804
  writeRegister(0x00, 0xFF); // CS0 - 7630443 to 7630584
  writeRegister(0x01, 0xFF); // CS1 - 7630596 to 7630733
  writeRegister(0x16, 0xC0); // FIFO CTRL - 7630747 to 7630882
  writeRegister(0x40, 0x03); // TX Buffer - 7630895 to 7631029
  writeRegister(0x41, 0x0E); // TX Buffer - 7631043 to 7631179
  writeRegister(0x44, 0x23); // TX Buffer - 7631191 to 7631327
  writeRegister(0x45, 0x11); // TX Buffer - 7631340 to 7631474
  writeRegister(0x46, 0x13); // TX Buffer - 7631488 to 7631623
  writeRegister(0x04, 0x07); // TX - 7631637 to 7631771
  writeRegister(0x00, 0xFF); // CS0 - 7638499 to 7638640
  writeRegister(0x01, 0xFF); // CS1 - 7638653 to 7638797
  writeRegister(0x16, 0xC0); // FIFO CTRL - 7638803 to 7638941
  writeRegister(0x40, 0x03); // TX Buffer - 7638952 to 7639085
  writeRegister(0x41, 0x0E); // TX Buffer - 7639099 to 7639234
  writeRegister(0x44, 0x23); // TX Buffer - 7639248 to 7639382
  writeRegister(0x45, 0x11); // TX Buffer - 7639396 to 7639532
  writeRegister(0x46, 0x13); // TX Buffer - 7639544 to 7639681
  writeRegister(0x04, 0x07); // TX - 7639693 to 7639829
  writeRegister(0x00, 0xFF); // CS0 - 7646474 to 7646618
  writeRegister(0x01, 0xFF); // CS1 - 7646624 to 7646764
  writeRegister(0x16, 0xC0); // FIFO CTRL - 7646778 to 7646913
  writeRegister(0x40, 0x03); // TX Buffer - 7646927 to 7647060
  writeRegister(0x41, 0x0E); // TX Buffer - 7647071 to 7647209
  writeRegister(0x44, 0x23); // TX Buffer - 7647219 to 7647357
  writeRegister(0x45, 0x11); // TX Buffer - 7647368 to 7647507
  writeRegister(0x46, 0x13); // TX Buffer - 7647516 to 7647656
  writeRegister(0x04, 0x07); // TX - 7647668 to 7647804
  writeRegister(0x00, 0xFF); // CS0 - 7654446 to 7654587
  writeRegister(0x01, 0xFF); // CS1 - 7654599 to 7654743
  writeRegister(0x16, 0xC0); // FIFO CTRL - 7654750 to 7654888
  writeRegister(0x40, 0x03); // TX Buffer - 7654898 to 7655033
  writeRegister(0x41, 0x0E); // TX Buffer - 7655046 to 7655180
  writeRegister(0x44, 0x23); // TX Buffer - 7655194 to 7655330
  writeRegister(0x45, 0x11); // TX Buffer - 7655342 to 7655477
  writeRegister(0x46, 0x13); // TX Buffer - 7655491 to 7655626
  writeRegister(0x04, 0x07); // TX - 7655640 to 7655774
  writeRegister(0x00, 0xFF); // CS0 - 7662506 to 7662643
  writeRegister(0x01, 0xFF); // CS1 - 7662656 to 7662797
  writeRegister(0x16, 0xC0); // FIFO CTRL - 7662806 to 7662944
  writeRegister(0x40, 0x03); // TX Buffer - 7662954 to 7663096
  writeRegister(0x41, 0x0E); // TX Buffer - 7663102 to 7663240
  writeRegister(0x44, 0x23); // TX Buffer - 7663250 to 7663392
  writeRegister(0x45, 0x11); // TX Buffer - 7663399 to 7663541
  writeRegister(0x46, 0x13); // TX Buffer - 7663547 to 7663687
  writeRegister(0x04, 0x07); // TX - 7663696 to 7663838
  writeRegister(0x00, 0xFF); // CS0 - 7670477 to 7670618
  writeRegister(0x01, 0xFF); // CS1 - 7670627 to 7670767
  writeRegister(0x16, 0xC0); // FIFO CTRL - 7670781 to 7670916
  writeRegister(0x40, 0x03); // TX Buffer - 7670929 to 7671063
  writeRegister(0x41, 0x0E); // TX Buffer - 7671077 to 7671213
  writeRegister(0x44, 0x23); // TX Buffer - 7671225 to 7671361
  writeRegister(0x45, 0x11); // TX Buffer - 7671374 to 7671508
  writeRegister(0x46, 0x13); // TX Buffer - 7671522 to 7671657
  writeRegister(0x04, 0x07); // TX - 7671671 to 7671805
  writeRegister(0x00, 0xFF); // CS0 - 7678452 to 7678588
  writeRegister(0x01, 0xFF); // CS1 - 7678602 to 7678742
  writeRegister(0x16, 0xC0); // FIFO CTRL - 7678752 to 7678891
  writeRegister(0x40, 0x03); // TX Buffer - 7678901 to 7679042
  writeRegister(0x41, 0x0E); // TX Buffer - 7679048 to 7679188
  writeRegister(0x44, 0x23); // TX Buffer - 7679197 to 7679339
  writeRegister(0x45, 0x11); // TX Buffer - 7679345 to 7679487
  writeRegister(0x46, 0x13); // TX Buffer - 7679494 to 7679632
  writeRegister(0x04, 0x07); // TX - 7679643 to 7679784
  writeRegister(0x00, 0xFF); // CS0 - 7686508 to 7686652
  writeRegister(0x01, 0xFF); // CS1 - 7686658 to 7686798
  writeRegister(0x16, 0xC0); // FIFO CTRL - 7686812 to 7686947
  writeRegister(0x40, 0x03); // TX Buffer - 7686961 to 7687094
  writeRegister(0x41, 0x0E); // TX Buffer - 7687105 to 7687243
  writeRegister(0x44, 0x23); // TX Buffer - 7687253 to 7687391
  writeRegister(0x45, 0x11); // TX Buffer - 7687402 to 7687541
  writeRegister(0x46, 0x13); // TX Buffer - 7687550 to 7687690
  writeRegister(0x04, 0x07); // TX - 7687702 to 7687838
  writeRegister(0x00, 0xFF); // CS0 - 7694480 to 7694621
  writeRegister(0x01, 0xFF); // CS1 - 7694633 to 7694777
  writeRegister(0x16, 0xC0); // FIFO CTRL - 7694784 to 7694926
  writeRegister(0x40, 0x03); // TX Buffer - 7694932 to 7695067
  writeRegister(0x41, 0x0E); // TX Buffer - 7695080 to 7695214
  writeRegister(0x44, 0x23); // TX Buffer - 7695228 to 7695364
  writeRegister(0x45, 0x11); // TX Buffer - 7695377 to 7695511
  writeRegister(0x46, 0x13); // TX Buffer - 7695525 to 7695660
  writeRegister(0x04, 0x07); // TX - 7695674 to 7695808
  writeRegister(0x00, 0xFF); // CS0 - 7702455 to 7702599
  writeRegister(0x01, 0xFF); // CS1 - 7702605 to 7702746
  writeRegister(0x16, 0xC0); // FIFO CTRL - 7702759 to 7702893
  writeRegister(0x40, 0x03); // TX Buffer - 7702907 to 7703042
  writeRegister(0x41, 0x0E); // TX Buffer - 7703051 to 7703189
  writeRegister(0x44, 0x23); // TX Buffer - 7703200 to 7703339
  writeRegister(0x45, 0x11); // TX Buffer - 7703348 to 7703486
  writeRegister(0x46, 0x13); // TX Buffer - 7703497 to 7703635
  writeRegister(0x04, 0x07); // TX - 7703649 to 7703783
  writeRegister(0x00, 0xFF); // CS0 - 7710503 to 7710644
  writeRegister(0x01, 0xFF); // CS1 - 7710653 to 7710793
  writeRegister(0x16, 0xC0); // FIFO CTRL - 7710807 to 7710942
  writeRegister(0x40, 0x03); // TX Buffer - 7710955 to 7711089
  writeRegister(0x41, 0x0E); // TX Buffer - 7711103 to 7711239
  writeRegister(0x44, 0x23); // TX Buffer - 7711251 to 7711387
  writeRegister(0x45, 0x11); // TX Buffer - 7711400 to 7711534
  writeRegister(0x46, 0x13); // TX Buffer - 7711548 to 7711683
  writeRegister(0x04, 0x07); // TX - 7711697 to 7711831
  writeRegister(0x00, 0xFF); // CS0 - 7718478 to 7718614
  writeRegister(0x01, 0xFF); // CS1 - 7718628 to 7718768
  writeRegister(0x16, 0xC0); // FIFO CTRL - 7718778 to 7718917
  writeRegister(0x40, 0x03); // TX Buffer - 7718927 to 7719062
  writeRegister(0x41, 0x0E); // TX Buffer - 7719074 to 7719209
  writeRegister(0x44, 0x23); // TX Buffer - 7719223 to 7719359
  writeRegister(0x45, 0x11); // TX Buffer - 7719371 to 7719507
  writeRegister(0x46, 0x13); // TX Buffer - 7719520 to 7719662
  writeRegister(0x04, 0x07); // TX - 7719669 to 7719804
  writeRegister(0x00, 0xFF); // CS0 - 7726450 to 7726589
  writeRegister(0x01, 0xFF); // CS1 - 7726600 to 7726741
  writeRegister(0x16, 0xC0); // FIFO CTRL - 7726753 to 7726888
  writeRegister(0x40, 0x03); // TX Buffer - 7726902 to 7727037
  writeRegister(0x41, 0x0E); // TX Buffer - 7727049 to 7727184
  writeRegister(0x44, 0x23); // TX Buffer - 7727198 to 7727332
  writeRegister(0x45, 0x11); // TX Buffer - 7727346 to 7727482
  writeRegister(0x46, 0x13); // TX Buffer - 7727495 to 7727631
  writeRegister(0x04, 0x07); // TX - 7727644 to 7727779
  writeRegister(0x00, 0xFF); // CS0 - 7734506 to 7734647
  writeRegister(0x01, 0xFF); // CS1 - 7734659 to 7734797
  writeRegister(0x16, 0xC0); // FIFO CTRL - 7734810 to 7734944
  writeRegister(0x40, 0x03); // TX Buffer - 7734958 to 7735093
  writeRegister(0x41, 0x0E); // TX Buffer - 7735106 to 7735240
  writeRegister(0x44, 0x23); // TX Buffer - 7735254 to 7735390
  writeRegister(0x45, 0x11); // TX Buffer - 7735402 to 7735537
  writeRegister(0x46, 0x13); // TX Buffer - 7735551 to 7735686
  writeRegister(0x04, 0x07); // TX - 7735700 to 7735834
  writeRegister(0x00, 0xFF); // CS0 - 7742481 to 7742617
  writeRegister(0x01, 0xFF); // CS1 - 7742631 to 7742772
  writeRegister(0x16, 0xC0); // FIFO CTRL - 7742785 to 7742919
  writeRegister(0x40, 0x03); // TX Buffer - 7742933 to 7743068
  writeRegister(0x41, 0x0E); // TX Buffer - 7743077 to 7743215
  writeRegister(0x44, 0x23); // TX Buffer - 7743226 to 7743365
  writeRegister(0x45, 0x11); // TX Buffer - 7743374 to 7743512
  writeRegister(0x46, 0x13); // TX Buffer - 7743522 to 7743661
  writeRegister(0x04, 0x07); // TX - 7743671 to 7743809
  writeRegister(0x00, 0xFF); // CS0 - 7750452 to 7750592
  writeRegister(0x01, 0xFF); // CS1 - 7750606 to 7750742
  writeRegister(0x16, 0xC0); // FIFO CTRL - 7750756 to 7750891
  writeRegister(0x40, 0x03); // TX Buffer - 7750905 to 7751038
  writeRegister(0x41, 0x0E); // TX Buffer - 7751052 to 7751187
  writeRegister(0x44, 0x23); // TX Buffer - 7751201 to 7751335
  writeRegister(0x45, 0x11); // TX Buffer - 7751349 to 7751485
  writeRegister(0x46, 0x13); // TX Buffer - 7751497 to 7751634
  writeRegister(0x04, 0x07); // TX - 7751646 to 7751782
  writeRegister(0x00, 0xFF); // CS0 - 7758509 to 7758648
  writeRegister(0x01, 0xFF); // CS1 - 7758662 to 7758806
  writeRegister(0x16, 0xC0); // FIFO CTRL - 7758812 to 7758951
  writeRegister(0x40, 0x03); // TX Buffer - 7758961 to 7759096
  writeRegister(0x41, 0x0E); // TX Buffer - 7759108 to 7759243
  writeRegister(0x44, 0x23); // TX Buffer - 7759257 to 7759393
  writeRegister(0x45, 0x11); // TX Buffer - 7759405 to 7759541
  writeRegister(0x46, 0x13); // TX Buffer - 7759554 to 7759696
  writeRegister(0x04, 0x07); // TX - 7759703 to 7759838
  writeRegister(0x00, 0xFF); // CS0 - 7766484 to 7766623
  writeRegister(0x01, 0xFF); // CS1 - 7766634 to 7766775
  writeRegister(0x16, 0xC0); // FIFO CTRL - 7766787 to 7766922
  writeRegister(0x40, 0x03); // TX Buffer - 7766936 to 7767071
  writeRegister(0x41, 0x0E); // TX Buffer - 7767083 to 7767218
  writeRegister(0x44, 0x23); // TX Buffer - 7767232 to 7767368
  writeRegister(0x45, 0x11); // TX Buffer - 7767380 to 7767516
  writeRegister(0x46, 0x13); // TX Buffer - 7767529 to 7767665
  writeRegister(0x04, 0x07); // TX - 7767678 to 7767813
  writeRegister(0x00, 0xFF); // CS0 - 7774455 to 7774596
  writeRegister(0x01, 0xFF); // CS1 - 7774609 to 7774753
  writeRegister(0x16, 0xC0); // FIFO CTRL - 7774759 to 7774897
  writeRegister(0x40, 0x03); // TX Buffer - 7774907 to 7775041
  writeRegister(0x41, 0x0E); // TX Buffer - 7775055 to 7775190
  writeRegister(0x44, 0x23); // TX Buffer - 7775203 to 7775338
  writeRegister(0x45, 0x11); // TX Buffer - 7775352 to 7775488
  writeRegister(0x46, 0x13); // TX Buffer - 7775500 to 7775643
  writeRegister(0x04, 0x07); // TX - 7775649 to 7775783
  writeRegister(0x00, 0xFF); // CS0 - 7782515 to 7782651
  writeRegister(0x01, 0xFF); // CS1 - 7782665 to 7782806
  writeRegister(0x16, 0xC0); // FIFO CTRL - 7782815 to 7782953
  writeRegister(0x40, 0x03); // TX Buffer - 7782964 to 7783105
  writeRegister(0x41, 0x0E); // TX Buffer - 7783111 to 7783249
  writeRegister(0x44, 0x23); // TX Buffer - 7783260 to 7783402
  writeRegister(0x45, 0x11); // TX Buffer - 7783408 to 7783550
  writeRegister(0x46, 0x13); // TX Buffer - 7783557 to 7783695
  writeRegister(0x04, 0x07); // TX - 7783705 to 7783847
  writeRegister(0x00, 0xFF); // CS0 - 7790486 to 7790626
  writeRegister(0x01, 0xFF); // CS1 - 7790640 to 7790776
  writeRegister(0x16, 0xC0); // FIFO CTRL - 7790790 to 7790925
  writeRegister(0x40, 0x03); // TX Buffer - 7790939 to 7791072
  writeRegister(0x41, 0x0E); // TX Buffer - 7791086 to 7791221
  writeRegister(0x44, 0x23); // TX Buffer - 7791235 to 7791369
  writeRegister(0x45, 0x11); // TX Buffer - 7791383 to 7791519
  writeRegister(0x46, 0x13); // TX Buffer - 7791531 to 7791668
  writeRegister(0x04, 0x07); // TX - 7791680 to 7791816
  writeRegister(0x00, 0xFF); // CS0 - 7798461 to 7798599
  writeRegister(0x01, 0xFF); // CS1 - 7798611 to 7798751
  writeRegister(0x16, 0xC0); // FIFO CTRL - 7798762 to 7798900
  writeRegister(0x40, 0x03); // TX Buffer - 7798910 to 7799051
  writeRegister(0x41, 0x0E); // TX Buffer - 7799058 to 7799196
  writeRegister(0x44, 0x23); // TX Buffer - 7799206 to 7799348
  writeRegister(0x45, 0x11); // TX Buffer - 7799355 to 7799497
  writeRegister(0x46, 0x13); // TX Buffer - 7799503 to 7799643
  writeRegister(0x04, 0x07); // TX - 7799652 to 7799794
  writeRegister(0x00, 0xFF); // CS0 - 7806433 to 7806574
  writeRegister(0x01, 0xFF); // CS1 - 7806586 to 7806724
  writeRegister(0x16, 0xC0); // FIFO CTRL - 7806737 to 7806871
  writeRegister(0x40, 0x03); // TX Buffer - 7806885 to 7807020
  writeRegister(0x41, 0x0E); // TX Buffer - 7807033 to 7807167
  writeRegister(0x44, 0x23); // TX Buffer - 7807181 to 7807317
  writeRegister(0x45, 0x11); // TX Buffer - 7807330 to 7807464
  writeRegister(0x46, 0x13); // TX Buffer - 7807478 to 7807613
  writeRegister(0x04, 0x07); // TX - 7807627 to 7807761
  writeRegister(0x00, 0xFF); // CS0 - 7814489 to 7814630
  writeRegister(0x01, 0xFF); // CS1 - 7814643 to 7814787
  writeRegister(0x16, 0xC0); // FIFO CTRL - 7814793 to 7814931
  writeRegister(0x40, 0x03); // TX Buffer - 7814941 to 7815075
  writeRegister(0x41, 0x0E); // TX Buffer - 7815089 to 7815224
  writeRegister(0x44, 0x23); // TX Buffer - 7815237 to 7815372
  writeRegister(0x45, 0x11); // TX Buffer - 7815386 to 7815522
  writeRegister(0x46, 0x13); // TX Buffer - 7815534 to 7815669
  writeRegister(0x04, 0x07); // TX - 7815683 to 7815817
  writeRegister(0x00, 0xFF); // CS0 - 7822464 to 7822608
  writeRegister(0x01, 0xFF); // CS1 - 7822614 to 7822754
  writeRegister(0x16, 0xC0); // FIFO CTRL - 7822768 to 7822903
  writeRegister(0x40, 0x03); // TX Buffer - 7822916 to 7823050
  writeRegister(0x41, 0x0E); // TX Buffer - 7823060 to 7823199
  writeRegister(0x44, 0x23); // TX Buffer - 7823209 to 7823347
  writeRegister(0x45, 0x11); // TX Buffer - 7823357 to 7823497
  writeRegister(0x46, 0x13); // TX Buffer - 7823506 to 7823644
  writeRegister(0x04, 0x07); // TX - 7823658 to 7823792
  writeRegister(0x00, 0xFF); // CS0 - 7830436 to 7830575
  writeRegister(0x01, 0xFF); // CS1 - 7830589 to 7830733
  writeRegister(0x16, 0xC0); // FIFO CTRL - 7830740 to 7830878
  writeRegister(0x40, 0x03); // TX Buffer - 7830888 to 7831023
  writeRegister(0x41, 0x0E); // TX Buffer - 7831035 to 7831170
  writeRegister(0x44, 0x23); // TX Buffer - 7831184 to 7831320
  writeRegister(0x45, 0x11); // TX Buffer - 7831332 to 7831467
  writeRegister(0x46, 0x13); // TX Buffer - 7831481 to 7831617
  writeRegister(0x04, 0x07); // TX - 7831630 to 7831765
  writeRegister(0x00, 0xFF); // CS0 - 7838495 to 7838633
  writeRegister(0x01, 0xFF); // CS1 - 7838645 to 7838785
  writeRegister(0x16, 0xC0); // FIFO CTRL - 7838796 to 7838934
  writeRegister(0x40, 0x03); // TX Buffer - 7838944 to 7839085
  writeRegister(0x41, 0x0E); // TX Buffer - 7839092 to 7839230
  writeRegister(0x44, 0x23); // TX Buffer - 7839240 to 7839382
  writeRegister(0x45, 0x11); // TX Buffer - 7839389 to 7839531
  writeRegister(0x46, 0x13); // TX Buffer - 7839537 to 7839677
  writeRegister(0x04, 0x07); // TX - 7839686 to 7839828
  writeRegister(0x00, 0xFF); // CS0 - 7846467 to 7846608
  writeRegister(0x01, 0xFF); // CS1 - 7846617 to 7846758
  writeRegister(0x16, 0xC0); // FIFO CTRL - 7846771 to 7846905
  writeRegister(0x40, 0x03); // TX Buffer - 7846919 to 7847054
  writeRegister(0x41, 0x0E); // TX Buffer - 7847067 to 7847201
  writeRegister(0x44, 0x23); // TX Buffer - 7847215 to 7847351
  writeRegister(0x45, 0x11); // TX Buffer - 7847364 to 7847498
  writeRegister(0x46, 0x13); // TX Buffer - 7847512 to 7847647
  writeRegister(0x04, 0x07); // TX - 7847661 to 7847795
  writeRegister(0x00, 0xFF); // CS0 - 7854442 to 7854578
  writeRegister(0x01, 0xFF); // CS1 - 7854592 to 7854733
  writeRegister(0x16, 0xC0); // FIFO CTRL - 7854742 to 7854880
  writeRegister(0x40, 0x03); // TX Buffer - 7854891 to 7855032
  writeRegister(0x41, 0x0E); // TX Buffer - 7855038 to 7855176
  writeRegister(0x44, 0x23); // TX Buffer - 7855187 to 7855329
  writeRegister(0x45, 0x11); // TX Buffer - 7855335 to 7855477
  writeRegister(0x46, 0x13); // TX Buffer - 7855484 to 7855622
  writeRegister(0x04, 0x07); // TX - 7855633 to 7855774
  writeRegister(0x00, 0xFF); // CS0 - 7862498 to 7862642
  writeRegister(0x01, 0xFF); // CS1 - 7862648 to 7862788
  writeRegister(0x16, 0xC0); // FIFO CTRL - 7862802 to 7862937
  writeRegister(0x40, 0x03); // TX Buffer - 7862950 to 7863084
  writeRegister(0x41, 0x0E); // TX Buffer - 7863094 to 7863233
  writeRegister(0x44, 0x23); // TX Buffer - 7863243 to 7863381
  writeRegister(0x45, 0x11); // TX Buffer - 7863391 to 7863531
  writeRegister(0x46, 0x13); // TX Buffer - 7863540 to 7863678
  writeRegister(0x04, 0x07); // TX - 7863692 to 7863826
  writeRegister(0x00, 0xFF); // CS0 - 7870470 to 7870609
  writeRegister(0x01, 0xFF); // CS1 - 7870623 to 7870767
  writeRegister(0x16, 0xC0); // FIFO CTRL - 7870774 to 7870916
  writeRegister(0x40, 0x03); // TX Buffer - 7870922 to 7871057
  writeRegister(0x41, 0x0E); // TX Buffer - 7871069 to 7871204
  writeRegister(0x44, 0x23); // TX Buffer - 7871218 to 7871354
  writeRegister(0x45, 0x11); // TX Buffer - 7871366 to 7871501
  writeRegister(0x46, 0x13); // TX Buffer - 7871515 to 7871651
  writeRegister(0x04, 0x07); // TX - 7871664 to 7871799
  writeRegister(0x00, 0xFF); // CS0 - 7878445 to 7878588
  writeRegister(0x01, 0xFF); // CS1 - 7878595 to 7878736
  writeRegister(0x16, 0xC0); // FIFO CTRL - 7878749 to 7878883
  writeRegister(0x40, 0x03); // TX Buffer - 7878897 to 7879032
  writeRegister(0x41, 0x0E); // TX Buffer - 7879041 to 7879179
  writeRegister(0x44, 0x23); // TX Buffer - 7879189 to 7879329
  writeRegister(0x45, 0x11); // TX Buffer - 7879338 to 7879476
  writeRegister(0x46, 0x13); // TX Buffer - 7879486 to 7879626
  writeRegister(0x04, 0x07); // TX - 7879639 to 7879774
  writeRegister(0x00, 0xFF); // CS0 - 7886501 to 7886642
  writeRegister(0x01, 0xFF); // CS1 - 7886651 to 7886791
  writeRegister(0x16, 0xC0); // FIFO CTRL - 7886805 to 7886941
  writeRegister(0x40, 0x03); // TX Buffer - 7886953 to 7887088
  writeRegister(0x41, 0x0E); // TX Buffer - 7887101 to 7887235
  writeRegister(0x44, 0x23); // TX Buffer - 7887249 to 7887385
  writeRegister(0x45, 0x11); // TX Buffer - 7887398 to 7887532
  writeRegister(0x46, 0x13); // TX Buffer - 7887546 to 7887681
  writeRegister(0x04, 0x07); // TX - 7887695 to 7887829
  writeRegister(0x00, 0xFF); // CS0 - 7894476 to 7894612
  writeRegister(0x01, 0xFF); // CS1 - 7894626 to 7894767
  writeRegister(0x16, 0xC0); // FIFO CTRL - 7894776 to 7894914
  writeRegister(0x40, 0x03); // TX Buffer - 7894925 to 7895066
  writeRegister(0x41, 0x0E); // TX Buffer - 7895072 to 7895213
  writeRegister(0x44, 0x23); // TX Buffer - 7895221 to 7895363
  writeRegister(0x45, 0x11); // TX Buffer - 7895369 to 7895511
  writeRegister(0x46, 0x13); // TX Buffer - 7895518 to 7895660
  writeRegister(0x04, 0x07); // TX - 7895667 to 7895808
  writeRegister(0x00, 0xFF); // CS0 - 7902448 to 7902587
  writeRegister(0x01, 0xFF); // CS1 - 7902597 to 7902739
  writeRegister(0x16, 0xC0); // FIFO CTRL - 7902751 to 7902886
  writeRegister(0x40, 0x03); // TX Buffer - 7902900 to 7903033
  writeRegister(0x41, 0x0E); // TX Buffer - 7903047 to 7903182
  writeRegister(0x44, 0x23); // TX Buffer - 7903196 to 7903330
  writeRegister(0x45, 0x11); // TX Buffer - 7903344 to 7903480
  writeRegister(0x46, 0x13); // TX Buffer - 7903493 to 7903629
  writeRegister(0x04, 0x07); // TX - 7903642 to 7903777
  writeRegister(0x00, 0xFF); // CS0 - 7910504 to 7910643
  writeRegister(0x01, 0xFF); // CS1 - 7910657 to 7910795
  writeRegister(0x16, 0xC0); // FIFO CTRL - 7910808 to 7910942
  writeRegister(0x40, 0x03); // TX Buffer - 7910956 to 7911091
  writeRegister(0x41, 0x0E); // TX Buffer - 7911103 to 7911238
  writeRegister(0x44, 0x23); // TX Buffer - 7911252 to 7911388
  writeRegister(0x45, 0x11); // TX Buffer - 7911400 to 7911535
  writeRegister(0x46, 0x13); // TX Buffer - 7911549 to 7911685
  writeRegister(0x04, 0x07); // TX - 7911698 to 7911833
  writeRegister(0x00, 0xFF); // CS0 - 7918479 to 7918622
  writeRegister(0x01, 0xFF); // CS1 - 7918629 to 7918770
  writeRegister(0x16, 0xC0); // FIFO CTRL - 7918783 to 7918917
  writeRegister(0x40, 0x03); // TX Buffer - 7918931 to 7919066
  writeRegister(0x41, 0x0E); // TX Buffer - 7919075 to 7919213
  writeRegister(0x44, 0x23); // TX Buffer - 7919223 to 7919363
  writeRegister(0x45, 0x11); // TX Buffer - 7919372 to 7919510
  writeRegister(0x46, 0x13); // TX Buffer - 7919520 to 7919660
  writeRegister(0x04, 0x07); // TX - 7919669 to 7919808
  writeRegister(0x00, 0xFF); // CS0 - 7926450 to 7926591
  writeRegister(0x01, 0xFF); // CS1 - 7926604 to 7926740
  writeRegister(0x16, 0xC0); // FIFO CTRL - 7926754 to 7926889
  writeRegister(0x40, 0x03); // TX Buffer - 7926903 to 7927036
  writeRegister(0x41, 0x0E); // TX Buffer - 7927050 to 7927185
  writeRegister(0x44, 0x23); // TX Buffer - 7927198 to 7927333
  writeRegister(0x45, 0x11); // TX Buffer - 7927347 to 7927483
  writeRegister(0x46, 0x13); // TX Buffer - 7927495 to 7927632
  writeRegister(0x04, 0x07); // TX - 7927644 to 7927780
  writeRegister(0x00, 0xFF); // CS0 - 7934510 to 7934646
  writeRegister(0x01, 0xFF); // CS1 - 7934660 to 7934801
  writeRegister(0x16, 0xC0); // FIFO CTRL - 7934810 to 7934948
  writeRegister(0x40, 0x03); // TX Buffer - 7934959 to 7935094
  writeRegister(0x41, 0x0E); // TX Buffer - 7935106 to 7935241
  writeRegister(0x44, 0x23); // TX Buffer - 7935255 to 7935389
  writeRegister(0x45, 0x11); // TX Buffer - 7935403 to 7935539
  writeRegister(0x46, 0x13); // TX Buffer - 7935552 to 7935694
  writeRegister(0x04, 0x07); // TX - 7935701 to 7935836
  writeRegister(0x00, 0xFF); // CS0 - 7942482 to 7942621
  writeRegister(0x01, 0xFF); // CS1 - 7942632 to 7942773
  writeRegister(0x16, 0xC0); // FIFO CTRL - 7942785 to 7942920
  writeRegister(0x40, 0x03); // TX Buffer - 7942934 to 7943069
  writeRegister(0x41, 0x0E); // TX Buffer - 7943081 to 7943216
  writeRegister(0x44, 0x23); // TX Buffer - 7943230 to 7943364
  writeRegister(0x45, 0x11); // TX Buffer - 7943378 to 7943514
  writeRegister(0x46, 0x13); // TX Buffer - 7943527 to 7943663
  writeRegister(0x04, 0x07); // TX - 7943676 to 7943811
  writeRegister(0x00, 0xFF); // CS0 - 7950457 to 7950594
  writeRegister(0x01, 0xFF); // CS1 - 7950606 to 7950748
  writeRegister(0x16, 0xC0); // FIFO CTRL - 7950757 to 7950895
  writeRegister(0x40, 0x03); // TX Buffer - 7950905 to 7951039
  writeRegister(0x41, 0x0E); // TX Buffer - 7951053 to 7951189
  writeRegister(0x44, 0x23); // TX Buffer - 7951201 to 7951337
  writeRegister(0x45, 0x11); // TX Buffer - 7951350 to 7951484
  writeRegister(0x46, 0x13); // TX Buffer - 7951498 to 7951641
  writeRegister(0x04, 0x07); // TX - 7951647 to 7951781
  writeRegister(0x00, 0xFF); // CS0 - 7958513 to 7958650
  writeRegister(0x01, 0xFF); // CS1 - 7958663 to 7958804
  writeRegister(0x16, 0xC0); // FIFO CTRL - 7958817 to 7958951
  writeRegister(0x40, 0x03); // TX Buffer - 7958965 to 7959100
  writeRegister(0x41, 0x0E); // TX Buffer - 7959109 to 7959247
  writeRegister(0x44, 0x23); // TX Buffer - 7959258 to 7959397
  writeRegister(0x45, 0x11); // TX Buffer - 7959406 to 7959544
  writeRegister(0x46, 0x13); // TX Buffer - 7959554 to 7959694
  writeRegister(0x04, 0x07); // TX - 7959703 to 7959842
  writeRegister(0x00, 0xFF); // CS0 - 7966484 to 7966625
  writeRegister(0x01, 0xFF); // CS1 - 7966638 to 7966774
  writeRegister(0x16, 0xC0); // FIFO CTRL - 7966788 to 7966923
  writeRegister(0x40, 0x03); // TX Buffer - 7966937 to 7967070
  writeRegister(0x41, 0x0E); // TX Buffer - 7967084 to 7967219
  writeRegister(0x44, 0x23); // TX Buffer - 7967232 to 7967367
  writeRegister(0x45, 0x11); // TX Buffer - 7967381 to 7967517
  writeRegister(0x46, 0x13); // TX Buffer - 7967529 to 7967666
  writeRegister(0x04, 0x07); // TX - 7967678 to 7967814
  writeRegister(0x00, 0xFF); // CS0 - 7974459 to 7974597
  writeRegister(0x01, 0xFF); // CS1 - 7974609 to 7974749
  writeRegister(0x16, 0xC0); // FIFO CTRL - 7974763 to 7974898
  writeRegister(0x40, 0x03); // TX Buffer - 7974912 to 7975045
  writeRegister(0x41, 0x0E); // TX Buffer - 7975056 to 7975194
  writeRegister(0x44, 0x23); // TX Buffer - 7975204 to 7975342
  writeRegister(0x45, 0x11); // TX Buffer - 7975352 to 7975492
  writeRegister(0x46, 0x13); // TX Buffer - 7975501 to 7975641
  writeRegister(0x04, 0x07); // TX - 7975650 to 7975789
  writeRegister(0x00, 0xFF); // CS0 - 7982516 to 7982655
  writeRegister(0x01, 0xFF); // CS1 - 7982666 to 7982807
  writeRegister(0x16, 0xC0); // FIFO CTRL - 7982819 to 7982954
  writeRegister(0x40, 0x03); // TX Buffer - 7982968 to 7983103
  writeRegister(0x41, 0x0E); // TX Buffer - 7983115 to 7983250
  writeRegister(0x44, 0x23); // TX Buffer - 7983264 to 7983398
  writeRegister(0x45, 0x11); // TX Buffer - 7983412 to 7983548
  writeRegister(0x46, 0x13); // TX Buffer - 7983561 to 7983697
  writeRegister(0x04, 0x07); // TX - 7983710 to 7983845
  writeRegister(0x00, 0xFF); // CS0 - 7990487 to 7990628
  writeRegister(0x01, 0xFF); // CS1 - 7990640 to 7990785
  writeRegister(0x16, 0xC0); // FIFO CTRL - 7990791 to 7990929
  writeRegister(0x40, 0x03); // TX Buffer - 7990939 to 7991073
  writeRegister(0x41, 0x0E); // TX Buffer - 7991087 to 7991223
  writeRegister(0x44, 0x23); // TX Buffer - 7991235 to 7991371
  writeRegister(0x45, 0x11); // TX Buffer - 7991384 to 7991518
  writeRegister(0x46, 0x13); // TX Buffer - 7991532 to 7991675
  writeRegister(0x04, 0x07); // TX - 7991681 to 7991815
  writeRegister(0x00, 0xFF); // CS0 - 7998462 to 7998603
  writeRegister(0x01, 0xFF); // CS1 - 7998612 to 7998752
  writeRegister(0x16, 0xC0); // FIFO CTRL - 7998766 to 7998901
  writeRegister(0x40, 0x03); // TX Buffer - 7998914 to 7999048
  writeRegister(0x41, 0x0E); // TX Buffer - 7999062 to 7999198
  writeRegister(0x44, 0x23); // TX Buffer - 7999210 to 7999346
  writeRegister(0x45, 0x11); // TX Buffer - 7999359 to 7999493
  writeRegister(0x46, 0x13); // TX Buffer - 7999507 to 7999642
  writeRegister(0x04, 0x07); // TX - 7999656 to 7999790
  writeRegister(0x00, 0xFF); // CS0 - 8006510 to 8006651
  writeRegister(0x01, 0xFF); // CS1 - 8006660 to 8006800
  writeRegister(0x16, 0xC0); // FIFO CTRL - 8006814 to 8006949
  writeRegister(0x40, 0x03); // TX Buffer - 8006963 to 8007096
  writeRegister(0x41, 0x0E); // TX Buffer - 8007110 to 8007245
  writeRegister(0x44, 0x23); // TX Buffer - 8007258 to 8007393
  writeRegister(0x45, 0x11); // TX Buffer - 8007407 to 8007543
  writeRegister(0x46, 0x13); // TX Buffer - 8007555 to 8007692
  writeRegister(0x04, 0x07); // TX - 8007704 to 8007840
  writeRegister(0x00, 0xFF); // CS0 - 8014485 to 8014621
  writeRegister(0x01, 0xFF); // CS1 - 8014635 to 8014775
  writeRegister(0x16, 0xC0); // FIFO CTRL - 8014786 to 8014924
  writeRegister(0x40, 0x03); // TX Buffer - 8014934 to 8015075
  writeRegister(0x41, 0x0E); // TX Buffer - 8015082 to 8015220
  writeRegister(0x44, 0x23); // TX Buffer - 8015230 to 8015372
  writeRegister(0x45, 0x11); // TX Buffer - 8015378 to 8015521
  writeRegister(0x46, 0x13); // TX Buffer - 8015527 to 8015667
  writeRegister(0x04, 0x07); // TX - 8015676 to 8015816
  writeRegister(0x00, 0xFF); // CS0 - 8022457 to 8022596
  writeRegister(0x01, 0xFF); // CS1 - 8022607 to 8022748
  writeRegister(0x16, 0xC0); // FIFO CTRL - 8022761 to 8022895
  writeRegister(0x40, 0x03); // TX Buffer - 8022909 to 8023044
  writeRegister(0x41, 0x0E); // TX Buffer - 8023057 to 8023191
  writeRegister(0x44, 0x23); // TX Buffer - 8023205 to 8023341
  writeRegister(0x45, 0x11); // TX Buffer - 8023353 to 8023488
  writeRegister(0x46, 0x13); // TX Buffer - 8023502 to 8023637
  writeRegister(0x04, 0x07); // TX - 8023651 to 8023786
  writeRegister(0x00, 0xFF); // CS0 - 8030513 to 8030654
  writeRegister(0x01, 0xFF); // CS1 - 8030666 to 8030811
  writeRegister(0x16, 0xC0); // FIFO CTRL - 8030817 to 8030958
  writeRegister(0x40, 0x03); // TX Buffer - 8030965 to 8031099
  writeRegister(0x41, 0x0E); // TX Buffer - 8031113 to 8031249
  writeRegister(0x44, 0x23); // TX Buffer - 8031261 to 8031397
  writeRegister(0x45, 0x11); // TX Buffer - 8031410 to 8031544
  writeRegister(0x46, 0x13); // TX Buffer - 8031558 to 8031693
  writeRegister(0x04, 0x07); // TX - 8031707 to 8031841
  writeRegister(0x00, 0xFF); // CS0 - 8038488 to 8038632
  writeRegister(0x01, 0xFF); // CS1 - 8038638 to 8038778
  writeRegister(0x16, 0xC0); // FIFO CTRL - 8038792 to 8038928
  writeRegister(0x40, 0x03); // TX Buffer - 8038940 to 8039075
  writeRegister(0x41, 0x0E); // TX Buffer - 8039084 to 8039222
  writeRegister(0x44, 0x23); // TX Buffer - 8039233 to 8039372
  writeRegister(0x45, 0x11); // TX Buffer - 8039381 to 8039519
  writeRegister(0x46, 0x13); // TX Buffer - 8039530 to 8039668
  writeRegister(0x04, 0x07); // TX - 8039682 to 8039816
  writeRegister(0x00, 0xFF); // CS0 - 8046460 to 8046599
  writeRegister(0x01, 0xFF); // CS1 - 8046613 to 8046757
  writeRegister(0x16, 0xC0); // FIFO CTRL - 8046763 to 8046906
  writeRegister(0x40, 0x03); // TX Buffer - 8046912 to 8047047
  writeRegister(0x41, 0x0E); // TX Buffer - 8047059 to 8047194
  writeRegister(0x44, 0x23); // TX Buffer - 8047208 to 8047342
  writeRegister(0x45, 0x11); // TX Buffer - 8047356 to 8047492
  writeRegister(0x46, 0x13); // TX Buffer - 8047505 to 8047641
  writeRegister(0x04, 0x07); // TX - 8047654 to 8047789
  writeRegister(0x00, 0xFF); // CS0 - 8054519 to 8054657
  writeRegister(0x01, 0xFF); // CS1 - 8054669 to 8054809
  writeRegister(0x16, 0xC0); // FIFO CTRL - 8054820 to 8054958
  writeRegister(0x40, 0x03); // TX Buffer - 8054968 to 8055109
  writeRegister(0x41, 0x0E); // TX Buffer - 8055116 to 8055258
  writeRegister(0x44, 0x23); // TX Buffer - 8055264 to 8055406
  writeRegister(0x45, 0x11); // TX Buffer - 8055412 to 8055555
  writeRegister(0x46, 0x13); // TX Buffer - 8055561 to 8055704
  writeRegister(0x04, 0x07); // TX - 8055710 to 8055852
  writeRegister(0x00, 0xFF); // CS0 - 8062491 to 8062630
  writeRegister(0x01, 0xFF); // CS1 - 8062641 to 8062782
  writeRegister(0x16, 0xC0); // FIFO CTRL - 8062795 to 8062929
  writeRegister(0x40, 0x03); // TX Buffer - 8062943 to 8063078
  writeRegister(0x41, 0x0E); // TX Buffer - 8063091 to 8063225
  writeRegister(0x44, 0x23); // TX Buffer - 8063239 to 8063375
  writeRegister(0x45, 0x11); // TX Buffer - 8063387 to 8063522
  writeRegister(0x46, 0x13); // TX Buffer - 8063536 to 8063671
  writeRegister(0x04, 0x07); // TX - 8063685 to 8063819
  writeRegister(0x00, 0xFF); // CS0 - 8070466 to 8070603
  writeRegister(0x01, 0xFF); // CS1 - 8070616 to 8070757
  writeRegister(0x16, 0xC0); // FIFO CTRL - 8070766 to 8070904
  writeRegister(0x40, 0x03); // TX Buffer - 8070915 to 8071056
  writeRegister(0x41, 0x0E); // TX Buffer - 8071062 to 8071203
  writeRegister(0x44, 0x23); // TX Buffer - 8071211 to 8071353
  writeRegister(0x45, 0x11); // TX Buffer - 8071359 to 8071501
  writeRegister(0x46, 0x13); // TX Buffer - 8071507 to 8071650
  writeRegister(0x04, 0x07); // TX - 8071656 to 8071798
  writeRegister(0x00, 0xFF); // CS0 - 8078522 to 8078666
  writeRegister(0x01, 0xFF); // CS1 - 8078672 to 8078812
  writeRegister(0x16, 0xC0); // FIFO CTRL - 8078826 to 8078961
  writeRegister(0x40, 0x03); // TX Buffer - 8078974 to 8079108
  writeRegister(0x41, 0x0E); // TX Buffer - 8079118 to 8079258
  writeRegister(0x44, 0x23); // TX Buffer - 8079267 to 8079406
  writeRegister(0x45, 0x11); // TX Buffer - 8079415 to 8079553
  writeRegister(0x46, 0x13); // TX Buffer - 8079564 to 8079702
  writeRegister(0x04, 0x07); // TX - 8079713 to 8079850
  writeRegister(0x00, 0xFF); // CS0 - 8086494 to 8086633
  writeRegister(0x01, 0xFF); // CS1 - 8086647 to 8086785
  writeRegister(0x16, 0xC0); // FIFO CTRL - 8086797 to 8086932
  writeRegister(0x40, 0x03); // TX Buffer - 8086946 to 8087081
  writeRegister(0x41, 0x0E); // TX Buffer - 8087093 to 8087228
  writeRegister(0x44, 0x23); // TX Buffer - 8087242 to 8087376
  writeRegister(0x45, 0x11); // TX Buffer - 8087390 to 8087526
  writeRegister(0x46, 0x13); // TX Buffer - 8087539 to 8087675
  writeRegister(0x04, 0x07); // TX - 8087688 to 8087823
  writeRegister(0x00, 0xFF); // CS0 - 8094469 to 8094612
  writeRegister(0x01, 0xFF); // CS1 - 8094619 to 8094760
  writeRegister(0x16, 0xC0); // FIFO CTRL - 8094772 to 8094907
  writeRegister(0x40, 0x03); // TX Buffer - 8094921 to 8095056
  writeRegister(0x41, 0x0E); // TX Buffer - 8095065 to 8095203
  writeRegister(0x44, 0x23); // TX Buffer - 8095213 to 8095351
  writeRegister(0x45, 0x11); // TX Buffer - 8095362 to 8095501
  writeRegister(0x46, 0x13); // TX Buffer - 8095510 to 8095650
  writeRegister(0x04, 0x07); // TX - 8095659 to 8095798
  writeRegister(0x00, 0xFF); // CS0 - 8102525 to 8102666
  writeRegister(0x01, 0xFF); // CS1 - 8102675 to 8102816
  writeRegister(0x16, 0xC0); // FIFO CTRL - 8102829 to 8102963
  writeRegister(0x40, 0x03); // TX Buffer - 8102977 to 8103112
  writeRegister(0x41, 0x0E); // TX Buffer - 8103125 to 8103259
  writeRegister(0x44, 0x23); // TX Buffer - 8103273 to 8103409
  writeRegister(0x45, 0x11); // TX Buffer - 8103421 to 8103556
  writeRegister(0x46, 0x13); // TX Buffer - 8103570 to 8103705
  writeRegister(0x04, 0x07); // TX - 8103719 to 8103853
  writeRegister(0x00, 0xFF); // CS0 - 8110500 to 8110636
  writeRegister(0x01, 0xFF); // CS1 - 8110650 to 8110791
  writeRegister(0x16, 0xC0); // FIFO CTRL - 8110800 to 8110938
  writeRegister(0x40, 0x03); // TX Buffer - 8110949 to 8111082
  writeRegister(0x41, 0x0E); // TX Buffer - 8111096 to 8111231
  writeRegister(0x44, 0x23); // TX Buffer - 8111245 to 8111379
  writeRegister(0x45, 0x11); // TX Buffer - 8111393 to 8111529
  writeRegister(0x46, 0x13); // TX Buffer - 8111541 to 8111684
  writeRegister(0x04, 0x07); // TX - 8111690 to 8111826
  writeRegister(0x00, 0xFF); // CS0 - 8118471 to 8118612
  writeRegister(0x01, 0xFF); // CS1 - 8118621 to 8118761
  writeRegister(0x16, 0xC0); // FIFO CTRL - 8118775 to 8118910
  writeRegister(0x40, 0x03); // TX Buffer - 8118924 to 8119057
  writeRegister(0x41, 0x0E); // TX Buffer - 8119071 to 8119206
  writeRegister(0x44, 0x23); // TX Buffer - 8119220 to 8119354
  writeRegister(0x45, 0x11); // TX Buffer - 8119368 to 8119504
  writeRegister(0x46, 0x13); // TX Buffer - 8119516 to 8119653
  writeRegister(0x04, 0x07); // TX - 8119665 to 8119801
  writeRegister(0x00, 0xFF); // CS0 - 8126528 to 8126667
  writeRegister(0x01, 0xFF); // CS1 - 8126681 to 8126819
  writeRegister(0x16, 0xC0); // FIFO CTRL - 8126831 to 8126966
  writeRegister(0x40, 0x03); // TX Buffer - 8126980 to 8127115
  writeRegister(0x41, 0x0E); // TX Buffer - 8127127 to 8127262
  writeRegister(0x44, 0x23); // TX Buffer - 8127276 to 8127412
  writeRegister(0x45, 0x11); // TX Buffer - 8127424 to 8127560
  writeRegister(0x46, 0x13); // TX Buffer - 8127573 to 8127709
  writeRegister(0x04, 0x07); // TX - 8127722 to 8127857
  writeRegister(0x00, 0xFF); // CS0 - 8134503 to 8134640
  writeRegister(0x01, 0xFF); // CS1 - 8134653 to 8134794
  writeRegister(0x16, 0xC0); // FIFO CTRL - 8134806 to 8134941
  writeRegister(0x40, 0x03); // TX Buffer - 8134955 to 8135090
  writeRegister(0x41, 0x0E); // TX Buffer - 8135099 to 8135237
  writeRegister(0x44, 0x23); // TX Buffer - 8135247 to 8135385
  writeRegister(0x45, 0x11); // TX Buffer - 8135396 to 8135535
  writeRegister(0x46, 0x13); // TX Buffer - 8135544 to 8135684
  writeRegister(0x04, 0x07); // TX - 8135693 to 8135832
  writeRegister(0x00, 0xFF); // CS0 - 8142474 to 8142615
  writeRegister(0x01, 0xFF); // CS1 - 8142628 to 8142764
  writeRegister(0x16, 0xC0); // FIFO CTRL - 8142778 to 8142913
  writeRegister(0x40, 0x03); // TX Buffer - 8142926 to 8143060
  writeRegister(0x41, 0x0E); // TX Buffer - 8143074 to 8143209
  writeRegister(0x44, 0x23); // TX Buffer - 8143222 to 8143358
  writeRegister(0x45, 0x11); // TX Buffer - 8143371 to 8143505
  writeRegister(0x46, 0x13); // TX Buffer - 8143519 to 8143654
  writeRegister(0x04, 0x07); // TX - 8143668 to 8143802
  writeRegister(0x00, 0xFF); // CS0 - 8150530 to 8150670
  writeRegister(0x01, 0xFF); // CS1 - 8150684 to 8150828
  writeRegister(0x16, 0xC0); // FIFO CTRL - 8150834 to 8150972
  writeRegister(0x40, 0x03); // TX Buffer - 8150983 to 8151116
  writeRegister(0x41, 0x0E); // TX Buffer - 8151130 to 8151265
  writeRegister(0x44, 0x23); // TX Buffer - 8151279 to 8151413
  writeRegister(0x45, 0x11); // TX Buffer - 8151427 to 8151563
  writeRegister(0x46, 0x13); // TX Buffer - 8151575 to 8151718
  writeRegister(0x04, 0x07); // TX - 8151724 to 8151860
  writeRegister(0x00, 0xFF); // CS0 - 8158505 to 8158645
  writeRegister(0x01, 0xFF); // CS1 - 8158655 to 8158795
  writeRegister(0x16, 0xC0); // FIFO CTRL - 8158809 to 8158944
  writeRegister(0x40, 0x03); // TX Buffer - 8158958 to 8159091
  writeRegister(0x41, 0x0E); // TX Buffer - 8159105 to 8159240
  writeRegister(0x44, 0x23); // TX Buffer - 8159254 to 8159388
  writeRegister(0x45, 0x11); // TX Buffer - 8159402 to 8159538
  writeRegister(0x46, 0x13); // TX Buffer - 8159550 to 8159687
  writeRegister(0x04, 0x07); // TX - 8159699 to 8159835
  writeRegister(0x00, 0xFF); // CS0 - 8166477 to 8166618
  writeRegister(0x01, 0xFF); // CS1 - 8166630 to 8166774
  writeRegister(0x16, 0xC0); // FIFO CTRL - 8166781 to 8166919
  writeRegister(0x40, 0x03); // TX Buffer - 8166929 to 8167064
  writeRegister(0x41, 0x0E); // TX Buffer - 8167077 to 8167211
  writeRegister(0x44, 0x23); // TX Buffer - 8167225 to 8167361
  writeRegister(0x45, 0x11); // TX Buffer - 8167374 to 8167508
  writeRegister(0x46, 0x13); // TX Buffer - 8167522 to 8167665
  writeRegister(0x04, 0x07); // TX - 8167671 to 8167805
  writeRegister(0x00, 0xFF); // CS0 - 8174537 to 8174674
  writeRegister(0x01, 0xFF); // CS1 - 8174687 to 8174828
  writeRegister(0x16, 0xC0); // FIFO CTRL - 8174837 to 8174975
  writeRegister(0x40, 0x03); // TX Buffer - 8174985 to 8175127
  writeRegister(0x41, 0x0E); // TX Buffer - 8175133 to 8175271
  writeRegister(0x44, 0x23); // TX Buffer - 8175281 to 8175424
  writeRegister(0x45, 0x11); // TX Buffer - 8175430 to 8175572
  writeRegister(0x46, 0x13); // TX Buffer - 8175578 to 8175718
  writeRegister(0x04, 0x07); // TX - 8175727 to 8175869
  writeRegister(0x00, 0xFF); // CS0 - 8182508 to 8182649
  writeRegister(0x01, 0xFF); // CS1 - 8182662 to 8182798
  writeRegister(0x16, 0xC0); // FIFO CTRL - 8182812 to 8182947
  writeRegister(0x40, 0x03); // TX Buffer - 8182960 to 8183094
  writeRegister(0x41, 0x0E); // TX Buffer - 8183108 to 8183243
  writeRegister(0x44, 0x23); // TX Buffer - 8183256 to 8183391
  writeRegister(0x45, 0x11); // TX Buffer - 8183405 to 8183541
  writeRegister(0x46, 0x13); // TX Buffer - 8183553 to 8183688
  writeRegister(0x04, 0x07); // TX - 8183702 to 8183836
  writeRegister(0x00, 0xFF); // CS0 - 8190483 to 8190619
  writeRegister(0x01, 0xFF); // CS1 - 8190633 to 8190773
  writeRegister(0x16, 0xC0); // FIFO CTRL - 8190784 to 8190922
  writeRegister(0x40, 0x03); // TX Buffer - 8190932 to 8191073
  writeRegister(0x41, 0x0E); // TX Buffer - 8191079 to 8191218
  writeRegister(0x44, 0x23); // TX Buffer - 8191228 to 8191370
  writeRegister(0x45, 0x11); // TX Buffer - 8191376 to 8191517
  writeRegister(0x46, 0x13); // TX Buffer - 8191525 to 8191663
  writeRegister(0x04, 0x07); // TX - 8191674 to 8191815
  writeRegister(0x00, 0xFF); // CS0 - 8198539 to 8198683
  writeRegister(0x01, 0xFF); // CS1 - 8198689 to 8198829
  writeRegister(0x16, 0xC0); // FIFO CTRL - 8198843 to 8198978
  writeRegister(0x40, 0x03); // TX Buffer - 8198992 to 8199125
  writeRegister(0x41, 0x0E); // TX Buffer - 8199136 to 8199274
  writeRegister(0x44, 0x23); // TX Buffer - 8199284 to 8199422
  writeRegister(0x45, 0x11); // TX Buffer - 8199433 to 8199572
  writeRegister(0x46, 0x13); // TX Buffer - 8199581 to 8199721
  writeRegister(0x04, 0x07); // TX - 8199733 to 8199869
  writeRegister(0x00, 0xFF); // CS0 - 8206511 to 8206652
  writeRegister(0x01, 0xFF); // CS1 - 8206664 to 8206808
  writeRegister(0x16, 0xC0); // FIFO CTRL - 8206815 to 8206953
  writeRegister(0x40, 0x03); // TX Buffer - 8206963 to 8207098
  writeRegister(0x41, 0x0E); // TX Buffer - 8207111 to 8207245
  writeRegister(0x44, 0x23); // TX Buffer - 8207259 to 8207395
  writeRegister(0x45, 0x11); // TX Buffer - 8207408 to 8207542
  writeRegister(0x46, 0x13); // TX Buffer - 8207556 to 8207691
  writeRegister(0x04, 0x07); // TX - 8207705 to 8207839
  writeRegister(0x00, 0xFF); // CS0 - 8214486 to 8214630
  writeRegister(0x01, 0xFF); // CS1 - 8214636 to 8214777
  writeRegister(0x16, 0xC0); // FIFO CTRL - 8214790 to 8214924
  writeRegister(0x40, 0x03); // TX Buffer - 8214938 to 8215073
  writeRegister(0x41, 0x0E); // TX Buffer - 8215082 to 8215220
  writeRegister(0x44, 0x23); // TX Buffer - 8215231 to 8215370
  writeRegister(0x45, 0x11); // TX Buffer - 8215379 to 8215517
  writeRegister(0x46, 0x13); // TX Buffer - 8215528 to 8215666
  writeRegister(0x04, 0x07); // TX - 8215680 to 8215814
  writeRegister(0x00, 0xFF); // CS0 - 8222542 to 8222683
  writeRegister(0x01, 0xFF); // CS1 - 8222692 to 8222832
  writeRegister(0x16, 0xC0); // FIFO CTRL - 8222846 to 8222981
  writeRegister(0x40, 0x03); // TX Buffer - 8222994 to 8223128
  writeRegister(0x41, 0x0E); // TX Buffer - 8223142 to 8223277
  writeRegister(0x44, 0x23); // TX Buffer - 8223290 to 8223425
  writeRegister(0x45, 0x11); // TX Buffer - 8223439 to 8223575
  writeRegister(0x46, 0x13); // TX Buffer - 8223587 to 8223722
  writeRegister(0x04, 0x07); // TX - 8223736 to 8223870
  writeRegister(0x00, 0xFF); // CS0 - 8230517 to 8230653
  writeRegister(0x01, 0xFF); // CS1 - 8230667 to 8230807
  writeRegister(0x16, 0xC0); // FIFO CTRL - 8230818 to 8230956
  writeRegister(0x40, 0x03); // TX Buffer - 8230966 to 8231107
  writeRegister(0x41, 0x0E); // TX Buffer - 8231113 to 8231252
  writeRegister(0x44, 0x23); // TX Buffer - 8231262 to 8231404
  writeRegister(0x45, 0x11); // TX Buffer - 8231410 to 8231553
  writeRegister(0x46, 0x13); // TX Buffer - 8231559 to 8231697
  writeRegister(0x04, 0x07); // TX - 8231708 to 8231849
  writeRegister(0x00, 0xFF); // CS0 - 8238489 to 8238628
  writeRegister(0x01, 0xFF); // CS1 - 8238639 to 8238780
  writeRegister(0x16, 0xC0); // FIFO CTRL - 8238793 to 8238927
  writeRegister(0x40, 0x03); // TX Buffer - 8238941 to 8239076
  writeRegister(0x41, 0x0E); // TX Buffer - 8239088 to 8239223
  writeRegister(0x44, 0x23); // TX Buffer - 8239237 to 8239373
  writeRegister(0x45, 0x11); // TX Buffer - 8239385 to 8239520
  writeRegister(0x46, 0x13); // TX Buffer - 8239534 to 8239670
  writeRegister(0x04, 0x07); // TX - 8239683 to 8239818
  writeRegister(0x00, 0xFF); // CS0 - 8246545 to 8246686
  writeRegister(0x01, 0xFF); // CS1 - 8246698 to 8246841
  writeRegister(0x16, 0xC0); // FIFO CTRL - 8246849 to 8246991
  writeRegister(0x40, 0x03); // TX Buffer - 8246997 to 8247132
  writeRegister(0x41, 0x0E); // TX Buffer - 8247145 to 8247279
  writeRegister(0x44, 0x23); // TX Buffer - 8247293 to 8247429
  writeRegister(0x45, 0x11); // TX Buffer - 8247442 to 8247576
  writeRegister(0x46, 0x13); // TX Buffer - 8247590 to 8247725
  writeRegister(0x04, 0x07); // TX - 8247739 to 8247873
  writeRegister(0x00, 0xFF); // CS0 - 8254520 to 8254664
  writeRegister(0x01, 0xFF); // CS1 - 8254670 to 8254811
  writeRegister(0x16, 0xC0); // FIFO CTRL - 8254824 to 8254958
  writeRegister(0x40, 0x03); // TX Buffer - 8254972 to 8255107
  writeRegister(0x41, 0x0E); // TX Buffer - 8255116 to 8255254
  writeRegister(0x44, 0x23); // TX Buffer - 8255265 to 8255404
  writeRegister(0x45, 0x11); // TX Buffer - 8255413 to 8255551
  writeRegister(0x46, 0x13); // TX Buffer - 8255562 to 8255700
  writeRegister(0x04, 0x07); // TX - 8255714 to 8255848
  writeRegister(0x00, 0xFF); // CS0 - 8262492 to 8262631
  writeRegister(0x01, 0xFF); // CS1 - 8262645 to 8262789
  writeRegister(0x16, 0xC0); // FIFO CTRL - 8262795 to 8262936
  writeRegister(0x40, 0x03); // TX Buffer - 8262944 to 8263079
  writeRegister(0x41, 0x0E); // TX Buffer - 8263091 to 8263226
  writeRegister(0x44, 0x23); // TX Buffer - 8263240 to 8263374
  writeRegister(0x45, 0x11); // TX Buffer - 8263388 to 8263524
  writeRegister(0x46, 0x13); // TX Buffer - 8263537 to 8263673
  writeRegister(0x04, 0x07); // TX - 8263686 to 8263821
  writeRegister(0x00, 0xFF); // CS0 - 8270551 to 8270687
  writeRegister(0x01, 0xFF); // CS1 - 8270701 to 8270841
  writeRegister(0x16, 0xC0); // FIFO CTRL - 8270852 to 8270990
  writeRegister(0x40, 0x03); // TX Buffer - 8271000 to 8271141
  writeRegister(0x41, 0x0E); // TX Buffer - 8271148 to 8271290
  writeRegister(0x44, 0x23); // TX Buffer - 8271296 to 8271438
  writeRegister(0x45, 0x11); // TX Buffer - 8271444 to 8271587
  writeRegister(0x46, 0x13); // TX Buffer - 8271593 to 8271734
  writeRegister(0x04, 0x07); // TX - 8271742 to 8271883
  writeRegister(0x00, 0xFF); // CS0 - 8278523 to 8278662
  writeRegister(0x01, 0xFF); // CS1 - 8278673 to 8278814
  writeRegister(0x16, 0xC0); // FIFO CTRL - 8278827 to 8278961
  writeRegister(0x40, 0x03); // TX Buffer - 8278975 to 8279110
  writeRegister(0x41, 0x0E); // TX Buffer - 8279122 to 8279257
  writeRegister(0x44, 0x23); // TX Buffer - 8279271 to 8279407
  writeRegister(0x45, 0x11); // TX Buffer - 8279419 to 8279554
  writeRegister(0x46, 0x13); // TX Buffer - 8279568 to 8279704
  writeRegister(0x04, 0x07); // TX - 8279717 to 8279852
  writeRegister(0x00, 0xFF); // CS0 - 8286498 to 8286635
  writeRegister(0x01, 0xFF); // CS1 - 8286648 to 8286789
  writeRegister(0x16, 0xC0); // FIFO CTRL - 8286798 to 8286936
  writeRegister(0x40, 0x03); // TX Buffer - 8286947 to 8287088
  writeRegister(0x41, 0x0E); // TX Buffer - 8287094 to 8287235
  writeRegister(0x44, 0x23); // TX Buffer - 8287242 to 8287385
  writeRegister(0x45, 0x11); // TX Buffer - 8287391 to 8287533
  writeRegister(0x46, 0x13); // TX Buffer - 8287539 to 8287682
  writeRegister(0x04, 0x07); // TX - 8287688 to 8287830
  writeRegister(0x00, 0xFF); // CS0 - 8294554 to 8294698
  writeRegister(0x01, 0xFF); // CS1 - 8294704 to 8294844
  writeRegister(0x16, 0xC0); // FIFO CTRL - 8294858 to 8294994
  writeRegister(0x40, 0x03); // TX Buffer - 8295006 to 8295141
  writeRegister(0x41, 0x0E); // TX Buffer - 8295150 to 8295288
  writeRegister(0x44, 0x23); // TX Buffer - 8295299 to 8295438
  writeRegister(0x45, 0x11); // TX Buffer - 8295447 to 8295585
  writeRegister(0x46, 0x13); // TX Buffer - 8295596 to 8295734
  writeRegister(0x04, 0x07); // TX - 8295745 to 8295882
  writeRegister(0x00, 0xFF); // CS0 - 8302526 to 8302665
  writeRegister(0x01, 0xFF); // CS1 - 8302679 to 8302817
  writeRegister(0x16, 0xC0); // FIFO CTRL - 8302829 to 8302964
  writeRegister(0x40, 0x03); // TX Buffer - 8302978 to 8303113
  writeRegister(0x41, 0x0E); // TX Buffer - 8303125 to 8303260
  writeRegister(0x44, 0x23); // TX Buffer - 8303274 to 8303408
  writeRegister(0x45, 0x11); // TX Buffer - 8303422 to 8303558
  writeRegister(0x46, 0x13); // TX Buffer - 8303571 to 8303707
  writeRegister(0x04, 0x07); // TX - 8303720 to 8303855
  writeRegister(0x00, 0xFF); // CS0 - 8310493 to 8310630
  writeRegister(0x01, 0xFF); // CS1 - 8310642 to 8310784
  writeRegister(0x16, 0xC0); // FIFO CTRL - 8310796 to 8310931
  writeRegister(0x40, 0x03); // TX Buffer - 8310945 to 8311078
  writeRegister(0x41, 0x0E); // TX Buffer - 8311089 to 8311227
  writeRegister(0x44, 0x23); // TX Buffer - 8311237 to 8311375
  writeRegister(0x45, 0x11); // TX Buffer - 8311386 to 8311525
  writeRegister(0x46, 0x13); // TX Buffer - 8311534 to 8311674
  writeRegister(0x04, 0x07); // TX - 8311683 to 8311822
  writeRegister(0x00, 0xFF); // CS0 - 8318549 to 8318688
  writeRegister(0x01, 0xFF); // CS1 - 8318699 to 8318840
  writeRegister(0x16, 0xC0); // FIFO CTRL - 8318853 to 8318987
  writeRegister(0x40, 0x03); // TX Buffer - 8319001 to 8319136
  writeRegister(0x41, 0x0E); // TX Buffer - 8319148 to 8319283
  writeRegister(0x44, 0x23); // TX Buffer - 8319297 to 8319433
  writeRegister(0x45, 0x11); // TX Buffer - 8319445 to 8319580
  writeRegister(0x46, 0x13); // TX Buffer - 8319594 to 8319730
  writeRegister(0x04, 0x07); // TX - 8319743 to 8319878
  writeRegister(0x00, 0xFF); // CS0 - 8326520 to 8326661
  writeRegister(0x01, 0xFF); // CS1 - 8326674 to 8326818
  writeRegister(0x16, 0xC0); // FIFO CTRL - 8326824 to 8326962
  writeRegister(0x40, 0x03); // TX Buffer - 8326973 to 8327106
  writeRegister(0x41, 0x0E); // TX Buffer - 8327120 to 8327255
  writeRegister(0x44, 0x23); // TX Buffer - 8327268 to 8327403
  writeRegister(0x45, 0x11); // TX Buffer - 8327417 to 8327553
  writeRegister(0x46, 0x13); // TX Buffer - 8327565 to 8327708
  writeRegister(0x04, 0x07); // TX - 8327714 to 8327850
  writeRegister(0x00, 0xFF); // CS0 - 8334495 to 8334636
  writeRegister(0x01, 0xFF); // CS1 - 8334645 to 8334785
  writeRegister(0x16, 0xC0); // FIFO CTRL - 8334799 to 8334934
  writeRegister(0x40, 0x03); // TX Buffer - 8334947 to 8335081
  writeRegister(0x41, 0x0E); // TX Buffer - 8335095 to 8335230
  writeRegister(0x44, 0x23); // TX Buffer - 8335243 to 8335378
  writeRegister(0x45, 0x11); // TX Buffer - 8335392 to 8335528
  writeRegister(0x46, 0x13); // TX Buffer - 8335540 to 8335677
  writeRegister(0x04, 0x07); // TX - 8335689 to 8335823
  writeRegister(0x00, 0xFF); // CS0 - 8342552 to 8342691
  writeRegister(0x01, 0xFF); // CS1 - 8342705 to 8342843
  writeRegister(0x16, 0xC0); // FIFO CTRL - 8342855 to 8342990
  writeRegister(0x40, 0x03); // TX Buffer - 8343004 to 8343137
  writeRegister(0x41, 0x0E); // TX Buffer - 8343151 to 8343286
  writeRegister(0x44, 0x23); // TX Buffer - 8343300 to 8343434
  writeRegister(0x45, 0x11); // TX Buffer - 8343448 to 8343584
  writeRegister(0x46, 0x13); // TX Buffer - 8343597 to 8343733
  writeRegister(0x04, 0x07); // TX - 8343746 to 8343881
  writeRegister(0x00, 0xFF); // CS0 - 8350527 to 8350664
  writeRegister(0x01, 0xFF); // CS1 - 8350676 to 8350818
  writeRegister(0x16, 0xC0); // FIFO CTRL - 8350827 to 8350965
  writeRegister(0x40, 0x03); // TX Buffer - 8350975 to 8351115
  writeRegister(0x41, 0x0E); // TX Buffer - 8351123 to 8351261
  writeRegister(0x44, 0x23); // TX Buffer - 8351271 to 8351413
  writeRegister(0x45, 0x11); // TX Buffer - 8351420 to 8351562
  writeRegister(0x46, 0x13); // TX Buffer - 8351568 to 8351708
  writeRegister(0x04, 0x07); // TX - 8351717 to 8351859
  writeRegister(0x00, 0xFF); // CS0 - 8358498 to 8358639
  writeRegister(0x01, 0xFF); // CS1 - 8358651 to 8358788
  writeRegister(0x16, 0xC0); // FIFO CTRL - 8358802 to 8358938
  writeRegister(0x40, 0x03); // TX Buffer - 8358950 to 8359085
  writeRegister(0x41, 0x0E); // TX Buffer - 8359098 to 8359232
  writeRegister(0x44, 0x23); // TX Buffer - 8359246 to 8359382
  writeRegister(0x45, 0x11); // TX Buffer - 8359395 to 8359529
  writeRegister(0x46, 0x13); // TX Buffer - 8359543 to 8359678
  writeRegister(0x04, 0x07); // TX - 8359692 to 8359826
  writeRegister(0x00, 0xFF); // CS0 - 8366554 to 8366695
  writeRegister(0x01, 0xFF); // CS1 - 8366708 to 8366852
  writeRegister(0x16, 0xC0); // FIFO CTRL - 8366858 to 8366996
  writeRegister(0x40, 0x03); // TX Buffer - 8367007 to 8367140
  writeRegister(0x41, 0x0E); // TX Buffer - 8367154 to 8367289
  writeRegister(0x44, 0x23); // TX Buffer - 8367302 to 8367437
  writeRegister(0x45, 0x11); // TX Buffer - 8367451 to 8367587
  writeRegister(0x46, 0x13); // TX Buffer - 8367599 to 8367736
  writeRegister(0x04, 0x07); // TX - 8367748 to 8367884
  writeRegister(0x00, 0xFF); // CS0 - 8374529 to 8374673
  writeRegister(0x01, 0xFF); // CS1 - 8374679 to 8374819
  writeRegister(0x16, 0xC0); // FIFO CTRL - 8374833 to 8374968
  writeRegister(0x40, 0x03); // TX Buffer - 8374982 to 8375115
  writeRegister(0x41, 0x0E); // TX Buffer - 8375126 to 8375264
  writeRegister(0x44, 0x23); // TX Buffer - 8375274 to 8375412
  writeRegister(0x45, 0x11); // TX Buffer - 8375422 to 8375562
  writeRegister(0x46, 0x13); // TX Buffer - 8375571 to 8375711
  writeRegister(0x04, 0x07); // TX - 8375723 to 8375857
  writeRegister(0x00, 0xFF); // CS0 - 8382501 to 8382640
  writeRegister(0x01, 0xFF); // CS1 - 8382654 to 8382798
  writeRegister(0x16, 0xC0); // FIFO CTRL - 8382805 to 8382943
  writeRegister(0x40, 0x03); // TX Buffer - 8382953 to 8383088
  writeRegister(0x41, 0x0E); // TX Buffer - 8383101 to 8383235
  writeRegister(0x44, 0x23); // TX Buffer - 8383249 to 8383385
  writeRegister(0x45, 0x11); // TX Buffer - 8383397 to 8383532
  writeRegister(0x46, 0x13); // TX Buffer - 8383546 to 8383681
  writeRegister(0x04, 0x07); // TX - 8383695 to 8383830
  writeRegister(0x00, 0xFF); // CS0 - 8390561 to 8390698
  writeRegister(0x01, 0xFF); // CS1 - 8390710 to 8390852
  writeRegister(0x16, 0xC0); // FIFO CTRL - 8390861 to 8390999
  writeRegister(0x40, 0x03); // TX Buffer - 8391009 to 8391149
  writeRegister(0x41, 0x0E); // TX Buffer - 8391157 to 8391295
  writeRegister(0x44, 0x23); // TX Buffer - 8391305 to 8391447
  writeRegister(0x45, 0x11); // TX Buffer - 8391454 to 8391596
  writeRegister(0x46, 0x13); // TX Buffer - 8391602 to 8391742
  writeRegister(0x04, 0x07); // TX - 8391751 to 8391893
  writeRegister(0x00, 0xFF); // CS0 - 8398532 to 8398673
  writeRegister(0x01, 0xFF); // CS1 - 8398682 to 8398822
  writeRegister(0x16, 0xC0); // FIFO CTRL - 8398836 to 8398971
  writeRegister(0x40, 0x03); // TX Buffer - 8398984 to 8399119
  writeRegister(0x41, 0x0E); // TX Buffer - 8399132 to 8399266
  writeRegister(0x44, 0x23); // TX Buffer - 8399280 to 8399416
  writeRegister(0x45, 0x11); // TX Buffer - 8399429 to 8399563
  writeRegister(0x46, 0x13); // TX Buffer - 8399577 to 8399712
  writeRegister(0x04, 0x07); // TX - 8399726 to 8399860
  writeRegister(0x00, 0xFF); // CS0 - 8406507 to 8406643
  writeRegister(0x01, 0xFF); // CS1 - 8406657 to 8406797
  writeRegister(0x16, 0xC0); // FIFO CTRL - 8406807 to 8406947
  writeRegister(0x40, 0x03); // TX Buffer - 8406956 to 8407097
  writeRegister(0x41, 0x0E); // TX Buffer - 8407103 to 8407241
  writeRegister(0x44, 0x23); // TX Buffer - 8407252 to 8407394
  writeRegister(0x45, 0x11); // TX Buffer - 8407400 to 8407542
  writeRegister(0x46, 0x13); // TX Buffer - 8407549 to 8407687
  writeRegister(0x04, 0x07); // TX - 8407698 to 8407839
  writeRegister(0x00, 0xFF); // CS0 - 8414563 to 8414707
  writeRegister(0x01, 0xFF); // CS1 - 8414713 to 8414853
  writeRegister(0x16, 0xC0); // FIFO CTRL - 8414867 to 8415002
  writeRegister(0x40, 0x03); // TX Buffer - 8415016 to 8415149
  writeRegister(0x41, 0x0E); // TX Buffer - 8415160 to 8415298
  writeRegister(0x44, 0x23); // TX Buffer - 8415308 to 8415446
  writeRegister(0x45, 0x11); // TX Buffer - 8415456 to 8415596
  writeRegister(0x46, 0x13); // TX Buffer - 8415605 to 8415745
  writeRegister(0x04, 0x07); // TX - 8415757 to 8415893
  writeRegister(0x00, 0xFF); // CS0 - 8422535 to 8422676
  writeRegister(0x01, 0xFF); // CS1 - 8422688 to 8422832
  writeRegister(0x16, 0xC0); // FIFO CTRL - 8422839 to 8422981
  writeRegister(0x40, 0x03); // TX Buffer - 8422987 to 8423122
  writeRegister(0x41, 0x0E); // TX Buffer - 8423135 to 8423269
  writeRegister(0x44, 0x23); // TX Buffer - 8423283 to 8423419
  writeRegister(0x45, 0x11); // TX Buffer - 8423431 to 8423566
  writeRegister(0x46, 0x13); // TX Buffer - 8423580 to 8423715
  writeRegister(0x04, 0x07); // TX - 8423729 to 8423863
  writeRegister(0x00, 0xFF); // CS0 - 8430510 to 8430652
  writeRegister(0x01, 0xFF); // CS1 - 8430660 to 8430801
  writeRegister(0x16, 0xC0); // FIFO CTRL - 8430814 to 8430948
  writeRegister(0x40, 0x03); // TX Buffer - 8430962 to 8431097
  writeRegister(0x41, 0x0E); // TX Buffer - 8431106 to 8431244
  writeRegister(0x44, 0x23); // TX Buffer - 8431255 to 8431394
  writeRegister(0x45, 0x11); // TX Buffer - 8431403 to 8431541
  writeRegister(0x46, 0x13); // TX Buffer - 8431551 to 8431690
  writeRegister(0x04, 0x07); // TX - 8431704 to 8431839
  writeRegister(0x00, 0xFF); // CS0 - 8438481 to 8438622
  writeRegister(0x01, 0xFF); // CS1 - 8438635 to 8438779
  writeRegister(0x16, 0xC0); // FIFO CTRL - 8438785 to 8438926
  writeRegister(0x40, 0x03); // TX Buffer - 8438934 to 8439067
  writeRegister(0x41, 0x0E); // TX Buffer - 8439081 to 8439216
  writeRegister(0x44, 0x23); // TX Buffer - 8439230 to 8439364
  writeRegister(0x45, 0x11); // TX Buffer - 8439378 to 8439514
  writeRegister(0x46, 0x13); // TX Buffer - 8439526 to 8439663
  writeRegister(0x04, 0x07); // TX - 8439675 to 8439811
  writeRegister(0x00, 0xFF); // CS0 - 8446541 to 8446677
  writeRegister(0x01, 0xFF); // CS1 - 8446691 to 8446831
  writeRegister(0x16, 0xC0); // FIFO CTRL - 8446841 to 8446980
  writeRegister(0x40, 0x03); // TX Buffer - 8446990 to 8447131
  writeRegister(0x41, 0x0E); // TX Buffer - 8447137 to 8447278
  writeRegister(0x44, 0x23); // TX Buffer - 8447286 to 8447428
  writeRegister(0x45, 0x11); // TX Buffer - 8447434 to 8447576
  writeRegister(0x46, 0x13); // TX Buffer - 8447583 to 8447725
  writeRegister(0x04, 0x07); // TX - 8447732 to 8447873
  writeRegister(0x00, 0xFF); // CS0 - 8454513 to 8454652
  writeRegister(0x01, 0xFF); // CS1 - 8454663 to 8454804
  writeRegister(0x16, 0xC0); // FIFO CTRL - 8454816 to 8454951
  writeRegister(0x40, 0x03); // TX Buffer - 8454965 to 8455100
  writeRegister(0x41, 0x0E); // TX Buffer - 8455112 to 8455247
  writeRegister(0x44, 0x23); // TX Buffer - 8455261 to 8455395
  writeRegister(0x45, 0x11); // TX Buffer - 8455409 to 8455545
  writeRegister(0x46, 0x13); // TX Buffer - 8455558 to 8455694
  writeRegister(0x04, 0x07); // TX - 8455707 to 8455842
  writeRegister(0x00, 0xFF); // CS0 - 8462488 to 8462625
  writeRegister(0x01, 0xFF); // CS1 - 8462638 to 8462779
  writeRegister(0x16, 0xC0); // FIFO CTRL - 8462788 to 8462926
  writeRegister(0x40, 0x03); // TX Buffer - 8462936 to 8463078
  writeRegister(0x41, 0x0E); // TX Buffer - 8463084 to 8463225
  writeRegister(0x44, 0x23); // TX Buffer - 8463232 to 8463374
  writeRegister(0x45, 0x11); // TX Buffer - 8463381 to 8463523
  writeRegister(0x46, 0x13); // TX Buffer - 8463529 to 8463672
  writeRegister(0x04, 0x07); // TX - 8463678 to 8463820
  writeRegister(0x00, 0xFF); // CS0 - 8470544 to 8470686
  writeRegister(0x01, 0xFF); // CS1 - 8470694 to 8470835
  writeRegister(0x16, 0xC0); // FIFO CTRL - 8470848 to 8470982
  writeRegister(0x40, 0x03); // TX Buffer - 8470996 to 8471131
  writeRegister(0x41, 0x0E); // TX Buffer - 8471140 to 8471278
  writeRegister(0x44, 0x23); // TX Buffer - 8471289 to 8471428
  writeRegister(0x45, 0x11); // TX Buffer - 8471437 to 8471575
  writeRegister(0x46, 0x13); // TX Buffer - 8471585 to 8471724
  writeRegister(0x04, 0x07); // TX - 8471734 to 8471872
  writeRegister(0x00, 0xFF); // CS0 - 8478515 to 8478655
  writeRegister(0x01, 0xFF); // CS1 - 8478669 to 8478805
  writeRegister(0x16, 0xC0); // FIFO CTRL - 8478819 to 8478954
  writeRegister(0x40, 0x03); // TX Buffer - 8478968 to 8479101
  writeRegister(0x41, 0x0E); // TX Buffer - 8479115 to 8479250
  writeRegister(0x44, 0x23); // TX Buffer - 8479264 to 8479398
  writeRegister(0x45, 0x11); // TX Buffer - 8479412 to 8479548
  writeRegister(0x46, 0x13); // TX Buffer - 8479560 to 8479697
  writeRegister(0x04, 0x07); // TX - 8479709 to 8479845
  writeRegister(0x00, 0xFF); // CS0 - 8486490 to 8486634
  writeRegister(0x01, 0xFF); // CS1 - 8486640 to 8486780
  writeRegister(0x16, 0xC0); // FIFO CTRL - 8486794 to 8486929
  writeRegister(0x40, 0x03); // TX Buffer - 8486943 to 8487076
  writeRegister(0x41, 0x0E); // TX Buffer - 8487087 to 8487225
  writeRegister(0x44, 0x23); // TX Buffer - 8487235 to 8487373
  writeRegister(0x45, 0x11); // TX Buffer - 8487384 to 8487523
  writeRegister(0x46, 0x13); // TX Buffer - 8487532 to 8487672
  writeRegister(0x04, 0x07); // TX - 8487681 to 8487820
  writeRegister(0x00, 0xFF); // CS0 - 8494547 to 8494686
  writeRegister(0x01, 0xFF); // CS1 - 8494697 to 8494838
  writeRegister(0x16, 0xC0); // FIFO CTRL - 8494850 to 8494985
  writeRegister(0x40, 0x03); // TX Buffer - 8494999 to 8495134
  writeRegister(0x41, 0x0E); // TX Buffer - 8495146 to 8495281
  writeRegister(0x44, 0x23); // TX Buffer - 8495295 to 8495431
  writeRegister(0x45, 0x11); // TX Buffer - 8495443 to 8495579
  writeRegister(0x46, 0x13); // TX Buffer - 8495592 to 8495728
  writeRegister(0x04, 0x07); // TX - 8495741 to 8495876
  writeRegister(0x00, 0xFF); // CS0 - 8502522 to 8502659
  writeRegister(0x01, 0xFF); // CS1 - 8502672 to 8502813
  writeRegister(0x16, 0xC0); // FIFO CTRL - 8502822 to 8502960
  writeRegister(0x40, 0x03); // TX Buffer - 8502970 to 8503104
  writeRegister(0x41, 0x0E); // TX Buffer - 8503118 to 8503253
  writeRegister(0x44, 0x23); // TX Buffer - 8503266 to 8503401
  writeRegister(0x45, 0x11); // TX Buffer - 8503415 to 8503551
  writeRegister(0x46, 0x13); // TX Buffer - 8503563 to 8503706
  writeRegister(0x04, 0x07); // TX - 8503712 to 8503846
  writeRegister(0x00, 0xFF); // CS0 - 8510493 to 8510634
  writeRegister(0x01, 0xFF); // CS1 - 8510643 to 8510783
  writeRegister(0x16, 0xC0); // FIFO CTRL - 8510797 to 8510932
  writeRegister(0x40, 0x03); // TX Buffer - 8510945 to 8511079
  writeRegister(0x41, 0x0E); // TX Buffer - 8511093 to 8511228
  writeRegister(0x44, 0x23); // TX Buffer - 8511241 to 8511377
  writeRegister(0x45, 0x11); // TX Buffer - 8511390 to 8511524
  writeRegister(0x46, 0x13); // TX Buffer - 8511538 to 8511673
  writeRegister(0x04, 0x07); // TX - 8511687 to 8511821
  writeRegister(0x00, 0xFF); // CS0 - 8518549 to 8518689
  writeRegister(0x01, 0xFF); // CS1 - 8518703 to 8518839
  writeRegister(0x16, 0xC0); // FIFO CTRL - 8518853 to 8518988
  writeRegister(0x40, 0x03); // TX Buffer - 8519002 to 8519135
  writeRegister(0x41, 0x0E); // TX Buffer - 8519149 to 8519284
  writeRegister(0x44, 0x23); // TX Buffer - 8519298 to 8519432
  writeRegister(0x45, 0x11); // TX Buffer - 8519446 to 8519582
  writeRegister(0x46, 0x13); // TX Buffer - 8519594 to 8519731
  writeRegister(0x04, 0x07); // TX - 8519743 to 8519879
  writeRegister(0x00, 0xFF); // CS0 - 8526524 to 8526662
  writeRegister(0x01, 0xFF); // CS1 - 8526674 to 8526814
  writeRegister(0x16, 0xC0); // FIFO CTRL - 8526828 to 8526963
  writeRegister(0x40, 0x03); // TX Buffer - 8526977 to 8527110
  writeRegister(0x41, 0x0E); // TX Buffer - 8527121 to 8527259
  writeRegister(0x44, 0x23); // TX Buffer - 8527269 to 8527407
  writeRegister(0x45, 0x11); // TX Buffer - 8527418 to 8527557
  writeRegister(0x46, 0x13); // TX Buffer - 8527566 to 8527706
  writeRegister(0x04, 0x07); // TX - 8527715 to 8527854
  writeRegister(0x00, 0xFF); // CS0 - 8534496 to 8534637
  writeRegister(0x01, 0xFF); // CS1 - 8534649 to 8534787
  writeRegister(0x16, 0xC0); // FIFO CTRL - 8534800 to 8534934
  writeRegister(0x40, 0x03); // TX Buffer - 8534948 to 8535083
  writeRegister(0x41, 0x0E); // TX Buffer - 8535096 to 8535230
  writeRegister(0x44, 0x23); // TX Buffer - 8535244 to 8535380
  writeRegister(0x45, 0x11); // TX Buffer - 8535393 to 8535527
  writeRegister(0x46, 0x13); // TX Buffer - 8535541 to 8535676
  writeRegister(0x04, 0x07); // TX - 8535690 to 8535824
  writeRegister(0x00, 0xFF); // CS0 - 8542552 to 8542693
  writeRegister(0x01, 0xFF); // CS1 - 8542706 to 8542850
  writeRegister(0x16, 0xC0); // FIFO CTRL - 8542856 to 8542994
  writeRegister(0x40, 0x03); // TX Buffer - 8543004 to 8543138
  writeRegister(0x41, 0x0E); // TX Buffer - 8543152 to 8543287
  writeRegister(0x44, 0x23); // TX Buffer - 8543300 to 8543435
  writeRegister(0x45, 0x11); // TX Buffer - 8543449 to 8543585
  writeRegister(0x46, 0x13); // TX Buffer - 8543597 to 8543740
  writeRegister(0x04, 0x07); // TX - 8543746 to 8543880
  writeRegister(0x00, 0xFF); // CS0 - 8550527 to 8550668
  writeRegister(0x01, 0xFF); // CS1 - 8550677 to 8550817
  writeRegister(0x16, 0xC0); // FIFO CTRL - 8550831 to 8550966
  writeRegister(0x40, 0x03); // TX Buffer - 8550979 to 8551113
  writeRegister(0x41, 0x0E); // TX Buffer - 8551127 to 8551262
  writeRegister(0x44, 0x23); // TX Buffer - 8551275 to 8551410
  writeRegister(0x45, 0x11); // TX Buffer - 8551424 to 8551558
  writeRegister(0x46, 0x13); // TX Buffer - 8551572 to 8551707
  writeRegister(0x04, 0x07); // TX - 8551721 to 8551855
  writeRegister(0x00, 0xFF); // CS0 - 8558499 to 8558638
  writeRegister(0x01, 0xFF); // CS1 - 8558652 to 8558796
  writeRegister(0x16, 0xC0); // FIFO CTRL - 8558803 to 8558941
  writeRegister(0x40, 0x03); // TX Buffer - 8558951 to 8559086
  writeRegister(0x41, 0x0E); // TX Buffer - 8559098 to 8559233
  writeRegister(0x44, 0x23); // TX Buffer - 8559247 to 8559383
  writeRegister(0x45, 0x11); // TX Buffer - 8559395 to 8559530
  writeRegister(0x46, 0x13); // TX Buffer - 8559544 to 8559686
  writeRegister(0x04, 0x07); // TX - 8559693 to 8559828
  writeRegister(0x00, 0xFF); // CS0 - 8566558 to 8566696
  writeRegister(0x01, 0xFF); // CS1 - 8566708 to 8566848
  writeRegister(0x16, 0xC0); // FIFO CTRL - 8566859 to 8566997
  writeRegister(0x40, 0x03); // TX Buffer - 8567007 to 8567148
  writeRegister(0x41, 0x0E); // TX Buffer - 8567155 to 8567293
  writeRegister(0x44, 0x23); // TX Buffer - 8567303 to 8567445
  writeRegister(0x45, 0x11); // TX Buffer - 8567452 to 8567594
  writeRegister(0x46, 0x13); // TX Buffer - 8567600 to 8567740
  writeRegister(0x04, 0x07); // TX - 8567749 to 8567891
  writeRegister(0x00, 0xFF); // CS0 - 8574530 to 8574671
  writeRegister(0x01, 0xFF); // CS1 - 8574683 to 8574821
  writeRegister(0x16, 0xC0); // FIFO CTRL - 8574834 to 8574968
  writeRegister(0x40, 0x03); // TX Buffer - 8574982 to 8575117
  writeRegister(0x41, 0x0E); // TX Buffer - 8575130 to 8575264
  writeRegister(0x44, 0x23); // TX Buffer - 8575278 to 8575414
  writeRegister(0x45, 0x11); // TX Buffer - 8575427 to 8575561
  writeRegister(0x46, 0x13); // TX Buffer - 8575575 to 8575710
  writeRegister(0x04, 0x07); // TX - 8575724 to 8575858
  writeRegister(0x00, 0xFF); // CS0 - 8582505 to 8582641
  writeRegister(0x01, 0xFF); // CS1 - 8582655 to 8582796
  writeRegister(0x16, 0xC0); // FIFO CTRL - 8582805 to 8582943
  writeRegister(0x40, 0x03); // TX Buffer - 8582954 to 8583095
  writeRegister(0x41, 0x0E); // TX Buffer - 8583101 to 8583239
  writeRegister(0x44, 0x23); // TX Buffer - 8583250 to 8583392
  writeRegister(0x45, 0x11); // TX Buffer - 8583398 to 8583540
  writeRegister(0x46, 0x13); // TX Buffer - 8583547 to 8583685
  writeRegister(0x04, 0x07); // TX - 8583696 to 8583837
  writeRegister(0x00, 0xFF); // CS0 - 8590561 to 8590705
  writeRegister(0x01, 0xFF); // CS1 - 8590711 to 8590851
  writeRegister(0x16, 0xC0); // FIFO CTRL - 8590865 to 8591000
  writeRegister(0x40, 0x03); // TX Buffer - 8591013 to 8591147
  writeRegister(0x41, 0x0E); // TX Buffer - 8591157 to 8591296
  writeRegister(0x44, 0x23); // TX Buffer - 8591306 to 8591444
  writeRegister(0x45, 0x11); // TX Buffer - 8591454 to 8591594
  writeRegister(0x46, 0x13); // TX Buffer - 8591603 to 8591741
  writeRegister(0x04, 0x07); // TX - 8591755 to 8591889
  writeRegister(0x00, 0xFF); // CS0 - 8598533 to 8598672
  writeRegister(0x01, 0xFF); // CS1 - 8598686 to 8598830
  writeRegister(0x16, 0xC0); // FIFO CTRL - 8598837 to 8598975
  writeRegister(0x40, 0x03); // TX Buffer - 8598985 to 8599120
  writeRegister(0x41, 0x0E); // TX Buffer - 8599132 to 8599267
  writeRegister(0x44, 0x23); // TX Buffer - 8599281 to 8599417
  writeRegister(0x45, 0x11); // TX Buffer - 8599429 to 8599564
  writeRegister(0x46, 0x13); // TX Buffer - 8599578 to 8599714
  writeRegister(0x04, 0x07); // TX - 8599727 to 8599862
  writeRegister(0x00, 0xFF); // CS0 - 8606508 to 8606651
  writeRegister(0x01, 0xFF); // CS1 - 8606658 to 8606799
  writeRegister(0x16, 0xC0); // FIFO CTRL - 8606812 to 8606946
  writeRegister(0x40, 0x03); // TX Buffer - 8606960 to 8607095
  writeRegister(0x41, 0x0E); // TX Buffer - 8607104 to 8607242
  writeRegister(0x44, 0x23); // TX Buffer - 8607252 to 8607392
  writeRegister(0x45, 0x11); // TX Buffer - 8607401 to 8607540
  writeRegister(0x46, 0x13); // TX Buffer - 8607549 to 8607689
  writeRegister(0x04, 0x07); // TX - 8607702 to 8607837
  writeRegister(0x00, 0xFF); // CS0 - 8614564 to 8614705
  writeRegister(0x01, 0xFF); // CS1 - 8614714 to 8614855
  writeRegister(0x16, 0xC0); // FIFO CTRL - 8614868 to 8615002
  writeRegister(0x40, 0x03); // TX Buffer - 8615016 to 8615151
  writeRegister(0x41, 0x0E); // TX Buffer - 8615164 to 8615298
  writeRegister(0x44, 0x23); // TX Buffer - 8615312 to 8615448
  writeRegister(0x45, 0x11); // TX Buffer - 8615461 to 8615595
  writeRegister(0x46, 0x13); // TX Buffer - 8615609 to 8615744
  writeRegister(0x04, 0x07); // TX - 8615758 to 8615892
  writeRegister(0x00, 0xFF); // CS0 - 8622539 to 8622675
  writeRegister(0x01, 0xFF); // CS1 - 8622689 to 8622830
  writeRegister(0x16, 0xC0); // FIFO CTRL - 8622839 to 8622977
  writeRegister(0x40, 0x03); // TX Buffer - 8622988 to 8623129
  writeRegister(0x41, 0x0E); // TX Buffer - 8623135 to 8623273
  writeRegister(0x44, 0x23); // TX Buffer - 8623284 to 8623426
  writeRegister(0x45, 0x11); // TX Buffer - 8623432 to 8623574
  writeRegister(0x46, 0x13); // TX Buffer - 8623581 to 8623719
  writeRegister(0x04, 0x07); // TX - 8623730 to 8623871
  writeRegister(0x00, 0xFF); // CS0 - 8630511 to 8630650
  writeRegister(0x01, 0xFF); // CS1 - 8630660 to 8630802
  writeRegister(0x16, 0xC0); // FIFO CTRL - 8630814 to 8630949
  writeRegister(0x40, 0x03); // TX Buffer - 8630963 to 8631096
  writeRegister(0x41, 0x0E); // TX Buffer - 8631110 to 8631245
  writeRegister(0x44, 0x23); // TX Buffer - 8631259 to 8631393
  writeRegister(0x45, 0x11); // TX Buffer - 8631407 to 8631543
  writeRegister(0x46, 0x13); // TX Buffer - 8631556 to 8631692
  writeRegister(0x04, 0x07); // TX - 8631704 to 8631840
  writeRegister(0x00, 0xFF); // CS0 - 8638567 to 8638706
  writeRegister(0x01, 0xFF); // CS1 - 8638720 to 8638864
  writeRegister(0x16, 0xC0); // FIFO CTRL - 8638871 to 8639013
  writeRegister(0x40, 0x03); // TX Buffer - 8639019 to 8639154
  writeRegister(0x41, 0x0E); // TX Buffer - 8639166 to 8639301
  writeRegister(0x44, 0x23); // TX Buffer - 8639315 to 8639451
  writeRegister(0x45, 0x11); // TX Buffer - 8639463 to 8639598
  writeRegister(0x46, 0x13); // TX Buffer - 8639612 to 8639748
  writeRegister(0x04, 0x07); // TX - 8639761 to 8639896
  writeRegister(0x00, 0xFF); // CS0 - 8646542 to 8646685
  writeRegister(0x01, 0xFF); // CS1 - 8646692 to 8646833
  writeRegister(0x16, 0xC0); // FIFO CTRL - 8646846 to 8646980
  writeRegister(0x40, 0x03); // TX Buffer - 8646994 to 8647129
  writeRegister(0x41, 0x0E); // TX Buffer - 8647138 to 8647276
  writeRegister(0x44, 0x23); // TX Buffer - 8647286 to 8647426
  writeRegister(0x45, 0x11); // TX Buffer - 8647435 to 8647573
  writeRegister(0x46, 0x13); // TX Buffer - 8647583 to 8647723
  writeRegister(0x04, 0x07); // TX - 8647736 to 8647871
  writeRegister(0x00, 0xFF); // CS0 - 8654505 to 8654646
  writeRegister(0x01, 0xFF); // CS1 - 8654659 to 8654795
  writeRegister(0x16, 0xC0); // FIFO CTRL - 8654809 to 8654944
  writeRegister(0x40, 0x03); // TX Buffer - 8654957 to 8655091
  writeRegister(0x41, 0x0E); // TX Buffer - 8655105 to 8655240
  writeRegister(0x44, 0x23); // TX Buffer - 8655253 to 8655388
  writeRegister(0x45, 0x11); // TX Buffer - 8655402 to 8655538
  writeRegister(0x46, 0x13); // TX Buffer - 8655550 to 8655685
  writeRegister(0x04, 0x07); // TX - 8655699 to 8655833
  writeRegister(0x00, 0xFF); // CS0 - 8662565 to 8662701
  writeRegister(0x01, 0xFF); // CS1 - 8662715 to 8662856
  writeRegister(0x16, 0xC0); // FIFO CTRL - 8662865 to 8663003
  writeRegister(0x40, 0x03); // TX Buffer - 8663014 to 8663147
  writeRegister(0x41, 0x0E); // TX Buffer - 8663161 to 8663296
  writeRegister(0x44, 0x23); // TX Buffer - 8663310 to 8663444
  writeRegister(0x45, 0x11); // TX Buffer - 8663458 to 8663594
  writeRegister(0x46, 0x13); // TX Buffer - 8663607 to 8663749
  writeRegister(0x04, 0x07); // TX - 8663755 to 8663891
  writeRegister(0x00, 0xFF); // CS0 - 8670537 to 8670676
  writeRegister(0x01, 0xFF); // CS1 - 8670686 to 8670828
  writeRegister(0x16, 0xC0); // FIFO CTRL - 8670840 to 8670975
  writeRegister(0x40, 0x03); // TX Buffer - 8670989 to 8671122
  writeRegister(0x41, 0x0E); // TX Buffer - 8671136 to 8671271
  writeRegister(0x44, 0x23); // TX Buffer - 8671285 to 8671419
  writeRegister(0x45, 0x11); // TX Buffer - 8671433 to 8671569
  writeRegister(0x46, 0x13); // TX Buffer - 8671582 to 8671718
  writeRegister(0x04, 0x07); // TX - 8671730 to 8671866
  writeRegister(0x00, 0xFF); // CS0 - 8678511 to 8678649
  writeRegister(0x01, 0xFF); // CS1 - 8678661 to 8678801
  writeRegister(0x16, 0xC0); // FIFO CTRL - 8678812 to 8678950
  writeRegister(0x40, 0x03); // TX Buffer - 8678960 to 8679095
  writeRegister(0x41, 0x0E); // TX Buffer - 8679108 to 8679242
  writeRegister(0x44, 0x23); // TX Buffer - 8679256 to 8679392
  writeRegister(0x45, 0x11); // TX Buffer - 8679405 to 8679539
  writeRegister(0x46, 0x13); // TX Buffer - 8679553 to 8679696
  writeRegister(0x04, 0x07); // TX - 8679702 to 8679836
  writeRegister(0x00, 0xFF); // CS0 - 8686568 to 8686705
  writeRegister(0x01, 0xFF); // CS1 - 8686718 to 8686859
  writeRegister(0x16, 0xC0); // FIFO CTRL - 8686872 to 8687006
  writeRegister(0x40, 0x03); // TX Buffer - 8687020 to 8687155
  writeRegister(0x41, 0x0E); // TX Buffer - 8687164 to 8687302
  writeRegister(0x44, 0x23); // TX Buffer - 8687312 to 8687452
  writeRegister(0x45, 0x11); // TX Buffer - 8687461 to 8687600
  writeRegister(0x46, 0x13); // TX Buffer - 8687609 to 8687749
  writeRegister(0x04, 0x07); // TX - 8687758 to 8687897
  writeRegister(0x00, 0xFF); // CS0 - 8694540 to 8694679
  writeRegister(0x01, 0xFF); // CS1 - 8694693 to 8694831
  writeRegister(0x16, 0xC0); // FIFO CTRL - 8694843 to 8694978
  writeRegister(0x40, 0x03); // TX Buffer - 8694992 to 8695125
  writeRegister(0x41, 0x0E); // TX Buffer - 8695139 to 8695274
  writeRegister(0x44, 0x23); // TX Buffer - 8695288 to 8695422
  writeRegister(0x45, 0x11); // TX Buffer - 8695436 to 8695572
  writeRegister(0x46, 0x13); // TX Buffer - 8695585 to 8695721
  writeRegister(0x04, 0x07); // TX - 8695733 to 8695869
  writeRegister(0x00, 0xFF); // CS0 - 8702533 to 8702672
  writeRegister(0x01, 0xFF); // CS1 - 8702686 to 8702830
  writeRegister(0x16, 0xC0); // FIFO CTRL - 8702837 to 8702975
  writeRegister(0x40, 0x04); // TX Buffer - 8702985 to 8703118
  writeRegister(0x41, 0x0E); // TX Buffer - 8703132 to 8703267
  writeRegister(0x44, 0x23); // TX Buffer - 8703280 to 8703415
  writeRegister(0x45, 0x11); // TX Buffer - 8703429 to 8703565
  writeRegister(0x46, 0x13); // TX Buffer - 8703577 to 8703714
  writeRegister(0x04, 0x07); // TX - 8703726 to 8703862
  writeRegister(0x00, 0xFF); // CS0 - 8710581 to 8710720
  writeRegister(0x01, 0xFF); // CS1 - 8710734 to 8710878
  writeRegister(0x16, 0xC0); // FIFO CTRL - 8710884 to 8711022
  writeRegister(0x40, 0x04); // TX Buffer - 8711033 to 8711166
  writeRegister(0x41, 0x0E); // TX Buffer - 8711180 to 8711314
  writeRegister(0x44, 0x23); // TX Buffer - 8711328 to 8711464
  writeRegister(0x45, 0x11); // TX Buffer - 8711477 to 8711611
  writeRegister(0x46, 0x13); // TX Buffer - 8711625 to 8711760
  writeRegister(0x04, 0x07); // TX - 8711774 to 8711908
  writeRegister(0x00, 0xFF); // CS0 - 8718555 to 8718699
  writeRegister(0x01, 0xFF); // CS1 - 8718705 to 8718845
  writeRegister(0x16, 0xC0); // FIFO CTRL - 8718859 to 8718993
  writeRegister(0x40, 0x04); // TX Buffer - 8719007 to 8719140
  writeRegister(0x41, 0x0E); // TX Buffer - 8719151 to 8719289
  writeRegister(0x44, 0x23); // TX Buffer - 8719299 to 8719437
  writeRegister(0x45, 0x11); // TX Buffer - 8719448 to 8719587
  writeRegister(0x46, 0x13); // TX Buffer - 8719596 to 8719736
  writeRegister(0x04, 0x07); // TX - 8719745 to 8719884
  writeRegister(0x00, 0xFF); // CS0 - 8726526 to 8726667
  writeRegister(0x01, 0xFF); // CS1 - 8726679 to 8726816
  writeRegister(0x16, 0xC0); // FIFO CTRL - 8726830 to 8726966
  writeRegister(0x40, 0x04); // TX Buffer - 8726978 to 8727113
  writeRegister(0x41, 0x0E); // TX Buffer - 8727125 to 8727260
  writeRegister(0x44, 0x23); // TX Buffer - 8727274 to 8727408
  writeRegister(0x45, 0x11); // TX Buffer - 8727422 to 8727558
  writeRegister(0x46, 0x13); // TX Buffer - 8727571 to 8727707
  writeRegister(0x04, 0x07); // TX - 8727720 to 8727855
  writeRegister(0x00, 0xFF); // CS0 - 8734582 to 8734721
  writeRegister(0x01, 0xFF); // CS1 - 8734735 to 8734879
  writeRegister(0x16, 0xC0); // FIFO CTRL - 8734886 to 8735028
  writeRegister(0x40, 0x04); // TX Buffer - 8735034 to 8735167
  writeRegister(0x41, 0x0E); // TX Buffer - 8735181 to 8735316
  writeRegister(0x44, 0x23); // TX Buffer - 8735330 to 8735464
  writeRegister(0x45, 0x11); // TX Buffer - 8735478 to 8735614
  writeRegister(0x46, 0x13); // TX Buffer - 8735626 to 8735763
  writeRegister(0x04, 0x07); // TX - 8735775 to 8735911
  writeRegister(0x00, 0xFF); // CS0 - 8742556 to 8742694
  writeRegister(0x01, 0xFF); // CS1 - 8742706 to 8742846
  writeRegister(0x16, 0xC0); // FIFO CTRL - 8742860 to 8742995
  writeRegister(0x40, 0x04); // TX Buffer - 8743009 to 8743142
  writeRegister(0x41, 0x0E); // TX Buffer - 8743152 to 8743290
  writeRegister(0x44, 0x23); // TX Buffer - 8743301 to 8743443
  writeRegister(0x45, 0x11); // TX Buffer - 8743449 to 8743591
  writeRegister(0x46, 0x13); // TX Buffer - 8743597 to 8743736
  writeRegister(0x04, 0x07); // TX - 8743746 to 8743888
  writeRegister(0x00, 0xFF); // CS0 - 8750527 to 8750668
  writeRegister(0x01, 0xFF); // CS1 - 8750677 to 8750817
  writeRegister(0x16, 0xC0); // FIFO CTRL - 8750831 to 8750966
  writeRegister(0x40, 0x04); // TX Buffer - 8750980 to 8751113
  writeRegister(0x41, 0x0E); // TX Buffer - 8751127 to 8751261
  writeRegister(0x44, 0x23); // TX Buffer - 8751275 to 8751411
  writeRegister(0x45, 0x11); // TX Buffer - 8751423 to 8751558
  writeRegister(0x46, 0x13); // TX Buffer - 8751572 to 8751707
  writeRegister(0x04, 0x07); // TX - 8751721 to 8751855
  writeRegister(0x00, 0xFF); // CS0 - 8758583 to 8758724
  writeRegister(0x01, 0xFF); // CS1 - 8758737 to 8758873
  writeRegister(0x16, 0xC0); // FIFO CTRL - 8758887 to 8759022
  writeRegister(0x40, 0x04); // TX Buffer - 8759035 to 8759169
  writeRegister(0x41, 0x0E); // TX Buffer - 8759182 to 8759317
  writeRegister(0x44, 0x23); // TX Buffer - 8759331 to 8759467
  writeRegister(0x45, 0x11); // TX Buffer - 8759479 to 8759615
  writeRegister(0x46, 0x13); // TX Buffer - 8759628 to 8759764
  writeRegister(0x04, 0x07); // TX - 8759777 to 8759912
  writeRegister(0x00, 0xFF); // CS0 - 8766558 to 8766695
  writeRegister(0x01, 0xFF); // CS1 - 8766708 to 8766849
  writeRegister(0x16, 0xC0); // FIFO CTRL - 8766858 to 8766996
  writeRegister(0x40, 0x04); // TX Buffer - 8767006 to 8767140
  writeRegister(0x41, 0x0E); // TX Buffer - 8767153 to 8767288
  writeRegister(0x44, 0x23); // TX Buffer - 8767302 to 8767438
  writeRegister(0x45, 0x11); // TX Buffer - 8767450 to 8767585
  writeRegister(0x46, 0x13); // TX Buffer - 8767599 to 8767741
  writeRegister(0x04, 0x07); // TX - 8767748 to 8767883
  writeRegister(0x00, 0xFF); // CS0 - 8774529 to 8774668
  writeRegister(0x01, 0xFF); // CS1 - 8774679 to 8774820
  writeRegister(0x16, 0xC0); // FIFO CTRL - 8774832 to 8774967
  writeRegister(0x40, 0x04); // TX Buffer - 8774981 to 8775114
  writeRegister(0x41, 0x0E); // TX Buffer - 8775124 to 8775263
  writeRegister(0x44, 0x23); // TX Buffer - 8775273 to 8775411
  writeRegister(0x45, 0x11); // TX Buffer - 8775421 to 8775561
  writeRegister(0x46, 0x13); // TX Buffer - 8775570 to 8775708
  writeRegister(0x04, 0x07); // TX - 8775722 to 8775856
  writeRegister(0x00, 0xFF); // CS0 - 8782585 to 8782724
  writeRegister(0x01, 0xFF); // CS1 - 8782734 to 8782876
  writeRegister(0x16, 0xC0); // FIFO CTRL - 8782888 to 8783023
  writeRegister(0x40, 0x04); // TX Buffer - 8783037 to 8783170
  writeRegister(0x41, 0x0E); // TX Buffer - 8783184 to 8783318
  writeRegister(0x44, 0x23); // TX Buffer - 8783332 to 8783468
  writeRegister(0x45, 0x11); // TX Buffer - 8783481 to 8783615
  writeRegister(0x46, 0x13); // TX Buffer - 8783629 to 8783764
  writeRegister(0x04, 0x07); // TX - 8783778 to 8783912
  writeRegister(0x00, 0xFF); // CS0 - 8790559 to 8790695
  writeRegister(0x01, 0xFF); // CS1 - 8790709 to 8790850
  writeRegister(0x16, 0xC0); // FIFO CTRL - 8790859 to 8790997
  writeRegister(0x40, 0x04); // TX Buffer - 8791008 to 8791141
  writeRegister(0x41, 0x0E); // TX Buffer - 8791155 to 8791289
  writeRegister(0x44, 0x23); // TX Buffer - 8791303 to 8791439
  writeRegister(0x45, 0x11); // TX Buffer - 8791452 to 8791586
  writeRegister(0x46, 0x13); // TX Buffer - 8791600 to 8791735
  writeRegister(0x04, 0x07); // TX - 8791749 to 8791883
  writeRegister(0x00, 0xFF); // CS0 - 8798530 to 8798674
  writeRegister(0x01, 0xFF); // CS1 - 8798680 to 8798820
  writeRegister(0x16, 0xC0); // FIFO CTRL - 8798834 to 8798970
  writeRegister(0x40, 0x04); // TX Buffer - 8798982 to 8799117
  writeRegister(0x41, 0x0E); // TX Buffer - 8799126 to 8799264
  writeRegister(0x44, 0x23); // TX Buffer - 8799274 to 8799412
  writeRegister(0x45, 0x11); // TX Buffer - 8799423 to 8799562
  writeRegister(0x46, 0x13); // TX Buffer - 8799571 to 8799711
  writeRegister(0x04, 0x07); // TX - 8799720 to 8799859
  writeRegister(0x00, 0xFF); // CS0 - 8806586 to 8806725
  writeRegister(0x01, 0xFF); // CS1 - 8806736 to 8806877
  writeRegister(0x16, 0xC0); // FIFO CTRL - 8806890 to 8807024
  writeRegister(0x40, 0x04); // TX Buffer - 8807038 to 8807171
  writeRegister(0x41, 0x0E); // TX Buffer - 8807182 to 8807320
  writeRegister(0x44, 0x23); // TX Buffer - 8807330 to 8807468
  writeRegister(0x45, 0x11); // TX Buffer - 8807479 to 8807618
  writeRegister(0x46, 0x13); // TX Buffer - 8807627 to 8807767
  writeRegister(0x04, 0x07); // TX - 8807779 to 8807915
  writeRegister(0x00, 0xFF); // CS0 - 8814557 to 8814698
  writeRegister(0x01, 0xFF); // CS1 - 8814710 to 8814854
  writeRegister(0x16, 0xC0); // FIFO CTRL - 8814861 to 8814999
  writeRegister(0x40, 0x04); // TX Buffer - 8815009 to 8815142
  writeRegister(0x41, 0x0E); // TX Buffer - 8815156 to 8815291
  writeRegister(0x44, 0x23); // TX Buffer - 8815305 to 8815439
  writeRegister(0x45, 0x11); // TX Buffer - 8815453 to 8815589
  writeRegister(0x46, 0x13); // TX Buffer - 8815601 to 8815738
  writeRegister(0x04, 0x07); // TX - 8815750 to 8815886
  writeRegister(0x00, 0xFF); // CS0 - 8822531 to 8822675
  writeRegister(0x01, 0xFF); // CS1 - 8822681 to 8822821
  writeRegister(0x16, 0xC0); // FIFO CTRL - 8822835 to 8822970
  writeRegister(0x40, 0x04); // TX Buffer - 8822984 to 8823117
  writeRegister(0x41, 0x0E); // TX Buffer - 8823127 to 8823265
  writeRegister(0x44, 0x23); // TX Buffer - 8823276 to 8823418
  writeRegister(0x45, 0x11); // TX Buffer - 8823424 to 8823566
  writeRegister(0x46, 0x13); // TX Buffer - 8823572 to 8823711
  writeRegister(0x04, 0x07); // TX - 8823721 to 8823863
  writeRegister(0x00, 0xFF); // CS0 - 8830587 to 8830731
  writeRegister(0x01, 0xFF); // CS1 - 8830737 to 8830877
  writeRegister(0x16, 0xC0); // FIFO CTRL - 8830891 to 8831026
  writeRegister(0x40, 0x04); // TX Buffer - 8831039 to 8831173
  writeRegister(0x41, 0x0E); // TX Buffer - 8831183 to 8831321
  writeRegister(0x44, 0x23); // TX Buffer - 8831331 to 8831471
  writeRegister(0x45, 0x11); // TX Buffer - 8831480 to 8831619
  writeRegister(0x46, 0x13); // TX Buffer - 8831628 to 8831768
  writeRegister(0x04, 0x07); // TX - 8831777 to 8831916
  writeRegister(0x00, 0xFF); // CS0 - 8838558 to 8838699
  writeRegister(0x01, 0xFF); // CS1 - 8838712 to 8838848
  writeRegister(0x16, 0xC0); // FIFO CTRL - 8838862 to 8838997
  writeRegister(0x40, 0x04); // TX Buffer - 8839010 to 8839144
  writeRegister(0x41, 0x0E); // TX Buffer - 8839157 to 8839292
  writeRegister(0x44, 0x23); // TX Buffer - 8839306 to 8839442
  writeRegister(0x45, 0x11); // TX Buffer - 8839454 to 8839590
  writeRegister(0x46, 0x13); // TX Buffer - 8839603 to 8839739
  writeRegister(0x04, 0x07); // TX - 8839752 to 8839887
  writeRegister(0x00, 0xFF); // CS0 - 8846533 to 8846670
  writeRegister(0x01, 0xFF); // CS1 - 8846683 to 8846824
  writeRegister(0x16, 0xC0); // FIFO CTRL - 8846833 to 8846971
  writeRegister(0x40, 0x04); // TX Buffer - 8846981 to 8847121
  writeRegister(0x41, 0x0E); // TX Buffer - 8847128 to 8847271
  writeRegister(0x44, 0x23); // TX Buffer - 8847277 to 8847419
  writeRegister(0x45, 0x11); // TX Buffer - 8847425 to 8847568
  writeRegister(0x46, 0x13); // TX Buffer - 8847574 to 8847716
  writeRegister(0x04, 0x07); // TX - 8847723 to 8847864
  writeRegister(0x00, 0xFF); // CS0 - 8854589 to 8854732
  writeRegister(0x01, 0xFF); // CS1 - 8854738 to 8854880
  writeRegister(0x16, 0xC0); // FIFO CTRL - 8854892 to 8855027
  writeRegister(0x40, 0x04); // TX Buffer - 8855041 to 8855174
  writeRegister(0x41, 0x0E); // TX Buffer - 8855184 to 8855322
  writeRegister(0x44, 0x23); // TX Buffer - 8855333 to 8855475
  writeRegister(0x45, 0x11); // TX Buffer - 8855481 to 8855623
  writeRegister(0x46, 0x13); // TX Buffer - 8855630 to 8855768
  writeRegister(0x04, 0x07); // TX - 8855779 to 8855920
  writeRegister(0x00, 0xFF); // CS0 - 8862560 to 8862699
  writeRegister(0x01, 0xFF); // CS1 - 8862713 to 8862851
  writeRegister(0x16, 0xC0); // FIFO CTRL - 8862863 to 8862998
  writeRegister(0x40, 0x04); // TX Buffer - 8863012 to 8863145
  writeRegister(0x41, 0x0E); // TX Buffer - 8863159 to 8863293
  writeRegister(0x44, 0x23); // TX Buffer - 8863307 to 8863443
  writeRegister(0x45, 0x11); // TX Buffer - 8863456 to 8863590
  writeRegister(0x46, 0x13); // TX Buffer - 8863604 to 8863739
  writeRegister(0x04, 0x07); // TX - 8863753 to 8863887
  writeRegister(0x00, 0xFF); // CS0 - 8870534 to 8870670
  writeRegister(0x01, 0xFF); // CS1 - 8870684 to 8870825
  writeRegister(0x16, 0xC0); // FIFO CTRL - 8870834 to 8870972
  writeRegister(0x40, 0x04); // TX Buffer - 8870983 to 8871116
  writeRegister(0x41, 0x0E); // TX Buffer - 8871130 to 8871266
  writeRegister(0x44, 0x23); // TX Buffer - 8871278 to 8871414
  writeRegister(0x45, 0x11); // TX Buffer - 8871427 to 8871561
  writeRegister(0x46, 0x13); // TX Buffer - 8871575 to 8871718
  writeRegister(0x04, 0x07); // TX - 8871724 to 8871858
  writeRegister(0x00, 0xFF); // CS0 - 8878590 to 8878727
  writeRegister(0x01, 0xFF); // CS1 - 8878740 to 8878881
  writeRegister(0x16, 0xC0); // FIFO CTRL - 8878890 to 8879028
  writeRegister(0x40, 0x04); // TX Buffer - 8879039 to 8879178
  writeRegister(0x41, 0x0E); // TX Buffer - 8879186 to 8879328
  writeRegister(0x44, 0x23); // TX Buffer - 8879334 to 8879476
  writeRegister(0x45, 0x11); // TX Buffer - 8879482 to 8879625
  writeRegister(0x46, 0x13); // TX Buffer - 8879631 to 8879774
  writeRegister(0x04, 0x07); // TX - 8879780 to 8879922
  writeRegister(0x00, 0xFF); // CS0 - 8886561 to 8886700
  writeRegister(0x01, 0xFF); // CS1 - 8886711 to 8886852
  writeRegister(0x16, 0xC0); // FIFO CTRL - 8886865 to 8886999
  writeRegister(0x40, 0x04); // TX Buffer - 8887013 to 8887146
  writeRegister(0x41, 0x0E); // TX Buffer - 8887160 to 8887295
  writeRegister(0x44, 0x23); // TX Buffer - 8887309 to 8887443
  writeRegister(0x45, 0x11); // TX Buffer - 8887457 to 8887593
  writeRegister(0x46, 0x13); // TX Buffer - 8887605 to 8887742
  writeRegister(0x04, 0x07); // TX - 8887754 to 8887890
  writeRegister(0x00, 0xFF); // CS0 - 8894532 to 8894673
  writeRegister(0x01, 0xFF); // CS1 - 8894685 to 8894829
  writeRegister(0x16, 0xC0); // FIFO CTRL - 8894836 to 8894974
  writeRegister(0x40, 0x04); // TX Buffer - 8894984 to 8895117
  writeRegister(0x41, 0x0E); // TX Buffer - 8895131 to 8895266
  writeRegister(0x44, 0x23); // TX Buffer - 8895280 to 8895414
  writeRegister(0x45, 0x11); // TX Buffer - 8895428 to 8895564
  writeRegister(0x46, 0x13); // TX Buffer - 8895576 to 8895713
  writeRegister(0x04, 0x07); // TX - 8895725 to 8895861
  writeRegister(0x00, 0xFF); // CS0 - 8902591 to 8902727
  writeRegister(0x01, 0xFF); // CS1 - 8902741 to 8902881
  writeRegister(0x16, 0xC0); // FIFO CTRL - 8902891 to 8903030
  writeRegister(0x40, 0x04); // TX Buffer - 8903040 to 8903173
  writeRegister(0x41, 0x0E); // TX Buffer - 8903187 to 8903322
  writeRegister(0x44, 0x23); // TX Buffer - 8903335 to 8903470
  writeRegister(0x45, 0x11); // TX Buffer - 8903484 to 8903620
  writeRegister(0x46, 0x13); // TX Buffer - 8903632 to 8903775
  writeRegister(0x04, 0x07); // TX - 8903781 to 8903915
  writeRegister(0x00, 0xFF); // CS0 - 8910562 to 8910703
  writeRegister(0x01, 0xFF); // CS1 - 8910712 to 8910852
  writeRegister(0x16, 0xC0); // FIFO CTRL - 8910866 to 8911001
  writeRegister(0x40, 0x04); // TX Buffer - 8911014 to 8911148
  writeRegister(0x41, 0x0E); // TX Buffer - 8911158 to 8911296
  writeRegister(0x44, 0x23); // TX Buffer - 8911306 to 8911446
  writeRegister(0x45, 0x11); // TX Buffer - 8911455 to 8911594
  writeRegister(0x46, 0x13); // TX Buffer - 8911603 to 8911743
  writeRegister(0x04, 0x07); // TX - 8911756 to 8911891
  writeRegister(0x00, 0xFF); // CS0 - 8918533 to 8918674
  writeRegister(0x01, 0xFF); // CS1 - 8918687 to 8918831
  writeRegister(0x16, 0xC0); // FIFO CTRL - 8918837 to 8918978
  writeRegister(0x40, 0x04); // TX Buffer - 8918985 to 8919119
  writeRegister(0x41, 0x0E); // TX Buffer - 8919132 to 8919267
  writeRegister(0x44, 0x23); // TX Buffer - 8919281 to 8919417
  writeRegister(0x45, 0x11); // TX Buffer - 8919429 to 8919564
  writeRegister(0x46, 0x13); // TX Buffer - 8919578 to 8919714
  writeRegister(0x04, 0x07); // TX - 8919727 to 8919862
  writeRegister(0x00, 0xFF); // CS0 - 8926589 to 8926730
  writeRegister(0x01, 0xFF); // CS1 - 8926742 to 8926885
  writeRegister(0x16, 0xC0); // FIFO CTRL - 8926893 to 8927031
  writeRegister(0x40, 0x04); // TX Buffer - 8927041 to 8927174
  writeRegister(0x41, 0x0E); // TX Buffer - 8927188 to 8927323
  writeRegister(0x44, 0x23); // TX Buffer - 8927337 to 8927471
  writeRegister(0x45, 0x11); // TX Buffer - 8927485 to 8927621
  writeRegister(0x46, 0x13); // TX Buffer - 8927634 to 8927770
  writeRegister(0x04, 0x07); // TX - 8927783 to 8927918
  writeRegister(0x00, 0xFF); // CS0 - 8934564 to 8934707
  writeRegister(0x01, 0xFF); // CS1 - 8934713 to 8934855
  writeRegister(0x16, 0xC0); // FIFO CTRL - 8934867 to 8935002
  writeRegister(0x40, 0x04); // TX Buffer - 8935016 to 8935149
  writeRegister(0x41, 0x0E); // TX Buffer - 8935159 to 8935297
  writeRegister(0x44, 0x23); // TX Buffer - 8935308 to 8935447
  writeRegister(0x45, 0x11); // TX Buffer - 8935456 to 8935594
  writeRegister(0x46, 0x13); // TX Buffer - 8935605 to 8935743
  writeRegister(0x04, 0x07); // TX - 8935754 to 8935891
  writeRegister(0x00, 0xFF); // CS0 - 8942535 to 8942674
  writeRegister(0x01, 0xFF); // CS1 - 8942688 to 8942826
  writeRegister(0x16, 0xC0); // FIFO CTRL - 8942838 to 8942973
  writeRegister(0x40, 0x04); // TX Buffer - 8942987 to 8943120
  writeRegister(0x41, 0x0E); // TX Buffer - 8943134 to 8943268
  writeRegister(0x44, 0x23); // TX Buffer - 8943282 to 8943418
  writeRegister(0x45, 0x11); // TX Buffer - 8943431 to 8943565
  writeRegister(0x46, 0x13); // TX Buffer - 8943579 to 8943714
  writeRegister(0x04, 0x07); // TX - 8943728 to 8943862
  writeRegister(0x00, 0xFF); // CS0 - 8950590 to 8950731
  writeRegister(0x01, 0xFF); // CS1 - 8950744 to 8950888
  writeRegister(0x16, 0xC0); // FIFO CTRL - 8950894 to 8951035
  writeRegister(0x40, 0x04); // TX Buffer - 8951043 to 8951176
  writeRegister(0x41, 0x0E); // TX Buffer - 8951190 to 8951324
  writeRegister(0x44, 0x23); // TX Buffer - 8951338 to 8951474
  writeRegister(0x45, 0x11); // TX Buffer - 8951486 to 8951621
  writeRegister(0x46, 0x13); // TX Buffer - 8951635 to 8951770
  writeRegister(0x04, 0x07); // TX - 8951784 to 8951918
  writeRegister(0x00, 0xFF); // CS0 - 8958557 to 8958694
  writeRegister(0x01, 0xFF); // CS1 - 8958707 to 8958848
  writeRegister(0x16, 0xC0); // FIFO CTRL - 8958857 to 8958995
  writeRegister(0x40, 0x04); // TX Buffer - 8959006 to 8959145
  writeRegister(0x41, 0x0E); // TX Buffer - 8959153 to 8959295
  writeRegister(0x44, 0x23); // TX Buffer - 8959301 to 8959443
  writeRegister(0x45, 0x11); // TX Buffer - 8959449 to 8959592
  writeRegister(0x46, 0x13); // TX Buffer - 8959598 to 8959741
  writeRegister(0x04, 0x07); // TX - 8959747 to 8959887
  writeRegister(0x00, 0xFF); // CS0 - 8966528 to 8966667
  writeRegister(0x01, 0xFF); // CS1 - 8966678 to 8966819
  writeRegister(0x16, 0xC0); // FIFO CTRL - 8966832 to 8966966
  writeRegister(0x40, 0x04); // TX Buffer - 8966980 to 8967113
  writeRegister(0x41, 0x0E); // TX Buffer - 8967127 to 8967262
  writeRegister(0x44, 0x23); // TX Buffer - 8967275 to 8967410
  writeRegister(0x45, 0x11); // TX Buffer - 8967424 to 8967560
  writeRegister(0x46, 0x13); // TX Buffer - 8967572 to 8967709
  writeRegister(0x04, 0x07); // TX - 8967721 to 8967857
  writeRegister(0x00, 0xFF); // CS0 - 8974584 to 8974723
  writeRegister(0x01, 0xFF); // CS1 - 8974737 to 8974875
  writeRegister(0x16, 0xC0); // FIFO CTRL - 8974887 to 8975022
  writeRegister(0x40, 0x04); // TX Buffer - 8975036 to 8975169
  writeRegister(0x41, 0x0E); // TX Buffer - 8975183 to 8975319
  writeRegister(0x44, 0x23); // TX Buffer - 8975331 to 8975467
  writeRegister(0x45, 0x11); // TX Buffer - 8975480 to 8975614
  writeRegister(0x46, 0x13); // TX Buffer - 8975628 to 8975763
  writeRegister(0x04, 0x07); // TX - 8975777 to 8975911
  writeRegister(0x00, 0xFF); // CS0 - 8982558 to 8982694
  writeRegister(0x01, 0xFF); // CS1 - 8982708 to 8982848
  writeRegister(0x16, 0xC0); // FIFO CTRL - 8982858 to 8982997
  writeRegister(0x40, 0x04); // TX Buffer - 8983007 to 8983140
  writeRegister(0x41, 0x0E); // TX Buffer - 8983154 to 8983289
  writeRegister(0x44, 0x23); // TX Buffer - 8983302 to 8983438
  writeRegister(0x45, 0x11); // TX Buffer - 8983451 to 8983585
  writeRegister(0x46, 0x13); // TX Buffer - 8983599 to 8983742
  writeRegister(0x04, 0x07); // TX - 8983748 to 8983882
  writeRegister(0x00, 0xFF); // CS0 - 8990529 to 8990670
  writeRegister(0x01, 0xFF); // CS1 - 8990679 to 8990819
  writeRegister(0x16, 0xC0); // FIFO CTRL - 8990833 to 8990968
  writeRegister(0x40, 0x04); // TX Buffer - 8990981 to 8991115
  writeRegister(0x41, 0x0E); // TX Buffer - 8991125 to 8991263
  writeRegister(0x44, 0x23); // TX Buffer - 8991273 to 8991413
  writeRegister(0x45, 0x11); // TX Buffer - 8991422 to 8991561
  writeRegister(0x46, 0x13); // TX Buffer - 8991570 to 8991710
  writeRegister(0x04, 0x07); // TX - 8991723 to 8991858
  writeRegister(0x00, 0xFF); // CS0 - 8998585 to 8998726
  writeRegister(0x01, 0xFF); // CS1 - 8998735 to 8998876
  writeRegister(0x16, 0xC0); // FIFO CTRL - 8998889 to 8999023
  writeRegister(0x40, 0x04); // TX Buffer - 8999037 to 8999170
  writeRegister(0x41, 0x0E); // TX Buffer - 8999184 to 8999319
  writeRegister(0x44, 0x23); // TX Buffer - 8999333 to 8999467
  writeRegister(0x45, 0x11); // TX Buffer - 8999481 to 8999617
  writeRegister(0x46, 0x13); // TX Buffer - 8999629 to 8999766
  writeRegister(0x04, 0x07); // TX - 8999778 to 8999914
  writeRegister(0x00, 0xFF); // CS0 - 9006556 to 9006697
  writeRegister(0x01, 0xFF); // CS1 - 9006709 to 9006853
  writeRegister(0x16, 0xC0); // FIFO CTRL - 9006860 to 9006998
  writeRegister(0x40, 0x04); // TX Buffer - 9007008 to 9007141
  writeRegister(0x41, 0x0E); // TX Buffer - 9007155 to 9007290
  writeRegister(0x44, 0x23); // TX Buffer - 9007304 to 9007438
  writeRegister(0x45, 0x11); // TX Buffer - 9007452 to 9007588
  writeRegister(0x46, 0x13); // TX Buffer - 9007601 to 9007737
  writeRegister(0x04, 0x07); // TX - 9007749 to 9007885
  writeRegister(0x00, 0xFF); // CS0 - 9014531 to 9014674
  writeRegister(0x01, 0xFF); // CS1 - 9014680 to 9014822
  writeRegister(0x16, 0xC0); // FIFO CTRL - 9014834 to 9014969
  writeRegister(0x40, 0x04); // TX Buffer - 9014983 to 9015116
  writeRegister(0x41, 0x0E); // TX Buffer - 9015126 to 9015264
  writeRegister(0x44, 0x23); // TX Buffer - 9015275 to 9015414
  writeRegister(0x45, 0x11); // TX Buffer - 9015423 to 9015561
  writeRegister(0x46, 0x13); // TX Buffer - 9015572 to 9015710
  writeRegister(0x04, 0x07); // TX - 9015721 to 9015858
  writeRegister(0x00, 0xFF); // CS0 - 9022586 to 9022727
  writeRegister(0x01, 0xFF); // CS1 - 9022736 to 9022876
  writeRegister(0x16, 0xC0); // FIFO CTRL - 9022890 to 9023025
  writeRegister(0x40, 0x04); // TX Buffer - 9023038 to 9023172
  writeRegister(0x41, 0x0E); // TX Buffer - 9023182 to 9023320
  writeRegister(0x44, 0x23); // TX Buffer - 9023330 to 9023470
  writeRegister(0x45, 0x11); // TX Buffer - 9023479 to 9023617
  writeRegister(0x46, 0x13); // TX Buffer - 9023627 to 9023767
  writeRegister(0x04, 0x07); // TX - 9023780 to 9023915
  writeRegister(0x00, 0xFF); // CS0 - 9030557 to 9030698
  writeRegister(0x01, 0xFF); // CS1 - 9030711 to 9030855
  writeRegister(0x16, 0xC0); // FIFO CTRL - 9030861 to 9031002
  writeRegister(0x40, 0x04); // TX Buffer - 9031010 to 9031143
  writeRegister(0x41, 0x0E); // TX Buffer - 9031157 to 9031291
  writeRegister(0x44, 0x23); // TX Buffer - 9031305 to 9031441
  writeRegister(0x45, 0x11); // TX Buffer - 9031453 to 9031588
  writeRegister(0x46, 0x13); // TX Buffer - 9031602 to 9031737
  writeRegister(0x04, 0x07); // TX - 9031751 to 9031886
  writeRegister(0x00, 0xFF); // CS0 - 9038532 to 9038669
  writeRegister(0x01, 0xFF); // CS1 - 9038682 to 9038823
  writeRegister(0x16, 0xC0); // FIFO CTRL - 9038836 to 9038970
  writeRegister(0x40, 0x04); // TX Buffer - 9038984 to 9039117
  writeRegister(0x41, 0x0E); // TX Buffer - 9039128 to 9039266
  writeRegister(0x44, 0x23); // TX Buffer - 9039276 to 9039418
  writeRegister(0x45, 0x11); // TX Buffer - 9039424 to 9039567
  writeRegister(0x46, 0x13); // TX Buffer - 9039573 to 9039713
  writeRegister(0x04, 0x07); // TX - 9039722 to 9039864
  writeRegister(0x00, 0xFF); // CS0 - 9046588 to 9046731
  writeRegister(0x01, 0xFF); // CS1 - 9046738 to 9046879
  writeRegister(0x16, 0xC0); // FIFO CTRL - 9046891 to 9047026
  writeRegister(0x40, 0x04); // TX Buffer - 9047040 to 9047173
  writeRegister(0x41, 0x0E); // TX Buffer - 9047183 to 9047321
  writeRegister(0x44, 0x23); // TX Buffer - 9047332 to 9047471
  writeRegister(0x45, 0x11); // TX Buffer - 9047480 to 9047618
  writeRegister(0x46, 0x13); // TX Buffer - 9047629 to 9047767
  writeRegister(0x04, 0x07); // TX - 9047778 to 9047915
  writeRegister(0x00, 0xFF); // CS0 - 9054559 to 9054698
  writeRegister(0x01, 0xFF); // CS1 - 9054712 to 9054850
  writeRegister(0x16, 0xC0); // FIFO CTRL - 9054862 to 9054997
  writeRegister(0x40, 0x04); // TX Buffer - 9055011 to 9055144
  writeRegister(0x41, 0x0E); // TX Buffer - 9055158 to 9055294
  writeRegister(0x44, 0x23); // TX Buffer - 9055306 to 9055442
  writeRegister(0x45, 0x11); // TX Buffer - 9055455 to 9055589
  writeRegister(0x46, 0x13); // TX Buffer - 9055603 to 9055738
  writeRegister(0x04, 0x07); // TX - 9055752 to 9055886
  writeRegister(0x00, 0xFF); // CS0 - 9062533 to 9062669
  writeRegister(0x01, 0xFF); // CS1 - 9062683 to 9062823
  writeRegister(0x16, 0xC0); // FIFO CTRL - 9062833 to 9062972
  writeRegister(0x40, 0x04); // TX Buffer - 9062982 to 9063115
  writeRegister(0x41, 0x0E); // TX Buffer - 9063129 to 9063264
  writeRegister(0x44, 0x23); // TX Buffer - 9063277 to 9063412
  writeRegister(0x45, 0x11); // TX Buffer - 9063426 to 9063562
  writeRegister(0x46, 0x13); // TX Buffer - 9063574 to 9063717
  writeRegister(0x04, 0x07); // TX - 9063723 to 9063857
  writeRegister(0x00, 0xFF); // CS0 - 9070589 to 9070725
  writeRegister(0x01, 0xFF); // CS1 - 9070739 to 9070880
  writeRegister(0x16, 0xC0); // FIFO CTRL - 9070893 to 9071027
  writeRegister(0x40, 0x04); // TX Buffer - 9071041 to 9071174
  writeRegister(0x41, 0x0E); // TX Buffer - 9071185 to 9071323
  writeRegister(0x44, 0x23); // TX Buffer - 9071333 to 9071475
  writeRegister(0x45, 0x11); // TX Buffer - 9071482 to 9071624
  writeRegister(0x46, 0x13); // TX Buffer - 9071630 to 9071770
  writeRegister(0x04, 0x07); // TX - 9071779 to 9071921
  writeRegister(0x00, 0xFF); // CS0 - 9078560 to 9078701
  writeRegister(0x01, 0xFF); // CS1 - 9078710 to 9078851
  writeRegister(0x16, 0xC0); // FIFO CTRL - 9078864 to 9078998
  writeRegister(0x40, 0x04); // TX Buffer - 9079012 to 9079145
  writeRegister(0x41, 0x0E); // TX Buffer - 9079159 to 9079294
  writeRegister(0x44, 0x23); // TX Buffer - 9079308 to 9079442
  writeRegister(0x45, 0x11); // TX Buffer - 9079456 to 9079592
  writeRegister(0x46, 0x13); // TX Buffer - 9079605 to 9079741
  writeRegister(0x04, 0x07); // TX - 9079753 to 9079889
  writeRegister(0x00, 0xFF); // CS0 - 9086534 to 9086672
  writeRegister(0x01, 0xFF); // CS1 - 9086684 to 9086824
  writeRegister(0x16, 0xC0); // FIFO CTRL - 9086835 to 9086973
  writeRegister(0x40, 0x04); // TX Buffer - 9086983 to 9087116
  writeRegister(0x41, 0x0E); // TX Buffer - 9087130 to 9087265
  writeRegister(0x44, 0x23); // TX Buffer - 9087279 to 9087413
  writeRegister(0x45, 0x11); // TX Buffer - 9087427 to 9087563
  writeRegister(0x46, 0x13); // TX Buffer - 9087576 to 9087712
  writeRegister(0x04, 0x07); // TX - 9087725 to 9087860
  writeRegister(0x00, 0xFF); // CS0 - 9094590 to 9094726
  writeRegister(0x01, 0xFF); // CS1 - 9094740 to 9094880
  writeRegister(0x16, 0xC0); // FIFO CTRL - 9094891 to 9095029
  writeRegister(0x40, 0x04); // TX Buffer - 9095039 to 9095172
  writeRegister(0x41, 0x0E); // TX Buffer - 9095186 to 9095321
  writeRegister(0x44, 0x23); // TX Buffer - 9095334 to 9095469
  writeRegister(0x45, 0x11); // TX Buffer - 9095483 to 9095619
  writeRegister(0x46, 0x13); // TX Buffer - 9095631 to 9095774
  writeRegister(0x04, 0x07); // TX - 9095780 to 9095916
  writeRegister(0x00, 0xFF); // CS0 - 9102561 to 9102702
  writeRegister(0x01, 0xFF); // CS1 - 9102711 to 9102851
  writeRegister(0x16, 0xC0); // FIFO CTRL - 9102865 to 9103000
  writeRegister(0x40, 0x04); // TX Buffer - 9103013 to 9103147
  writeRegister(0x41, 0x0E); // TX Buffer - 9103157 to 9103295
  writeRegister(0x44, 0x23); // TX Buffer - 9103306 to 9103445
  writeRegister(0x45, 0x11); // TX Buffer - 9103454 to 9103592
  writeRegister(0x46, 0x13); // TX Buffer - 9103602 to 9103742
  writeRegister(0x04, 0x07); // TX - 9103755 to 9103890
  writeRegister(0x00, 0xFF); // CS0 - 9110532 to 9110673
  writeRegister(0x01, 0xFF); // CS1 - 9110686 to 9110830
  writeRegister(0x16, 0xC0); // FIFO CTRL - 9110836 to 9110974
  writeRegister(0x40, 0x04); // TX Buffer - 9110985 to 9111118
  writeRegister(0x41, 0x0E); // TX Buffer - 9111132 to 9111266
  writeRegister(0x44, 0x23); // TX Buffer - 9111280 to 9111416
  writeRegister(0x45, 0x11); // TX Buffer - 9111428 to 9111563
  writeRegister(0x46, 0x13); // TX Buffer - 9111577 to 9111712
  writeRegister(0x04, 0x07); // TX - 9111726 to 9111860
  writeRegister(0x00, 0xFF); // CS0 - 9118592 to 9118729
  writeRegister(0x01, 0xFF); // CS1 - 9118741 to 9118883
  writeRegister(0x16, 0xC0); // FIFO CTRL - 9118892 to 9119030
  writeRegister(0x40, 0x04); // TX Buffer - 9119040 to 9119174
  writeRegister(0x41, 0x0E); // TX Buffer - 9119187 to 9119322
  writeRegister(0x44, 0x23); // TX Buffer - 9119336 to 9119470
  writeRegister(0x45, 0x11); // TX Buffer - 9119484 to 9119620
  writeRegister(0x46, 0x13); // TX Buffer - 9119633 to 9119769
  writeRegister(0x04, 0x07); // TX - 9119782 to 9119917
  writeRegister(0x00, 0xFF); // CS0 - 9126563 to 9126706
  writeRegister(0x01, 0xFF); // CS1 - 9126713 to 9126854
  writeRegister(0x16, 0xC0); // FIFO CTRL - 9126866 to 9127001
  writeRegister(0x40, 0x04); // TX Buffer - 9127015 to 9127148
  writeRegister(0x41, 0x0E); // TX Buffer - 9127158 to 9127298
  writeRegister(0x44, 0x23); // TX Buffer - 9127307 to 9127446
  writeRegister(0x45, 0x11); // TX Buffer - 9127455 to 9127593
  writeRegister(0x46, 0x13); // TX Buffer - 9127604 to 9127742
  writeRegister(0x04, 0x07); // TX - 9127753 to 9127890
  writeRegister(0x00, 0xFF); // CS0 - 9134534 to 9134673
  writeRegister(0x01, 0xFF); // CS1 - 9134687 to 9134825
  writeRegister(0x16, 0xC0); // FIFO CTRL - 9134837 to 9134972
  writeRegister(0x40, 0x04); // TX Buffer - 9134986 to 9135119
  writeRegister(0x41, 0x0E); // TX Buffer - 9135133 to 9135268
  writeRegister(0x44, 0x23); // TX Buffer - 9135281 to 9135417
  writeRegister(0x45, 0x11); // TX Buffer - 9135430 to 9135564
  writeRegister(0x46, 0x13); // TX Buffer - 9135578 to 9135713
  writeRegister(0x04, 0x07); // TX - 9135727 to 9135861
  writeRegister(0x00, 0xFF); // CS0 - 9142589 to 9142729
  writeRegister(0x01, 0xFF); // CS1 - 9142743 to 9142887
  writeRegister(0x16, 0xC0); // FIFO CTRL - 9142893 to 9143031
  writeRegister(0x40, 0x04); // TX Buffer - 9143042 to 9143175
  writeRegister(0x41, 0x0E); // TX Buffer - 9143189 to 9143323
  writeRegister(0x44, 0x23); // TX Buffer - 9143337 to 9143473
  writeRegister(0x45, 0x11); // TX Buffer - 9143486 to 9143620
  writeRegister(0x46, 0x13); // TX Buffer - 9143634 to 9143769
  writeRegister(0x04, 0x07); // TX - 9143783 to 9143917
  writeRegister(0x00, 0xFF); // CS0 - 9150564 to 9150708
  writeRegister(0x01, 0xFF); // CS1 - 9150714 to 9150855
  writeRegister(0x16, 0xC0); // FIFO CTRL - 9150868 to 9151002
  writeRegister(0x40, 0x04); // TX Buffer - 9151016 to 9151149
  writeRegister(0x41, 0x0E); // TX Buffer - 9151160 to 9151298
  writeRegister(0x44, 0x23); // TX Buffer - 9151308 to 9151450
  writeRegister(0x45, 0x11); // TX Buffer - 9151457 to 9151599
  writeRegister(0x46, 0x13); // TX Buffer - 9151605 to 9151745
  writeRegister(0x04, 0x07); // TX - 9151754 to 9151896
  writeRegister(0x00, 0xFF); // CS0 - 9158535 to 9158676
  writeRegister(0x01, 0xFF); // CS1 - 9158688 to 9158826
  writeRegister(0x16, 0xC0); // FIFO CTRL - 9158839 to 9158973
  writeRegister(0x40, 0x04); // TX Buffer - 9158987 to 9159120
  writeRegister(0x41, 0x0E); // TX Buffer - 9159134 to 9159269
  writeRegister(0x44, 0x23); // TX Buffer - 9159283 to 9159417
  writeRegister(0x45, 0x11); // TX Buffer - 9159431 to 9159567
  writeRegister(0x46, 0x13); // TX Buffer - 9159580 to 9159716
  writeRegister(0x04, 0x07); // TX - 9159728 to 9159864
  writeRegister(0x00, 0xFF); // CS0 - 9166591 to 9166730
  writeRegister(0x01, 0xFF); // CS1 - 9166744 to 9166882
  writeRegister(0x16, 0xC0); // FIFO CTRL - 9166895 to 9167029
  writeRegister(0x40, 0x04); // TX Buffer - 9167043 to 9167176
  writeRegister(0x41, 0x0E); // TX Buffer - 9167190 to 9167325
  writeRegister(0x44, 0x23); // TX Buffer - 9167338 to 9167473
  writeRegister(0x45, 0x11); // TX Buffer - 9167487 to 9167623
  writeRegister(0x46, 0x13); // TX Buffer - 9167635 to 9167772
  writeRegister(0x04, 0x07); // TX - 9167784 to 9167918
  writeRegister(0x00, 0xFF); // CS0 - 9174565 to 9174701
  writeRegister(0x01, 0xFF); // CS1 - 9174715 to 9174855
  writeRegister(0x16, 0xC0); // FIFO CTRL - 9174866 to 9175004
  writeRegister(0x40, 0x04); // TX Buffer - 9175014 to 9175155
  writeRegister(0x41, 0x0E); // TX Buffer - 9175161 to 9175302
  writeRegister(0x44, 0x23); // TX Buffer - 9175309 to 9175452
  writeRegister(0x45, 0x11); // TX Buffer - 9175458 to 9175600
  writeRegister(0x46, 0x13); // TX Buffer - 9175606 to 9175749
  writeRegister(0x04, 0x07); // TX - 9175755 to 9175897
  writeRegister(0x00, 0xFF); // CS0 - 9182621 to 9182765
  writeRegister(0x01, 0xFF); // CS1 - 9182771 to 9182911
  writeRegister(0x16, 0xC0); // FIFO CTRL - 9182925 to 9183061
  writeRegister(0x40, 0x04); // TX Buffer - 9183073 to 9183208
  writeRegister(0x41, 0x0E); // TX Buffer - 9183217 to 9183355
  writeRegister(0x44, 0x23); // TX Buffer - 9183365 to 9183507
  writeRegister(0x45, 0x11); // TX Buffer - 9183514 to 9183656
  writeRegister(0x46, 0x13); // TX Buffer - 9183662 to 9183802
  writeRegister(0x04, 0x07); // TX - 9183811 to 9183953
  writeRegister(0x00, 0xFF); // CS0 - 9190592 to 9190733
  writeRegister(0x01, 0xFF); // CS1 - 9190745 to 9190882
  writeRegister(0x16, 0xC0); // FIFO CTRL - 9190896 to 9191031
  writeRegister(0x40, 0x04); // TX Buffer - 9191044 to 9191178
  writeRegister(0x41, 0x0E); // TX Buffer - 9191191 to 9191326
  writeRegister(0x44, 0x23); // TX Buffer - 9191340 to 9191474
  writeRegister(0x45, 0x11); // TX Buffer - 9191488 to 9191624
  writeRegister(0x46, 0x13); // TX Buffer - 9191637 to 9191773
  writeRegister(0x04, 0x07); // TX - 9191786 to 9191921
  writeRegister(0x00, 0xFF); // CS0 - 9198567 to 9198704
  writeRegister(0x01, 0xFF); // CS1 - 9198717 to 9198858
  writeRegister(0x16, 0xC0); // FIFO CTRL - 9198867 to 9199005
  writeRegister(0x40, 0x04); // TX Buffer - 9199015 to 9199149
  writeRegister(0x41, 0x0E); // TX Buffer - 9199162 to 9199297
  writeRegister(0x44, 0x23); // TX Buffer - 9199311 to 9199447
  writeRegister(0x45, 0x11); // TX Buffer - 9199459 to 9199595
  writeRegister(0x46, 0x13); // TX Buffer - 9199608 to 9199750
  writeRegister(0x04, 0x07); // TX - 9199757 to 9199892
  writeRegister(0x00, 0xFF); // CS0 - 9206622 to 9206760
  writeRegister(0x01, 0xFF); // CS1 - 9206772 to 9206912
  writeRegister(0x16, 0xC0); // FIFO CTRL - 9206923 to 9207061
  writeRegister(0x40, 0x04); // TX Buffer - 9207071 to 9207212
  writeRegister(0x41, 0x0E); // TX Buffer - 9207218 to 9207359
  writeRegister(0x44, 0x23); // TX Buffer - 9207367 to 9207509
  writeRegister(0x45, 0x11); // TX Buffer - 9207515 to 9207657
  writeRegister(0x46, 0x13); // TX Buffer - 9207663 to 9207806
  writeRegister(0x04, 0x07); // TX - 9207812 to 9207954
  writeRegister(0x00, 0xFF); // CS0 - 9214593 to 9214733
  writeRegister(0x01, 0xFF); // CS1 - 9214743 to 9214883
  writeRegister(0x16, 0xC0); // FIFO CTRL - 9214897 to 9215032
  writeRegister(0x40, 0x04); // TX Buffer - 9215046 to 9215179
  writeRegister(0x41, 0x0E); // TX Buffer - 9215193 to 9215327
  writeRegister(0x44, 0x23); // TX Buffer - 9215341 to 9215477
  writeRegister(0x45, 0x11); // TX Buffer - 9215490 to 9215624
  writeRegister(0x46, 0x13); // TX Buffer - 9215638 to 9215773
  writeRegister(0x04, 0x07); // TX - 9215787 to 9215921
  writeRegister(0x00, 0xFF); // CS0 - 9222565 to 9222704
  writeRegister(0x01, 0xFF); // CS1 - 9222718 to 9222862
  writeRegister(0x16, 0xC0); // FIFO CTRL - 9222868 to 9223006
  writeRegister(0x40, 0x04); // TX Buffer - 9223017 to 9223150
  writeRegister(0x41, 0x0E); // TX Buffer - 9223164 to 9223298
  writeRegister(0x44, 0x23); // TX Buffer - 9223312 to 9223448
  writeRegister(0x45, 0x11); // TX Buffer - 9223461 to 9223595
  writeRegister(0x46, 0x13); // TX Buffer - 9223609 to 9223744
  writeRegister(0x04, 0x07); // TX - 9223758 to 9223892
  writeRegister(0x00, 0xFF); // CS0 - 9230624 to 9230761
  writeRegister(0x01, 0xFF); // CS1 - 9230774 to 9230915
  writeRegister(0x16, 0xC0); // FIFO CTRL - 9230924 to 9231062
  writeRegister(0x40, 0x04); // TX Buffer - 9231072 to 9231206
  writeRegister(0x41, 0x0E); // TX Buffer - 9231219 to 9231354
  writeRegister(0x44, 0x23); // TX Buffer - 9231368 to 9231504
  writeRegister(0x45, 0x11); // TX Buffer - 9231516 to 9231651
  writeRegister(0x46, 0x13); // TX Buffer - 9231665 to 9231807
  writeRegister(0x04, 0x07); // TX - 9231814 to 9231949
  writeRegister(0x00, 0xFF); // CS0 - 9238595 to 9238734
  writeRegister(0x01, 0xFF); // CS1 - 9238745 to 9238886
  writeRegister(0x16, 0xC0); // FIFO CTRL - 9238899 to 9239033
  writeRegister(0x40, 0x04); // TX Buffer - 9239047 to 9239180
  writeRegister(0x41, 0x0E); // TX Buffer - 9239191 to 9239329
  writeRegister(0x44, 0x23); // TX Buffer - 9239339 to 9239477
  writeRegister(0x45, 0x11); // TX Buffer - 9239487 to 9239627
  writeRegister(0x46, 0x13); // TX Buffer - 9239636 to 9239774
  writeRegister(0x04, 0x07); // TX - 9239788 to 9239922
  writeRegister(0x00, 0xFF); // CS0 - 9246566 to 9246705
  writeRegister(0x01, 0xFF); // CS1 - 9246719 to 9246863
  writeRegister(0x16, 0xC0); // FIFO CTRL - 9246870 to 9247012
  writeRegister(0x40, 0x04); // TX Buffer - 9247018 to 9247151
  writeRegister(0x41, 0x0E); // TX Buffer - 9247165 to 9247300
  writeRegister(0x44, 0x23); // TX Buffer - 9247313 to 9247448
  writeRegister(0x45, 0x11); // TX Buffer - 9247462 to 9247598
  writeRegister(0x46, 0x13); // TX Buffer - 9247610 to 9247747
  writeRegister(0x04, 0x07); // TX - 9247759 to 9247895
  writeRegister(0x00, 0xFF); // CS0 - 9254622 to 9254761
  writeRegister(0x01, 0xFF); // CS1 - 9254775 to 9254919
  writeRegister(0x16, 0xC0); // FIFO CTRL - 9254925 to 9255063
  writeRegister(0x40, 0x04); // TX Buffer - 9255074 to 9255207
  writeRegister(0x41, 0x0E); // TX Buffer - 9255221 to 9255357
  writeRegister(0x44, 0x23); // TX Buffer - 9255369 to 9255505
  writeRegister(0x45, 0x11); // TX Buffer - 9255518 to 9255652
  writeRegister(0x46, 0x13); // TX Buffer - 9255666 to 9255801
  writeRegister(0x04, 0x07); // TX - 9255815 to 9255949
  writeRegister(0x00, 0xFF); // CS0 - 9262596 to 9262740
  writeRegister(0x01, 0xFF); // CS1 - 9262746 to 9262886
  writeRegister(0x16, 0xC0); // FIFO CTRL - 9262900 to 9263036
  writeRegister(0x40, 0x04); // TX Buffer - 9263048 to 9263183
  writeRegister(0x41, 0x0E); // TX Buffer - 9263192 to 9263330
  writeRegister(0x44, 0x23); // TX Buffer - 9263340 to 9263478
  writeRegister(0x45, 0x11); // TX Buffer - 9263489 to 9263628
  writeRegister(0x46, 0x13); // TX Buffer - 9263637 to 9263777
  writeRegister(0x04, 0x07); // TX - 9263786 to 9263925
  writeRegister(0x00, 0xFF); // CS0 - 9270567 to 9270708
  writeRegister(0x01, 0xFF); // CS1 - 9270720 to 9270857
  writeRegister(0x16, 0xC0); // FIFO CTRL - 9270871 to 9271006
  writeRegister(0x40, 0x04); // TX Buffer - 9271019 to 9271153
  writeRegister(0x41, 0x0E); // TX Buffer - 9271166 to 9271301
  writeRegister(0x44, 0x23); // TX Buffer - 9271315 to 9271449
  writeRegister(0x45, 0x11); // TX Buffer - 9271463 to 9271599
  writeRegister(0x46, 0x13); // TX Buffer - 9271612 to 9271748
  writeRegister(0x04, 0x07); // TX - 9271761 to 9271896
  writeRegister(0x00, 0xFF); // CS0 - 9278623 to 9278764
  writeRegister(0x01, 0xFF); // CS1 - 9278776 to 9278920
  writeRegister(0x16, 0xC0); // FIFO CTRL - 9278927 to 9279069
  writeRegister(0x40, 0x04); // TX Buffer - 9279075 to 9279208
  writeRegister(0x41, 0x0E); // TX Buffer - 9279222 to 9279357
  writeRegister(0x44, 0x23); // TX Buffer - 9279371 to 9279505
  writeRegister(0x45, 0x11); // TX Buffer - 9279519 to 9279655
  writeRegister(0x46, 0x13); // TX Buffer - 9279667 to 9279804
  writeRegister(0x04, 0x07); // TX - 9279816 to 9279952
  writeRegister(0x00, 0xFF); // CS0 - 9286597 to 9286735
  writeRegister(0x01, 0xFF); // CS1 - 9286747 to 9286887
  writeRegister(0x16, 0xC0); // FIFO CTRL - 9286901 to 9287036
  writeRegister(0x40, 0x04); // TX Buffer - 9287050 to 9287183
  writeRegister(0x41, 0x0E); // TX Buffer - 9287193 to 9287331
  writeRegister(0x44, 0x23); // TX Buffer - 9287342 to 9287484
  writeRegister(0x45, 0x11); // TX Buffer - 9287490 to 9287632
  writeRegister(0x46, 0x13); // TX Buffer - 9287639 to 9287777
  writeRegister(0x04, 0x07); // TX - 9287787 to 9287929
  writeRegister(0x00, 0xFF); // CS0 - 9294568 to 9294708
  writeRegister(0x01, 0xFF); // CS1 - 9294718 to 9294858
  writeRegister(0x16, 0xC0); // FIFO CTRL - 9294872 to 9295007
  writeRegister(0x40, 0x04); // TX Buffer - 9295021 to 9295154
  writeRegister(0x41, 0x0E); // TX Buffer - 9295168 to 9295302
  writeRegister(0x44, 0x23); // TX Buffer - 9295316 to 9295452
  writeRegister(0x45, 0x11); // TX Buffer - 9295465 to 9295599
  writeRegister(0x46, 0x13); // TX Buffer - 9295613 to 9295748
  writeRegister(0x04, 0x07); // TX - 9295762 to 9295896
  writeRegister(0x00, 0xFF); // CS0 - 9302624 to 9302765
  writeRegister(0x01, 0xFF); // CS1 - 9302778 to 9302914
  writeRegister(0x16, 0xC0); // FIFO CTRL - 9302928 to 9303063
  writeRegister(0x40, 0x04); // TX Buffer - 9303076 to 9303210
  writeRegister(0x41, 0x0E); // TX Buffer - 9303223 to 9303358
  writeRegister(0x44, 0x23); // TX Buffer - 9303372 to 9303508
  writeRegister(0x45, 0x11); // TX Buffer - 9303520 to 9303656
  writeRegister(0x46, 0x13); // TX Buffer - 9303669 to 9303805
  writeRegister(0x04, 0x07); // TX - 9303818 to 9303953
  writeRegister(0x00, 0xFF); // CS0 - 9310587 to 9310726
  writeRegister(0x01, 0xFF); // CS1 - 9310740 to 9310884
  writeRegister(0x16, 0xC0); // FIFO CTRL - 9310890 to 9311028
  writeRegister(0x40, 0x04); // TX Buffer - 9311039 to 9311172
  writeRegister(0x41, 0x0E); // TX Buffer - 9311186 to 9311320
  writeRegister(0x44, 0x23); // TX Buffer - 9311334 to 9311470
  writeRegister(0x45, 0x11); // TX Buffer - 9311483 to 9311617
  writeRegister(0x46, 0x13); // TX Buffer - 9311631 to 9311766
  writeRegister(0x04, 0x07); // TX - 9311780 to 9311914
  writeRegister(0x00, 0xFF); // CS0 - 9318561 to 9318705
  writeRegister(0x01, 0xFF); // CS1 - 9318711 to 9318852
  writeRegister(0x16, 0xC0); // FIFO CTRL - 9318865 to 9318999
  writeRegister(0x40, 0x04); // TX Buffer - 9319013 to 9319146
  writeRegister(0x41, 0x0E); // TX Buffer - 9319157 to 9319295
  writeRegister(0x44, 0x23); // TX Buffer - 9319305 to 9319447
  writeRegister(0x45, 0x11); // TX Buffer - 9319454 to 9319596
  writeRegister(0x46, 0x13); // TX Buffer - 9319602 to 9319742
  writeRegister(0x04, 0x07); // TX - 9319751 to 9319893
  writeRegister(0x00, 0xFF); // CS0 - 9326617 to 9326760
  writeRegister(0x01, 0xFF); // CS1 - 9326767 to 9326908
  writeRegister(0x16, 0xC0); // FIFO CTRL - 9326921 to 9327055
  writeRegister(0x40, 0x04); // TX Buffer - 9327069 to 9327202
  writeRegister(0x41, 0x0E); // TX Buffer - 9327213 to 9327351
  writeRegister(0x44, 0x23); // TX Buffer - 9327361 to 9327499
  writeRegister(0x45, 0x11); // TX Buffer - 9327509 to 9327649
  writeRegister(0x46, 0x13); // TX Buffer - 9327658 to 9327798
  writeRegister(0x04, 0x07); // TX - 9327807 to 9327944
  writeRegister(0x00, 0xFF); // CS0 - 9334588 to 9334727
  writeRegister(0x01, 0xFF); // CS1 - 9334741 to 9334879
  writeRegister(0x16, 0xC0); // FIFO CTRL - 9334892 to 9335026
  writeRegister(0x40, 0x04); // TX Buffer - 9335040 to 9335173
  writeRegister(0x41, 0x0E); // TX Buffer - 9335187 to 9335322
  writeRegister(0x44, 0x23); // TX Buffer - 9335335 to 9335470
  writeRegister(0x45, 0x11); // TX Buffer - 9335484 to 9335620
  writeRegister(0x46, 0x13); // TX Buffer - 9335632 to 9335769
  writeRegister(0x04, 0x07); // TX - 9335781 to 9335917
  writeRegister(0x00, 0xFF); // CS0 - 9342562 to 9342700
  writeRegister(0x01, 0xFF); // CS1 - 9342712 to 9342852
  writeRegister(0x16, 0xC0); // FIFO CTRL - 9342863 to 9343001
  writeRegister(0x40, 0x04); // TX Buffer - 9343011 to 9343152
  writeRegister(0x41, 0x0E); // TX Buffer - 9343158 to 9343299
  writeRegister(0x44, 0x23); // TX Buffer - 9343307 to 9343449
  writeRegister(0x45, 0x11); // TX Buffer - 9343455 to 9343597
  writeRegister(0x46, 0x13); // TX Buffer - 9343603 to 9343746
  writeRegister(0x04, 0x07); // TX - 9343752 to 9343894
  writeRegister(0x00, 0xFF); // CS0 - 9350618 to 9350762
  writeRegister(0x01, 0xFF); // CS1 - 9350768 to 9350908
  writeRegister(0x16, 0xC0); // FIFO CTRL - 9350922 to 9351057
  writeRegister(0x40, 0x04); // TX Buffer - 9351070 to 9351205
  writeRegister(0x41, 0x0E); // TX Buffer - 9351214 to 9351352
  writeRegister(0x44, 0x23); // TX Buffer - 9351362 to 9351504
  writeRegister(0x45, 0x11); // TX Buffer - 9351511 to 9351653
  writeRegister(0x46, 0x13); // TX Buffer - 9351659 to 9351799
  writeRegister(0x04, 0x07); // TX - 9351808 to 9351950
  writeRegister(0x00, 0xFF); // CS0 - 9358589 to 9358730
  writeRegister(0x01, 0xFF); // CS1 - 9358743 to 9358879
  writeRegister(0x16, 0xC0); // FIFO CTRL - 9358893 to 9359028
  writeRegister(0x40, 0x04); // TX Buffer - 9359041 to 9359175
  writeRegister(0x41, 0x0E); // TX Buffer - 9359188 to 9359323
  writeRegister(0x44, 0x23); // TX Buffer - 9359337 to 9359473
  writeRegister(0x45, 0x11); // TX Buffer - 9359485 to 9359621
  writeRegister(0x46, 0x13); // TX Buffer - 9359634 to 9359770
  writeRegister(0x04, 0x07); // TX - 9359783 to 9359918
  writeRegister(0x00, 0xFF); // CS0 - 9366564 to 9366701
  writeRegister(0x01, 0xFF); // CS1 - 9366714 to 9366855
  writeRegister(0x16, 0xC0); // FIFO CTRL - 9366864 to 9367002
  writeRegister(0x40, 0x04); // TX Buffer - 9367012 to 9367146
  writeRegister(0x41, 0x0E); // TX Buffer - 9367159 to 9367294
  writeRegister(0x44, 0x23); // TX Buffer - 9367308 to 9367444
  writeRegister(0x45, 0x11); // TX Buffer - 9367456 to 9367592
  writeRegister(0x46, 0x13); // TX Buffer - 9367605 to 9367747
  writeRegister(0x04, 0x07); // TX - 9367754 to 9367889
  writeRegister(0x00, 0xFF); // CS0 - 9374619 to 9374757
  writeRegister(0x01, 0xFF); // CS1 - 9374769 to 9374909
  writeRegister(0x16, 0xC0); // FIFO CTRL - 9374920 to 9375058
  writeRegister(0x40, 0x04); // TX Buffer - 9375068 to 9375209
  writeRegister(0x41, 0x0E); // TX Buffer - 9375215 to 9375356
  writeRegister(0x44, 0x23); // TX Buffer - 9375364 to 9375506
  writeRegister(0x45, 0x11); // TX Buffer - 9375512 to 9375654
  writeRegister(0x46, 0x13); // TX Buffer - 9375661 to 9375803
  writeRegister(0x04, 0x07); // TX - 9375809 to 9375951
  writeRegister(0x00, 0xFF); // CS0 - 9382591 to 9382730
  writeRegister(0x01, 0xFF); // CS1 - 9382740 to 9382882
  writeRegister(0x16, 0xC0); // FIFO CTRL - 9382894 to 9383029
  writeRegister(0x40, 0x04); // TX Buffer - 9383043 to 9383176
  writeRegister(0x41, 0x0E); // TX Buffer - 9383190 to 9383324
  writeRegister(0x44, 0x23); // TX Buffer - 9383338 to 9383474
  writeRegister(0x45, 0x11); // TX Buffer - 9383487 to 9383621
  writeRegister(0x46, 0x13); // TX Buffer - 9383635 to 9383770
  writeRegister(0x04, 0x07); // TX - 9383784 to 9383918
  writeRegister(0x00, 0xFF); // CS0 - 9390562 to 9390701
  writeRegister(0x01, 0xFF); // CS1 - 9390715 to 9390859
  writeRegister(0x16, 0xC0); // FIFO CTRL - 9390865 to 9391003
  writeRegister(0x40, 0x04); // TX Buffer - 9391014 to 9391147
  writeRegister(0x41, 0x0E); // TX Buffer - 9391161 to 9391295
  writeRegister(0x44, 0x23); // TX Buffer - 9391309 to 9391445
  writeRegister(0x45, 0x11); // TX Buffer - 9391458 to 9391592
  writeRegister(0x46, 0x13); // TX Buffer - 9391606 to 9391741
  writeRegister(0x04, 0x07); // TX - 9391755 to 9391889
  writeRegister(0x00, 0xFF); // CS0 - 9398621 to 9398758
  writeRegister(0x01, 0xFF); // CS1 - 9398771 to 9398912
  writeRegister(0x16, 0xC0); // FIFO CTRL - 9398921 to 9399059
  writeRegister(0x40, 0x04); // TX Buffer - 9399070 to 9399203
  writeRegister(0x41, 0x0E); // TX Buffer - 9399217 to 9399351
  writeRegister(0x44, 0x23); // TX Buffer - 9399365 to 9399501
  writeRegister(0x45, 0x11); // TX Buffer - 9399513 to 9399648
  writeRegister(0x46, 0x13); // TX Buffer - 9399662 to 9399803
  writeRegister(0x04, 0x07); // TX - 9399811 to 9399946
  writeRegister(0x00, 0xFF); // CS0 - 9406592 to 9406731
  writeRegister(0x01, 0xFF); // CS1 - 9406742 to 9406883
  writeRegister(0x16, 0xC0); // FIFO CTRL - 9406896 to 9407030
  writeRegister(0x40, 0x04); // TX Buffer - 9407044 to 9407177
  writeRegister(0x41, 0x0E); // TX Buffer - 9407188 to 9407326
  writeRegister(0x44, 0x23); // TX Buffer - 9407336 to 9407474
  writeRegister(0x45, 0x11); // TX Buffer - 9407484 to 9407624
  writeRegister(0x46, 0x13); // TX Buffer - 9407633 to 9407773
  writeRegister(0x04, 0x07); // TX - 9407785 to 9407921
  writeRegister(0x00, 0xFF); // CS0 - 9414563 to 9414702
  writeRegister(0x01, 0xFF); // CS1 - 9414716 to 9414860
  writeRegister(0x16, 0xC0); // FIFO CTRL - 9414867 to 9415009
  writeRegister(0x40, 0x04); // TX Buffer - 9415015 to 9415148
  writeRegister(0x41, 0x0E); // TX Buffer - 9415162 to 9415297
  writeRegister(0x44, 0x23); // TX Buffer - 9415311 to 9415445
  writeRegister(0x45, 0x11); // TX Buffer - 9415459 to 9415595
  writeRegister(0x46, 0x13); // TX Buffer - 9415607 to 9415744
  writeRegister(0x04, 0x07); // TX - 9415756 to 9415892
  writeRegister(0x00, 0xFF); // CS0 - 9422619 to 9422758
  writeRegister(0x01, 0xFF); // CS1 - 9422772 to 9422916
  writeRegister(0x16, 0xC0); // FIFO CTRL - 9422922 to 9423062
  writeRegister(0x40, 0x04); // TX Buffer - 9423071 to 9423204
  writeRegister(0x41, 0x0E); // TX Buffer - 9423218 to 9423354
  writeRegister(0x44, 0x23); // TX Buffer - 9423366 to 9423502
  writeRegister(0x45, 0x11); // TX Buffer - 9423515 to 9423649
  writeRegister(0x46, 0x13); // TX Buffer - 9423663 to 9423798
  writeRegister(0x04, 0x07); // TX - 9423812 to 9423946
  writeRegister(0x00, 0xFF); // CS0 - 9430593 to 9430737
  writeRegister(0x01, 0xFF); // CS1 - 9430743 to 9430883
  writeRegister(0x16, 0xC0); // FIFO CTRL - 9430897 to 9431032
  writeRegister(0x40, 0x04); // TX Buffer - 9431045 to 9431179
  writeRegister(0x41, 0x0E); // TX Buffer - 9431189 to 9431327
  writeRegister(0x44, 0x23); // TX Buffer - 9431337 to 9431475
  writeRegister(0x45, 0x11); // TX Buffer - 9431486 to 9431625
  writeRegister(0x46, 0x13); // TX Buffer - 9431634 to 9431774
  writeRegister(0x04, 0x07); // TX - 9431783 to 9431922
  writeRegister(0x00, 0xFF); // CS0 - 9438564 to 9438705
  writeRegister(0x01, 0xFF); // CS1 - 9438718 to 9438854
  writeRegister(0x16, 0xC0); // FIFO CTRL - 9438868 to 9439003
  writeRegister(0x40, 0x04); // TX Buffer - 9439016 to 9439150
  writeRegister(0x41, 0x0E); // TX Buffer - 9439163 to 9439298
  writeRegister(0x44, 0x23); // TX Buffer - 9439312 to 9439448
  writeRegister(0x45, 0x11); // TX Buffer - 9439460 to 9439596
  writeRegister(0x46, 0x13); // TX Buffer - 9439609 to 9439745
  writeRegister(0x04, 0x07); // TX - 9439758 to 9439893
  writeRegister(0x00, 0xFF); // CS0 - 9446620 to 9446761
  writeRegister(0x01, 0xFF); // CS1 - 9446773 to 9446917
  writeRegister(0x16, 0xC0); // FIFO CTRL - 9446924 to 9447066
  writeRegister(0x40, 0x04); // TX Buffer - 9447072 to 9447205
  writeRegister(0x41, 0x0E); // TX Buffer - 9447219 to 9447354
  writeRegister(0x44, 0x23); // TX Buffer - 9447368 to 9447502
  writeRegister(0x45, 0x11); // TX Buffer - 9447516 to 9447652
  writeRegister(0x46, 0x13); // TX Buffer - 9447665 to 9447801
  writeRegister(0x04, 0x07); // TX - 9447813 to 9447949
  writeRegister(0x00, 0xFF); // CS0 - 9454594 to 9454732
  writeRegister(0x01, 0xFF); // CS1 - 9454744 to 9454884
  writeRegister(0x16, 0xC0); // FIFO CTRL - 9454898 to 9455033
  writeRegister(0x40, 0x04); // TX Buffer - 9455047 to 9455180
  writeRegister(0x41, 0x0E); // TX Buffer - 9455190 to 9455328
  writeRegister(0x44, 0x23); // TX Buffer - 9455339 to 9455481
  writeRegister(0x45, 0x11); // TX Buffer - 9455487 to 9455629
  writeRegister(0x46, 0x13); // TX Buffer - 9455636 to 9455774
  writeRegister(0x04, 0x07); // TX - 9455785 to 9455926
  writeRegister(0x00, 0xFF); // CS0 - 9462566 to 9462705
  writeRegister(0x01, 0xFF); // CS1 - 9462715 to 9462857
  writeRegister(0x16, 0xC0); // FIFO CTRL - 9462869 to 9463004
  writeRegister(0x40, 0x04); // TX Buffer - 9463018 to 9463151
  writeRegister(0x41, 0x0E); // TX Buffer - 9463165 to 9463299
  writeRegister(0x44, 0x23); // TX Buffer - 9463313 to 9463449
  writeRegister(0x45, 0x11); // TX Buffer - 9463462 to 9463596
  writeRegister(0x46, 0x13); // TX Buffer - 9463610 to 9463745
  writeRegister(0x04, 0x07); // TX - 9463759 to 9463893
  writeRegister(0x00, 0xFF); // CS0 - 9470621 to 9470762
  writeRegister(0x01, 0xFF); // CS1 - 9470775 to 9470911
  writeRegister(0x16, 0xC0); // FIFO CTRL - 9470925 to 9471060
  writeRegister(0x40, 0x04); // TX Buffer - 9471073 to 9471207
  writeRegister(0x41, 0x0E); // TX Buffer - 9471220 to 9471355
  writeRegister(0x44, 0x23); // TX Buffer - 9471369 to 9471505
  writeRegister(0x45, 0x11); // TX Buffer - 9471517 to 9471652
  writeRegister(0x46, 0x13); // TX Buffer - 9471666 to 9471802
  writeRegister(0x04, 0x07); // TX - 9471815 to 9471950
  writeRegister(0x00, 0xFF); // CS0 - 9478596 to 9478733
  writeRegister(0x01, 0xFF); // CS1 - 9478746 to 9478887
  writeRegister(0x16, 0xC0); // FIFO CTRL - 9478896 to 9479034
  writeRegister(0x40, 0x04); // TX Buffer - 9479045 to 9479178
  writeRegister(0x41, 0x0E); // TX Buffer - 9479192 to 9479326
  writeRegister(0x44, 0x23); // TX Buffer - 9479340 to 9479476
  writeRegister(0x45, 0x11); // TX Buffer - 9479488 to 9479623
  writeRegister(0x46, 0x13); // TX Buffer - 9479637 to 9479780
  writeRegister(0x04, 0x07); // TX - 9479786 to 9479920
  writeRegister(0x00, 0xFF); // CS0 - 9486567 to 9486706
  writeRegister(0x01, 0xFF); // CS1 - 9486717 to 9486858
  writeRegister(0x16, 0xC0); // FIFO CTRL - 9486871 to 9487005
  writeRegister(0x40, 0x04); // TX Buffer - 9487019 to 9487152
  writeRegister(0x41, 0x0E); // TX Buffer - 9487163 to 9487301
  writeRegister(0x44, 0x23); // TX Buffer - 9487311 to 9487449
  writeRegister(0x45, 0x11); // TX Buffer - 9487460 to 9487599
  writeRegister(0x46, 0x13); // TX Buffer - 9487608 to 9487748
  writeRegister(0x04, 0x07); // TX - 9487760 to 9487896
  writeRegister(0x00, 0xFF); // CS0 - 9494623 to 9494762
  writeRegister(0x01, 0xFF); // CS1 - 9494773 to 9494914
  writeRegister(0x16, 0xC0); // FIFO CTRL - 9494926 to 9495061
  writeRegister(0x40, 0x04); // TX Buffer - 9495075 to 9495208
  writeRegister(0x41, 0x0E); // TX Buffer - 9495222 to 9495358
  writeRegister(0x44, 0x23); // TX Buffer - 9495370 to 9495506
  writeRegister(0x45, 0x11); // TX Buffer - 9495519 to 9495653
  writeRegister(0x46, 0x13); // TX Buffer - 9495667 to 9495802
  writeRegister(0x04, 0x07); // TX - 9495816 to 9495950
  writeRegister(0x00, 0xFF); // CS0 - 9502597 to 9502733
  writeRegister(0x01, 0xFF); // CS1 - 9502747 to 9502887
  writeRegister(0x16, 0xC0); // FIFO CTRL - 9502897 to 9503036
  writeRegister(0x40, 0x04); // TX Buffer - 9503046 to 9503179
  writeRegister(0x41, 0x0E); // TX Buffer - 9503193 to 9503328
  writeRegister(0x44, 0x23); // TX Buffer - 9503341 to 9503477
  writeRegister(0x45, 0x11); // TX Buffer - 9503490 to 9503624
  writeRegister(0x46, 0x13); // TX Buffer - 9503638 to 9503773
  writeRegister(0x04, 0x07); // TX - 9503787 to 9503921
  writeRegister(0x00, 0xFF); // CS0 - 9510568 to 9510712
  writeRegister(0x01, 0xFF); // CS1 - 9510718 to 9510858
  writeRegister(0x16, 0xC0); // FIFO CTRL - 9510872 to 9511007
  writeRegister(0x40, 0x04); // TX Buffer - 9511020 to 9511154
  writeRegister(0x41, 0x0E); // TX Buffer - 9511164 to 9511302
  writeRegister(0x44, 0x23); // TX Buffer - 9511312 to 9511452
  writeRegister(0x45, 0x11); // TX Buffer - 9511461 to 9511600
  writeRegister(0x46, 0x13); // TX Buffer - 9511609 to 9511749
  writeRegister(0x04, 0x07); // TX - 9511758 to 9511897
  writeRegister(0x00, 0xFF); // CS0 - 9518624 to 9518765
  writeRegister(0x01, 0xFF); // CS1 - 9518774 to 9518915
  writeRegister(0x16, 0xC0); // FIFO CTRL - 9518928 to 9519062
  writeRegister(0x40, 0x04); // TX Buffer - 9519076 to 9519209
  writeRegister(0x41, 0x0E); // TX Buffer - 9519220 to 9519358
  writeRegister(0x44, 0x23); // TX Buffer - 9519368 to 9519506
  writeRegister(0x45, 0x11); // TX Buffer - 9519517 to 9519656
  writeRegister(0x46, 0x13); // TX Buffer - 9519665 to 9519805
  writeRegister(0x04, 0x07); // TX - 9519817 to 9519953
  writeRegister(0x00, 0xFF); // CS0 - 9526595 to 9526736
  writeRegister(0x01, 0xFF); // CS1 - 9526748 to 9526892
  writeRegister(0x16, 0xC0); // FIFO CTRL - 9526899 to 9527037
  writeRegister(0x40, 0x04); // TX Buffer - 9527047 to 9527180
  writeRegister(0x41, 0x0E); // TX Buffer - 9527194 to 9527329
  writeRegister(0x44, 0x23); // TX Buffer - 9527343 to 9527477
  writeRegister(0x45, 0x11); // TX Buffer - 9527491 to 9527627
  writeRegister(0x46, 0x13); // TX Buffer - 9527640 to 9527776
  writeRegister(0x04, 0x07); // TX - 9527788 to 9527924
  writeRegister(0x00, 0xFF); // CS0 - 9534570 to 9534713
  writeRegister(0x01, 0xFF); // CS1 - 9534719 to 9534861
  writeRegister(0x16, 0xC0); // FIFO CTRL - 9534873 to 9535008
  writeRegister(0x40, 0x04); // TX Buffer - 9535022 to 9535155
  writeRegister(0x41, 0x0E); // TX Buffer - 9535165 to 9535303
  writeRegister(0x44, 0x23); // TX Buffer - 9535314 to 9535456
  writeRegister(0x45, 0x11); // TX Buffer - 9535462 to 9535604
  writeRegister(0x46, 0x13); // TX Buffer - 9535611 to 9535749
  writeRegister(0x04, 0x07); // TX - 9535760 to 9535901
  writeRegister(0x00, 0xFF); // CS0 - 9542625 to 9542769
  writeRegister(0x01, 0xFF); // CS1 - 9542775 to 9542915
  writeRegister(0x16, 0xC0); // FIFO CTRL - 9542929 to 9543064
  writeRegister(0x40, 0x04); // TX Buffer - 9543077 to 9543211
  writeRegister(0x41, 0x0E); // TX Buffer - 9543221 to 9543359
  writeRegister(0x44, 0x23); // TX Buffer - 9543369 to 9543509
  writeRegister(0x45, 0x11); // TX Buffer - 9543518 to 9543656
  writeRegister(0x46, 0x13); // TX Buffer - 9543666 to 9543806
  writeRegister(0x04, 0x07); // TX - 9543815 to 9543954
  writeRegister(0x00, 0xFF); // CS0 - 9550596 to 9550737
  writeRegister(0x01, 0xFF); // CS1 - 9550750 to 9550886
  writeRegister(0x16, 0xC0); // FIFO CTRL - 9550900 to 9551035
  writeRegister(0x40, 0x04); // TX Buffer - 9551049 to 9551182
  writeRegister(0x41, 0x0E); // TX Buffer - 9551196 to 9551330
  writeRegister(0x44, 0x23); // TX Buffer - 9551344 to 9551480
  writeRegister(0x45, 0x11); // TX Buffer - 9551492 to 9551627
  writeRegister(0x46, 0x13); // TX Buffer - 9551641 to 9551776
  writeRegister(0x04, 0x07); // TX - 9551790 to 9551925
  writeRegister(0x00, 0xFF); // CS0 - 9558571 to 9558708
  writeRegister(0x01, 0xFF); // CS1 - 9558721 to 9558862
  writeRegister(0x16, 0xC0); // FIFO CTRL - 9558871 to 9559009
  writeRegister(0x40, 0x04); // TX Buffer - 9559020 to 9559159
  writeRegister(0x41, 0x0E); // TX Buffer - 9559167 to 9559309
  writeRegister(0x44, 0x23); // TX Buffer - 9559315 to 9559457
  writeRegister(0x45, 0x11); // TX Buffer - 9559463 to 9559606
  writeRegister(0x46, 0x13); // TX Buffer - 9559612 to 9559755
  writeRegister(0x04, 0x07); // TX - 9559761 to 9559903
  writeRegister(0x00, 0xFF); // CS0 - 9566627 to 9566770
  writeRegister(0x01, 0xFF); // CS1 - 9566777 to 9566918
  writeRegister(0x16, 0xC0); // FIFO CTRL - 9566930 to 9567065
  writeRegister(0x40, 0x04); // TX Buffer - 9567079 to 9567212
  writeRegister(0x41, 0x0E); // TX Buffer - 9567222 to 9567360
  writeRegister(0x44, 0x23); // TX Buffer - 9567371 to 9567513
  writeRegister(0x45, 0x11); // TX Buffer - 9567519 to 9567661
  writeRegister(0x46, 0x13); // TX Buffer - 9567668 to 9567806
  writeRegister(0x04, 0x07); // TX - 9567817 to 9567958
  writeRegister(0x00, 0xFF); // CS0 - 9574598 to 9574737
  writeRegister(0x01, 0xFF); // CS1 - 9574751 to 9574889
  writeRegister(0x16, 0xC0); // FIFO CTRL - 9574901 to 9575036
  writeRegister(0x40, 0x04); // TX Buffer - 9575050 to 9575183
  writeRegister(0x41, 0x0E); // TX Buffer - 9575197 to 9575333
  writeRegister(0x44, 0x23); // TX Buffer - 9575345 to 9575481
  writeRegister(0x45, 0x11); // TX Buffer - 9575494 to 9575628
  writeRegister(0x46, 0x13); // TX Buffer - 9575642 to 9575777
  writeRegister(0x04, 0x07); // TX - 9575791 to 9575925
  writeRegister(0x00, 0xFF); // CS0 - 9582572 to 9582708
  writeRegister(0x01, 0xFF); // CS1 - 9582722 to 9582862
  writeRegister(0x16, 0xC0); // FIFO CTRL - 9582872 to 9583011
  writeRegister(0x40, 0x04); // TX Buffer - 9583021 to 9583154
  writeRegister(0x41, 0x0E); // TX Buffer - 9583168 to 9583303
  writeRegister(0x44, 0x23); // TX Buffer - 9583316 to 9583451
  writeRegister(0x45, 0x11); // TX Buffer - 9583465 to 9583601
  writeRegister(0x46, 0x13); // TX Buffer - 9583613 to 9583756
  writeRegister(0x04, 0x07); // TX - 9583762 to 9583896
  writeRegister(0x00, 0xFF); // CS0 - 9590628 to 9590764
  writeRegister(0x01, 0xFF); // CS1 - 9590778 to 9590919
  writeRegister(0x16, 0xC0); // FIFO CTRL - 9590928 to 9591066
  writeRegister(0x40, 0x04); // TX Buffer - 9591077 to 9591216
  writeRegister(0x41, 0x0E); // TX Buffer - 9591224 to 9591366
  writeRegister(0x44, 0x23); // TX Buffer - 9591372 to 9591514
  writeRegister(0x45, 0x11); // TX Buffer - 9591521 to 9591663
  writeRegister(0x46, 0x13); // TX Buffer - 9591669 to 9591812
  writeRegister(0x04, 0x07); // TX - 9591818 to 9591960
  writeRegister(0x00, 0xFF); // CS0 - 9598599 to 9598740
  writeRegister(0x01, 0xFF); // CS1 - 9598749 to 9598890
  writeRegister(0x16, 0xC0); // FIFO CTRL - 9598903 to 9599037
  writeRegister(0x40, 0x04); // TX Buffer - 9599051 to 9599184
  writeRegister(0x41, 0x0E); // TX Buffer - 9599198 to 9599333
  writeRegister(0x44, 0x23); // TX Buffer - 9599347 to 9599481
  writeRegister(0x45, 0x11); // TX Buffer - 9599495 to 9599631
  writeRegister(0x46, 0x13); // TX Buffer - 9599644 to 9599780
  writeRegister(0x04, 0x07); // TX - 9599792 to 9599928
  writeRegister(0x00, 0xFF); // CS0 - 9606570 to 9606711
  writeRegister(0x01, 0xFF); // CS1 - 9606723 to 9606866
  writeRegister(0x16, 0xC0); // FIFO CTRL - 9606874 to 9607012
  writeRegister(0x40, 0x04); // TX Buffer - 9607022 to 9607155
  writeRegister(0x41, 0x0E); // TX Buffer - 9607169 to 9607304
  writeRegister(0x44, 0x23); // TX Buffer - 9607318 to 9607452
  writeRegister(0x45, 0x11); // TX Buffer - 9607466 to 9607602
  writeRegister(0x46, 0x13); // TX Buffer - 9607615 to 9607751
  writeRegister(0x04, 0x07); // TX - 9607764 to 9607899
  writeRegister(0x00, 0xFF); // CS0 - 9614629 to 9614765
  writeRegister(0x01, 0xFF); // CS1 - 9614779 to 9614919
  writeRegister(0x16, 0xC0); // FIFO CTRL - 9614930 to 9615068
  writeRegister(0x40, 0x04); // TX Buffer - 9615078 to 9615211
  writeRegister(0x41, 0x0E); // TX Buffer - 9615225 to 9615360
  writeRegister(0x44, 0x23); // TX Buffer - 9615373 to 9615508
  writeRegister(0x45, 0x11); // TX Buffer - 9615522 to 9615658
  writeRegister(0x46, 0x13); // TX Buffer - 9615670 to 9615813
  writeRegister(0x04, 0x07); // TX - 9615819 to 9615955
  writeRegister(0x00, 0xFF); // CS0 - 9622600 to 9622741
  writeRegister(0x01, 0xFF); // CS1 - 9622750 to 9622890
  writeRegister(0x16, 0xC0); // FIFO CTRL - 9622904 to 9623039
  writeRegister(0x40, 0x04); // TX Buffer - 9623052 to 9623186
  writeRegister(0x41, 0x0E); // TX Buffer - 9623196 to 9623334
  writeRegister(0x44, 0x23); // TX Buffer - 9623345 to 9623484
  writeRegister(0x45, 0x11); // TX Buffer - 9623493 to 9623631
  writeRegister(0x46, 0x13); // TX Buffer - 9623641 to 9623781
  writeRegister(0x04, 0x07); // TX - 9623794 to 9623929
  writeRegister(0x00, 0xFF); // CS0 - 9630571 to 9630712
  writeRegister(0x01, 0xFF); // CS1 - 9630725 to 9630869
  writeRegister(0x16, 0xC0); // FIFO CTRL - 9630875 to 9631016
  writeRegister(0x40, 0x04); // TX Buffer - 9631024 to 9631157
  writeRegister(0x41, 0x0E); // TX Buffer - 9631171 to 9631305
  writeRegister(0x44, 0x23); // TX Buffer - 9631319 to 9631455
  writeRegister(0x45, 0x11); // TX Buffer - 9631467 to 9631602
  writeRegister(0x46, 0x13); // TX Buffer - 9631616 to 9631751
  writeRegister(0x04, 0x07); // TX - 9631765 to 9631899
  writeRegister(0x00, 0xFF); // CS0 - 9638627 to 9638768
  writeRegister(0x01, 0xFF); // CS1 - 9638780 to 9638925
  writeRegister(0x16, 0xC0); // FIFO CTRL - 9638931 to 9639069
  writeRegister(0x40, 0x04); // TX Buffer - 9639079 to 9639213
  writeRegister(0x41, 0x0E); // TX Buffer - 9639226 to 9639361
  writeRegister(0x44, 0x23); // TX Buffer - 9639375 to 9639509
  writeRegister(0x45, 0x11); // TX Buffer - 9639523 to 9639659
  writeRegister(0x46, 0x13); // TX Buffer - 9639672 to 9639808
  writeRegister(0x04, 0x07); // TX - 9639821 to 9639956
  writeRegister(0x00, 0xFF); // CS0 - 9646602 to 9646745
  writeRegister(0x01, 0xFF); // CS1 - 9646752 to 9646893
  writeRegister(0x16, 0xC0); // FIFO CTRL - 9646905 to 9647040
  writeRegister(0x40, 0x04); // TX Buffer - 9647054 to 9647187
  writeRegister(0x41, 0x0E); // TX Buffer - 9647197 to 9647337
  writeRegister(0x44, 0x23); // TX Buffer - 9647346 to 9647485
  writeRegister(0x45, 0x11); // TX Buffer - 9647494 to 9647632
  writeRegister(0x46, 0x13); // TX Buffer - 9647643 to 9647781
  writeRegister(0x04, 0x07); // TX - 9647792 to 9647929
  writeRegister(0x00, 0xFF); // CS0 - 9654573 to 9654712
  writeRegister(0x01, 0xFF); // CS1 - 9654726 to 9654864
  writeRegister(0x16, 0xC0); // FIFO CTRL - 9654876 to 9655011
  writeRegister(0x40, 0x04); // TX Buffer - 9655025 to 9655158
  writeRegister(0x41, 0x0E); // TX Buffer - 9655172 to 9655307
  writeRegister(0x44, 0x23); // TX Buffer - 9655320 to 9655456
  writeRegister(0x45, 0x11); // TX Buffer - 9655469 to 9655603
  writeRegister(0x46, 0x13); // TX Buffer - 9655617 to 9655752
  writeRegister(0x04, 0x07); // TX - 9655766 to 9655900
  writeRegister(0x00, 0xFF); // CS0 - 9662628 to 9662768
  writeRegister(0x01, 0xFF); // CS1 - 9662782 to 9662926
  writeRegister(0x16, 0xC0); // FIFO CTRL - 9662932 to 9663073
  writeRegister(0x40, 0x04); // TX Buffer - 9663081 to 9663214
  writeRegister(0x41, 0x0E); // TX Buffer - 9663228 to 9663362
  writeRegister(0x44, 0x23); // TX Buffer - 9663376 to 9663512
  writeRegister(0x45, 0x11); // TX Buffer - 9663525 to 9663659
  writeRegister(0x46, 0x13); // TX Buffer - 9663673 to 9663808
  writeRegister(0x04, 0x07); // TX - 9663822 to 9663956
  writeRegister(0x00, 0xFF); // CS0 - 9670603 to 9670739
  writeRegister(0x01, 0xFF); // CS1 - 9670753 to 9670894
  writeRegister(0x16, 0xC0); // FIFO CTRL - 9670907 to 9671041
  writeRegister(0x40, 0x04); // TX Buffer - 9671055 to 9671188
  writeRegister(0x41, 0x0E); // TX Buffer - 9671199 to 9671337
  writeRegister(0x44, 0x23); // TX Buffer - 9671347 to 9671489
  writeRegister(0x45, 0x11); // TX Buffer - 9671496 to 9671638
  writeRegister(0x46, 0x13); // TX Buffer - 9671644 to 9671784
  writeRegister(0x04, 0x07); // TX - 9671793 to 9671935
  writeRegister(0x00, 0xFF); // CS0 - 9678659 to 9678802
  writeRegister(0x01, 0xFF); // CS1 - 9678809 to 9678950
  writeRegister(0x16, 0xC0); // FIFO CTRL - 9678962 to 9679097
  writeRegister(0x40, 0x04); // TX Buffer - 9679111 to 9679244
  writeRegister(0x41, 0x0E); // TX Buffer - 9679254 to 9679393
  writeRegister(0x44, 0x23); // TX Buffer - 9679403 to 9679541
  writeRegister(0x45, 0x11); // TX Buffer - 9679551 to 9679691
  writeRegister(0x46, 0x13); // TX Buffer - 9679700 to 9679838
  writeRegister(0x04, 0x07); // TX - 9679849 to 9679986
  writeRegister(0x00, 0xFF); // CS0 - 9686630 to 9686769
  writeRegister(0x01, 0xFF); // CS1 - 9686783 to 9686921
  writeRegister(0x16, 0xC0); // FIFO CTRL - 9686934 to 9687068
  writeRegister(0x40, 0x04); // TX Buffer - 9687082 to 9687215
  writeRegister(0x41, 0x0E); // TX Buffer - 9687229 to 9687364
  writeRegister(0x44, 0x23); // TX Buffer - 9687377 to 9687512
  writeRegister(0x45, 0x11); // TX Buffer - 9687526 to 9687662
  writeRegister(0x46, 0x13); // TX Buffer - 9687674 to 9687811
  writeRegister(0x04, 0x07); // TX - 9687823 to 9687957
  writeRegister(0x00, 0xFF); // CS0 - 9694604 to 9694740
  writeRegister(0x01, 0xFF); // CS1 - 9694754 to 9694894
  writeRegister(0x16, 0xC0); // FIFO CTRL - 9694905 to 9695043
  writeRegister(0x40, 0x04); // TX Buffer - 9695053 to 9695186
  writeRegister(0x41, 0x0E); // TX Buffer - 9695200 to 9695335
  writeRegister(0x44, 0x23); // TX Buffer - 9695348 to 9695483
  writeRegister(0x45, 0x11); // TX Buffer - 9695497 to 9695633
  writeRegister(0x46, 0x13); // TX Buffer - 9695645 to 9695788
  writeRegister(0x04, 0x07); // TX - 9695794 to 9695930
  writeRegister(0x00, 0xFF); // CS0 - 9702660 to 9702796
  writeRegister(0x01, 0xFF); // CS1 - 9702810 to 9702950
  writeRegister(0x16, 0xC0); // FIFO CTRL - 9702964 to 9703100
  writeRegister(0x40, 0x04); // TX Buffer - 9703112 to 9703247
  writeRegister(0x41, 0x0E); // TX Buffer - 9703256 to 9703394
  writeRegister(0x44, 0x23); // TX Buffer - 9703404 to 9703546
  writeRegister(0x45, 0x11); // TX Buffer - 9703553 to 9703695
  writeRegister(0x46, 0x13); // TX Buffer - 9703701 to 9703841
  writeRegister(0x04, 0x07); // TX - 9703850 to 9703992
  writeRegister(0x00, 0xFF); // CS0 - 9710631 to 9710772
  writeRegister(0x01, 0xFF); // CS1 - 9710781 to 9710921
  writeRegister(0x16, 0xC0); // FIFO CTRL - 9710935 to 9711070
  writeRegister(0x40, 0x04); // TX Buffer - 9711083 to 9711217
  writeRegister(0x41, 0x0E); // TX Buffer - 9711230 to 9711365
  writeRegister(0x44, 0x23); // TX Buffer - 9711379 to 9711513
  writeRegister(0x45, 0x11); // TX Buffer - 9711527 to 9711663
  writeRegister(0x46, 0x13); // TX Buffer - 9711676 to 9711812
  writeRegister(0x04, 0x07); // TX - 9711825 to 9711960
  writeRegister(0x00, 0xFF); // CS0 - 9718606 to 9718743
  writeRegister(0x01, 0xFF); // CS1 - 9718756 to 9718897
  writeRegister(0x16, 0xC0); // FIFO CTRL - 9718906 to 9719044
  writeRegister(0x40, 0x04); // TX Buffer - 9719054 to 9719188
  writeRegister(0x41, 0x0E); // TX Buffer - 9719201 to 9719336
  writeRegister(0x44, 0x23); // TX Buffer - 9719350 to 9719486
  writeRegister(0x45, 0x11); // TX Buffer - 9719498 to 9719634
  writeRegister(0x46, 0x13); // TX Buffer - 9719647 to 9719783
  writeRegister(0x04, 0x07); // TX - 9719796 to 9719931
  writeRegister(0x00, 0xFF); // CS0 - 9726661 to 9726799
  writeRegister(0x01, 0xFF); // CS1 - 9726811 to 9726951
  writeRegister(0x16, 0xC0); // FIFO CTRL - 9726962 to 9727100
  writeRegister(0x40, 0x04); // TX Buffer - 9727110 to 9727243
  writeRegister(0x41, 0x0E); // TX Buffer - 9727257 to 9727392
  writeRegister(0x44, 0x23); // TX Buffer - 9727406 to 9727540
  writeRegister(0x45, 0x11); // TX Buffer - 9727554 to 9727690
  writeRegister(0x46, 0x13); // TX Buffer - 9727702 to 9727845
  writeRegister(0x04, 0x07); // TX - 9727851 to 9727987
  writeRegister(0x00, 0xFF); // CS0 - 9734632 to 9734772
  writeRegister(0x01, 0xFF); // CS1 - 9734782 to 9734922
  writeRegister(0x16, 0xC0); // FIFO CTRL - 9734936 to 9735071
  writeRegister(0x40, 0x04); // TX Buffer - 9735085 to 9735218
  writeRegister(0x41, 0x0E); // TX Buffer - 9735228 to 9735366
  writeRegister(0x44, 0x23); // TX Buffer - 9735377 to 9735516
  writeRegister(0x45, 0x11); // TX Buffer - 9735525 to 9735663
  writeRegister(0x46, 0x13); // TX Buffer - 9735674 to 9735812
  writeRegister(0x04, 0x07); // TX - 9735826 to 9735960
  writeRegister(0x00, 0xFF); // CS0 - 9742604 to 9742743
  writeRegister(0x01, 0xFF); // CS1 - 9742757 to 9742901
  writeRegister(0x16, 0xC0); // FIFO CTRL - 9742907 to 9743045
  writeRegister(0x40, 0x04); // TX Buffer - 9743056 to 9743189
  writeRegister(0x41, 0x0E); // TX Buffer - 9743203 to 9743337
  writeRegister(0x44, 0x23); // TX Buffer - 9743351 to 9743487
  writeRegister(0x45, 0x11); // TX Buffer - 9743500 to 9743634
  writeRegister(0x46, 0x13); // TX Buffer - 9743648 to 9743783
  writeRegister(0x04, 0x07); // TX - 9743797 to 9743931
  writeRegister(0x00, 0xFF); // CS0 - 9750663 to 9750800
  writeRegister(0x01, 0xFF); // CS1 - 9750813 to 9750954
  writeRegister(0x16, 0xC0); // FIFO CTRL - 9750963 to 9751101
  writeRegister(0x40, 0x04); // TX Buffer - 9751111 to 9751245
  writeRegister(0x41, 0x0E); // TX Buffer - 9751258 to 9751393
  writeRegister(0x44, 0x23); // TX Buffer - 9751407 to 9751543
  writeRegister(0x45, 0x11); // TX Buffer - 9751555 to 9751690
  writeRegister(0x46, 0x13); // TX Buffer - 9751704 to 9751840
  writeRegister(0x04, 0x07); // TX - 9751853 to 9751988
  writeRegister(0x00, 0xFF); // CS0 - 9758634 to 9758777
  writeRegister(0x01, 0xFF); // CS1 - 9758784 to 9758925
  writeRegister(0x16, 0xC0); // FIFO CTRL - 9758938 to 9759072
  writeRegister(0x40, 0x04); // TX Buffer - 9759086 to 9759219
  writeRegister(0x41, 0x0E); // TX Buffer - 9759230 to 9759368
  writeRegister(0x44, 0x23); // TX Buffer - 9759378 to 9759516
  writeRegister(0x45, 0x11); // TX Buffer - 9759526 to 9759666
  writeRegister(0x46, 0x13); // TX Buffer - 9759675 to 9759813
  writeRegister(0x04, 0x07); // TX - 9759824 to 9759961
  writeRegister(0x00, 0xFF); // CS0 - 9766605 to 9766744
  writeRegister(0x01, 0xFF); // CS1 - 9766758 to 9766896
  writeRegister(0x16, 0xC0); // FIFO CTRL - 9766909 to 9767043
  writeRegister(0x40, 0x04); // TX Buffer - 9767057 to 9767190
  writeRegister(0x41, 0x0E); // TX Buffer - 9767204 to 9767339
  writeRegister(0x44, 0x23); // TX Buffer - 9767352 to 9767487
  writeRegister(0x45, 0x11); // TX Buffer - 9767501 to 9767637
  writeRegister(0x46, 0x13); // TX Buffer - 9767649 to 9767786
  writeRegister(0x04, 0x07); // TX - 9767798 to 9767934
  writeRegister(0x00, 0xFF); // CS0 - 9774661 to 9774800
  writeRegister(0x01, 0xFF); // CS1 - 9774814 to 9774958
  writeRegister(0x16, 0xC0); // FIFO CTRL - 9774964 to 9775102
  writeRegister(0x40, 0x04); // TX Buffer - 9775113 to 9775246
  writeRegister(0x41, 0x0E); // TX Buffer - 9775260 to 9775396
  writeRegister(0x44, 0x23); // TX Buffer - 9775408 to 9775544
  writeRegister(0x45, 0x11); // TX Buffer - 9775557 to 9775691
  writeRegister(0x46, 0x13); // TX Buffer - 9775705 to 9775840
  writeRegister(0x04, 0x07); // TX - 9775854 to 9775988
  writeRegister(0x00, 0xFF); // CS0 - 9782635 to 9782779
  writeRegister(0x01, 0xFF); // CS1 - 9782785 to 9782925
  writeRegister(0x16, 0xC0); // FIFO CTRL - 9782939 to 9783075
  writeRegister(0x40, 0x04); // TX Buffer - 9783087 to 9783222
  writeRegister(0x41, 0x0E); // TX Buffer - 9783231 to 9783369
  writeRegister(0x44, 0x23); // TX Buffer - 9783379 to 9783521
  writeRegister(0x45, 0x11); // TX Buffer - 9783528 to 9783670
  writeRegister(0x46, 0x13); // TX Buffer - 9783676 to 9783816
  writeRegister(0x04, 0x07); // TX - 9783825 to 9783967
  writeRegister(0x00, 0xFF); // CS0 - 9790606 to 9790747
  writeRegister(0x01, 0xFF); // CS1 - 9790759 to 9790896
  writeRegister(0x16, 0xC0); // FIFO CTRL - 9790910 to 9791045
  writeRegister(0x40, 0x04); // TX Buffer - 9791058 to 9791192
  writeRegister(0x41, 0x0E); // TX Buffer - 9791205 to 9791340
  writeRegister(0x44, 0x23); // TX Buffer - 9791354 to 9791488
  writeRegister(0x45, 0x11); // TX Buffer - 9791502 to 9791638
  writeRegister(0x46, 0x13); // TX Buffer - 9791651 to 9791787
  writeRegister(0x04, 0x07); // TX - 9791800 to 9791935
  writeRegister(0x00, 0xFF); // CS0 - 9798662 to 9798803
  writeRegister(0x01, 0xFF); // CS1 - 9798815 to 9798953
  writeRegister(0x16, 0xC0); // FIFO CTRL - 9798966 to 9799100
  writeRegister(0x40, 0x04); // TX Buffer - 9799114 to 9799247
  writeRegister(0x41, 0x0E); // TX Buffer - 9799261 to 9799396
  writeRegister(0x44, 0x23); // TX Buffer - 9799410 to 9799544
  writeRegister(0x45, 0x11); // TX Buffer - 9799558 to 9799694
  writeRegister(0x46, 0x13); // TX Buffer - 9799706 to 9799843
  writeRegister(0x04, 0x07); // TX - 9799855 to 9799991
  writeRegister(0x00, 0xFF); // CS0 - 9806636 to 9806774
  writeRegister(0x01, 0xFF); // CS1 - 9806786 to 9806926
  writeRegister(0x16, 0xC0); // FIFO CTRL - 9806937 to 9807075
  writeRegister(0x40, 0x04); // TX Buffer - 9807085 to 9807226
  writeRegister(0x41, 0x0E); // TX Buffer - 9807232 to 9807373
  writeRegister(0x44, 0x23); // TX Buffer - 9807381 to 9807523
  writeRegister(0x45, 0x11); // TX Buffer - 9807529 to 9807671
  writeRegister(0x46, 0x13); // TX Buffer - 9807678 to 9807820
  writeRegister(0x04, 0x07); // TX - 9807826 to 9807968
  writeRegister(0x00, 0xFF); // CS0 - 9814607 to 9814747
  writeRegister(0x01, 0xFF); // CS1 - 9814757 to 9814897
  writeRegister(0x16, 0xC0); // FIFO CTRL - 9814911 to 9815046
  writeRegister(0x40, 0x04); // TX Buffer - 9815060 to 9815193
  writeRegister(0x41, 0x0E); // TX Buffer - 9815207 to 9815341
  writeRegister(0x44, 0x23); // TX Buffer - 9815355 to 9815491
  writeRegister(0x45, 0x11); // TX Buffer - 9815504 to 9815638
  writeRegister(0x46, 0x13); // TX Buffer - 9815652 to 9815787
  writeRegister(0x04, 0x07); // TX - 9815801 to 9815935
  writeRegister(0x00, 0xFF); // CS0 - 9822663 to 9822804
  writeRegister(0x01, 0xFF); // CS1 - 9822817 to 9822953
  writeRegister(0x16, 0xC0); // FIFO CTRL - 9822967 to 9823102
  writeRegister(0x40, 0x04); // TX Buffer - 9823115 to 9823249
  writeRegister(0x41, 0x0E); // TX Buffer - 9823262 to 9823397
  writeRegister(0x44, 0x23); // TX Buffer - 9823411 to 9823547
  writeRegister(0x45, 0x11); // TX Buffer - 9823559 to 9823694
  writeRegister(0x46, 0x13); // TX Buffer - 9823708 to 9823844
  writeRegister(0x04, 0x07); // TX - 9823857 to 9823992
  writeRegister(0x00, 0xFF); // CS0 - 9830638 to 9830775
  writeRegister(0x01, 0xFF); // CS1 - 9830788 to 9830929
  writeRegister(0x16, 0xC0); // FIFO CTRL - 9830938 to 9831076
  writeRegister(0x40, 0x04); // TX Buffer - 9831087 to 9831220
  writeRegister(0x41, 0x0E); // TX Buffer - 9831233 to 9831368
  writeRegister(0x44, 0x23); // TX Buffer - 9831382 to 9831518
  writeRegister(0x45, 0x11); // TX Buffer - 9831530 to 9831665
  writeRegister(0x46, 0x13); // TX Buffer - 9831679 to 9831821
  writeRegister(0x04, 0x07); // TX - 9831828 to 9831963
  writeRegister(0x00, 0xFF); // CS0 - 9838609 to 9838748
  writeRegister(0x01, 0xFF); // CS1 - 9838759 to 9838900
  writeRegister(0x16, 0xC0); // FIFO CTRL - 9838913 to 9839047
  writeRegister(0x40, 0x04); // TX Buffer - 9839061 to 9839194
  writeRegister(0x41, 0x0E); // TX Buffer - 9839205 to 9839343
  writeRegister(0x44, 0x23); // TX Buffer - 9839353 to 9839491
  writeRegister(0x45, 0x11); // TX Buffer - 9839501 to 9839641
  writeRegister(0x46, 0x13); // TX Buffer - 9839650 to 9839790
  writeRegister(0x04, 0x07); // TX - 9839802 to 9839936
  writeRegister(0x00, 0xFF); // CS0 - 9846665 to 9846804
  writeRegister(0x01, 0xFF); // CS1 - 9846815 to 9846956
  writeRegister(0x16, 0xC0); // FIFO CTRL - 9846968 to 9847103
  writeRegister(0x40, 0x04); // TX Buffer - 9847117 to 9847250
  writeRegister(0x41, 0x0E); // TX Buffer - 9847264 to 9847398
  writeRegister(0x44, 0x23); // TX Buffer - 9847412 to 9847548
  writeRegister(0x45, 0x11); // TX Buffer - 9847561 to 9847695
  writeRegister(0x46, 0x13); // TX Buffer - 9847709 to 9847844
  writeRegister(0x04, 0x07); // TX - 9847858 to 9847992
  writeRegister(0x00, 0xFF); // CS0 - 9854636 to 9854775
  writeRegister(0x01, 0xFF); // CS1 - 9854789 to 9854933
  writeRegister(0x16, 0xC0); // FIFO CTRL - 9854939 to 9855079
  writeRegister(0x40, 0x04); // TX Buffer - 9855088 to 9855221
  writeRegister(0x41, 0x0E); // TX Buffer - 9855235 to 9855371
  writeRegister(0x44, 0x23); // TX Buffer - 9855383 to 9855519
  writeRegister(0x45, 0x11); // TX Buffer - 9855532 to 9855666
  writeRegister(0x46, 0x13); // TX Buffer - 9855680 to 9855815
  writeRegister(0x04, 0x07); // TX - 9855829 to 9855963
  writeRegister(0x00, 0xFF); // CS0 - 9862610 to 9862754
  writeRegister(0x01, 0xFF); // CS1 - 9862760 to 9862900
  writeRegister(0x16, 0xC0); // FIFO CTRL - 9862914 to 9863049
  writeRegister(0x40, 0x04); // TX Buffer - 9863062 to 9863196
  writeRegister(0x41, 0x0E); // TX Buffer - 9863206 to 9863344
  writeRegister(0x44, 0x23); // TX Buffer - 9863354 to 9863492
  writeRegister(0x45, 0x11); // TX Buffer - 9863503 to 9863642
  writeRegister(0x46, 0x13); // TX Buffer - 9863651 to 9863791
  writeRegister(0x04, 0x07); // TX - 9863800 to 9863939
  writeRegister(0x00, 0xFF); // CS0 - 9870666 to 9870807
  writeRegister(0x01, 0xFF); // CS1 - 9870816 to 9870957
  writeRegister(0x16, 0xC0); // FIFO CTRL - 9870970 to 9871104
  writeRegister(0x40, 0x04); // TX Buffer - 9871118 to 9871251
  writeRegister(0x41, 0x0E); // TX Buffer - 9871262 to 9871400
  writeRegister(0x44, 0x23); // TX Buffer - 9871410 to 9871548
  writeRegister(0x45, 0x11); // TX Buffer - 9871559 to 9871698
  writeRegister(0x46, 0x13); // TX Buffer - 9871707 to 9871847
  writeRegister(0x04, 0x07); // TX - 9871859 to 9871995
  writeRegister(0x00, 0xFF); // CS0 - 9878637 to 9878778
  writeRegister(0x01, 0xFF); // CS1 - 9878790 to 9878934
  writeRegister(0x16, 0xC0); // FIFO CTRL - 9878941 to 9879083
  writeRegister(0x40, 0x04); // TX Buffer - 9879089 to 9879222
  writeRegister(0x41, 0x0E); // TX Buffer - 9879236 to 9879371
  writeRegister(0x44, 0x23); // TX Buffer - 9879385 to 9879519
  writeRegister(0x45, 0x11); // TX Buffer - 9879533 to 9879669
  writeRegister(0x46, 0x13); // TX Buffer - 9879681 to 9879818
  writeRegister(0x04, 0x07); // TX - 9879830 to 9879966
  writeRegister(0x00, 0xFF); // CS0 - 9886611 to 9886749
  writeRegister(0x01, 0xFF); // CS1 - 9886761 to 9886901
  writeRegister(0x16, 0xC0); // FIFO CTRL - 9886915 to 9887050
  writeRegister(0x40, 0x04); // TX Buffer - 9887064 to 9887197
  writeRegister(0x41, 0x0E); // TX Buffer - 9887207 to 9887345
  writeRegister(0x44, 0x23); // TX Buffer - 9887356 to 9887498
  writeRegister(0x45, 0x11); // TX Buffer - 9887504 to 9887646
  writeRegister(0x46, 0x13); // TX Buffer - 9887653 to 9887791
  writeRegister(0x04, 0x07); // TX - 9887801 to 9887943
  writeRegister(0x00, 0xFF); // CS0 - 9894667 to 9894811
  writeRegister(0x01, 0xFF); // CS1 - 9894817 to 9894957
  writeRegister(0x16, 0xC0); // FIFO CTRL - 9894971 to 9895106
  writeRegister(0x40, 0x04); // TX Buffer - 9895119 to 9895253
  writeRegister(0x41, 0x0E); // TX Buffer - 9895263 to 9895401
  writeRegister(0x44, 0x23); // TX Buffer - 9895411 to 9895551
  writeRegister(0x45, 0x11); // TX Buffer - 9895560 to 9895699
  writeRegister(0x46, 0x13); // TX Buffer - 9895708 to 9895848
  writeRegister(0x04, 0x07); // TX - 9895857 to 9895996
  writeRegister(0x00, 0xFF); // CS0 - 9902638 to 9902779
  writeRegister(0x01, 0xFF); // CS1 - 9902792 to 9902928
  writeRegister(0x16, 0xC0); // FIFO CTRL - 9902942 to 9903077
  writeRegister(0x40, 0x04); // TX Buffer - 9903090 to 9903224
  writeRegister(0x41, 0x0E); // TX Buffer - 9903237 to 9903372
  writeRegister(0x44, 0x23); // TX Buffer - 9903386 to 9903522
  writeRegister(0x45, 0x11); // TX Buffer - 9903534 to 9903669
  writeRegister(0x46, 0x13); // TX Buffer - 9903683 to 9903819
  writeRegister(0x04, 0x07); // TX - 9903832 to 9903967
  writeRegister(0x00, 0xFF); // CS0 - 9910613 to 9910750
  writeRegister(0x01, 0xFF); // CS1 - 9910763 to 9910904
  writeRegister(0x16, 0xC0); // FIFO CTRL - 9910913 to 9911051
  writeRegister(0x40, 0x04); // TX Buffer - 9911062 to 9911195
  writeRegister(0x41, 0x0E); // TX Buffer - 9911209 to 9911343
  writeRegister(0x44, 0x23); // TX Buffer - 9911357 to 9911493
  writeRegister(0x45, 0x11); // TX Buffer - 9911505 to 9911640
  writeRegister(0x46, 0x13); // TX Buffer - 9911654 to 9911795
  writeRegister(0x04, 0x07); // TX - 9911803 to 9911938
  writeRegister(0x00, 0xFF); // CS0 - 9918669 to 9918806
  writeRegister(0x01, 0xFF); // CS1 - 9918818 to 9918960
  writeRegister(0x16, 0xC0); // FIFO CTRL - 9918972 to 9919107
  writeRegister(0x40, 0x04); // TX Buffer - 9919121 to 9919254
  writeRegister(0x41, 0x0E); // TX Buffer - 9919264 to 9919402
  writeRegister(0x44, 0x23); // TX Buffer - 9919413 to 9919555
  writeRegister(0x45, 0x11); // TX Buffer - 9919561 to 9919703
  writeRegister(0x46, 0x13); // TX Buffer - 9919710 to 9919848
  writeRegister(0x04, 0x07); // TX - 9919859 to 9920000
  writeRegister(0x00, 0xFF); // CS0 - 9926640 to 9926779
  writeRegister(0x01, 0xFF); // CS1 - 9926790 to 9926931
  writeRegister(0x16, 0xC0); // FIFO CTRL - 9926943 to 9927078
  writeRegister(0x40, 0x04); // TX Buffer - 9927092 to 9927225
  writeRegister(0x41, 0x0E); // TX Buffer - 9927239 to 9927375
  writeRegister(0x44, 0x23); // TX Buffer - 9927387 to 9927523
  writeRegister(0x45, 0x11); // TX Buffer - 9927536 to 9927670
  writeRegister(0x46, 0x13); // TX Buffer - 9927684 to 9927819
  writeRegister(0x04, 0x07); // TX - 9927833 to 9927967
  writeRegister(0x00, 0xFF); // CS0 - 9934614 to 9934750
  writeRegister(0x01, 0xFF); // CS1 - 9934764 to 9934904
  writeRegister(0x16, 0xC0); // FIFO CTRL - 9934914 to 9935054
  writeRegister(0x40, 0x04); // TX Buffer - 9935063 to 9935196
  writeRegister(0x41, 0x0E); // TX Buffer - 9935210 to 9935345
  writeRegister(0x44, 0x23); // TX Buffer - 9935358 to 9935494
  writeRegister(0x45, 0x11); // TX Buffer - 9935507 to 9935641
  writeRegister(0x46, 0x13); // TX Buffer - 9935655 to 9935790
  writeRegister(0x04, 0x07); // TX - 9935804 to 9935938
  writeRegister(0x00, 0xFF); // CS0 - 9942670 to 9942806
  writeRegister(0x01, 0xFF); // CS1 - 9942820 to 9942961
  writeRegister(0x16, 0xC0); // FIFO CTRL - 9942970 to 9943108
  writeRegister(0x40, 0x04); // TX Buffer - 9943119 to 9943252
  writeRegister(0x41, 0x0E); // TX Buffer - 9943266 to 9943400
  writeRegister(0x44, 0x23); // TX Buffer - 9943414 to 9943550
  writeRegister(0x45, 0x11); // TX Buffer - 9943563 to 9943697
  writeRegister(0x46, 0x13); // TX Buffer - 9943711 to 9943854
  writeRegister(0x04, 0x07); // TX - 9943860 to 9943994
  writeRegister(0x00, 0xFF); // CS0 - 9950641 to 9950782
  writeRegister(0x01, 0xFF); // CS1 - 9950791 to 9950932
  writeRegister(0x16, 0xC0); // FIFO CTRL - 9950945 to 9951079
  writeRegister(0x40, 0x04); // TX Buffer - 9951093 to 9951226
  writeRegister(0x41, 0x0E); // TX Buffer - 9951237 to 9951375
  writeRegister(0x44, 0x23); // TX Buffer - 9951385 to 9951523
  writeRegister(0x45, 0x11); // TX Buffer - 9951534 to 9951673
  writeRegister(0x46, 0x13); // TX Buffer - 9951682 to 9951822
  writeRegister(0x04, 0x07); // TX - 9951834 to 9951970
  writeRegister(0x00, 0xFF); // CS0 - 9958612 to 9958753
  writeRegister(0x01, 0xFF); // CS1 - 9958765 to 9958909
  writeRegister(0x16, 0xC0); // FIFO CTRL - 9958916 to 9959054
  writeRegister(0x40, 0x04); // TX Buffer - 9959064 to 9959197
  writeRegister(0x41, 0x0E); // TX Buffer - 9959211 to 9959346
  writeRegister(0x44, 0x23); // TX Buffer - 9959360 to 9959494
  writeRegister(0x45, 0x11); // TX Buffer - 9959508 to 9959644
  writeRegister(0x46, 0x13); // TX Buffer - 9959657 to 9959793
  writeRegister(0x04, 0x07); // TX - 9959805 to 9959941
  writeRegister(0x00, 0xFF); // CS0 - 9966671 to 9966807
  writeRegister(0x01, 0xFF); // CS1 - 9966821 to 9966961
  writeRegister(0x16, 0xC0); // FIFO CTRL - 9966972 to 9967110
  writeRegister(0x40, 0x04); // TX Buffer - 9967120 to 9967253
  writeRegister(0x41, 0x0E); // TX Buffer - 9967267 to 9967402
  writeRegister(0x44, 0x23); // TX Buffer - 9967415 to 9967550
  writeRegister(0x45, 0x11); // TX Buffer - 9967564 to 9967700
  writeRegister(0x46, 0x13); // TX Buffer - 9967712 to 9967849
  writeRegister(0x04, 0x07); // TX - 9967861 to 9967995
  writeRegister(0x00, 0xFF); // CS0 - 9974642 to 9974786
  writeRegister(0x01, 0xFF); // CS1 - 9974792 to 9974932
  writeRegister(0x16, 0xC0); // FIFO CTRL - 9974946 to 9975081
  writeRegister(0x40, 0x04); // TX Buffer - 9975094 to 9975228
  writeRegister(0x41, 0x0E); // TX Buffer - 9975238 to 9975376
  writeRegister(0x44, 0x23); // TX Buffer - 9975386 to 9975526
  writeRegister(0x45, 0x11); // TX Buffer - 9975535 to 9975674
  writeRegister(0x46, 0x13); // TX Buffer - 9975683 to 9975823
  writeRegister(0x04, 0x07); // TX - 9975832 to 9975971
  writeRegister(0x00, 0xFF); // CS0 - 9982613 to 9982754
  writeRegister(0x01, 0xFF); // CS1 - 9982767 to 9982903
  writeRegister(0x16, 0xC0); // FIFO CTRL - 9982917 to 9983052
  writeRegister(0x40, 0x04); // TX Buffer - 9983066 to 9983199
  writeRegister(0x41, 0x0E); // TX Buffer - 9983212 to 9983347
  writeRegister(0x44, 0x23); // TX Buffer - 9983361 to 9983497
  writeRegister(0x45, 0x11); // TX Buffer - 9983509 to 9983644
  writeRegister(0x46, 0x13); // TX Buffer - 9983658 to 9983794
  writeRegister(0x04, 0x07); // TX - 9983807 to 9983942
  writeRegister(0x00, 0xFF); // CS0 - 9990669 to 9990810
  writeRegister(0x01, 0xFF); // CS1 - 9990822 to 9990967
  writeRegister(0x16, 0xC0); // FIFO CTRL - 9990973 to 9991111
  writeRegister(0x40, 0x04); // TX Buffer - 9991121 to 9991256
  writeRegister(0x41, 0x0E); // TX Buffer - 9991268 to 9991403
  writeRegister(0x44, 0x23); // TX Buffer - 9991417 to 9991551
  writeRegister(0x45, 0x11); // TX Buffer - 9991565 to 9991701
  writeRegister(0x46, 0x13); // TX Buffer - 9991714 to 9991850
  writeRegister(0x04, 0x07); // TX - 9991863 to 9991998
  writeRegister(0x00, 0xFF); // CS0 - 9998644 to 9998787
  writeRegister(0x01, 0xFF); // CS1 - 9998793 to 9998935
  writeRegister(0x16, 0xC0); // FIFO CTRL - 9998947 to 9999082
  writeRegister(0x40, 0x04); // TX Buffer - 9999096 to 9999229
  writeRegister(0x41, 0x0E); // TX Buffer - 9999239 to 9999377
  writeRegister(0x44, 0x23); // TX Buffer - 9999388 to 9999530
  writeRegister(0x45, 0x11); // TX Buffer - 9999536 to 9999678
  writeRegister(0x46, 0x13); // TX Buffer - 9999685 to 9999823
  writeRegister(0x04, 0x07); // TX - 9999834 to 9999975
  writeRegister(0x00, 0xFF); // CS0 - 10006615 to 10006754
  writeRegister(0x01, 0xFF); // CS1 - 10006768 to 10006906
  writeRegister(0x16, 0xC0); // FIFO CTRL - 10006918 to 10007053
  writeRegister(0x40, 0x04); // TX Buffer - 10007067 to 10007200
  writeRegister(0x41, 0x0E); // TX Buffer - 10007214 to 10007350
  writeRegister(0x44, 0x23); // TX Buffer - 10007362 to 10007498
  writeRegister(0x45, 0x11); // TX Buffer - 10007511 to 10007645
  writeRegister(0x46, 0x13); // TX Buffer - 10007659 to 10007794
  writeRegister(0x04, 0x07); // TX - 10007808 to 10007942
  writeRegister(0x00, 0xFF); // CS0 - 10014670 to 10014811
  writeRegister(0x01, 0xFF); // CS1 - 10014824 to 10014960
  writeRegister(0x16, 0xC0); // FIFO CTRL - 10014974 to 10015109
  writeRegister(0x40, 0x04); // TX Buffer - 10015123 to 10015256
  writeRegister(0x41, 0x0E); // TX Buffer - 10015270 to 10015404
  writeRegister(0x44, 0x23); // TX Buffer - 10015418 to 10015554
  writeRegister(0x45, 0x11); // TX Buffer - 10015566 to 10015701
  writeRegister(0x46, 0x13); // TX Buffer - 10015715 to 10015850
  writeRegister(0x04, 0x07); // TX - 10015864 to 10015998
  writeRegister(0x00, 0xFF); // CS0 - 10022645 to 10022781
  writeRegister(0x01, 0xFF); // CS1 - 10022795 to 10022936
  writeRegister(0x16, 0xC0); // FIFO CTRL - 10022945 to 10023083
  writeRegister(0x40, 0x04); // TX Buffer - 10023094 to 10023233
  writeRegister(0x41, 0x0E); // TX Buffer - 10023241 to 10023383
  writeRegister(0x44, 0x23); // TX Buffer - 10023389 to 10023531
  writeRegister(0x45, 0x11); // TX Buffer - 10023538 to 10023680
  writeRegister(0x46, 0x13); // TX Buffer - 10023686 to 10023829
  writeRegister(0x04, 0x07); // TX - 10023835 to 10023977
  writeRegister(0x00, 0xFF); // CS0 - 10030616 to 10030757
  writeRegister(0x01, 0xFF); // CS1 - 10030766 to 10030907
  writeRegister(0x16, 0xC0); // FIFO CTRL - 10030920 to 10031054
  writeRegister(0x40, 0x04); // TX Buffer - 10031068 to 10031201
  writeRegister(0x41, 0x0E); // TX Buffer - 10031215 to 10031350
  writeRegister(0x44, 0x23); // TX Buffer - 10031364 to 10031498
  writeRegister(0x45, 0x11); // TX Buffer - 10031512 to 10031648
  writeRegister(0x46, 0x13); // TX Buffer - 10031660 to 10031797
  writeRegister(0x04, 0x07); // TX - 10031809 to 10031945
  writeRegister(0x00, 0xFF); // CS0 - 10038672 to 10038811
  writeRegister(0x01, 0xFF); // CS1 - 10038825 to 10038963
  writeRegister(0x16, 0xC0); // FIFO CTRL - 10038975 to 10039110
  writeRegister(0x40, 0x04); // TX Buffer - 10039124 to 10039257
  writeRegister(0x41, 0x0E); // TX Buffer - 10039271 to 10039406
  writeRegister(0x44, 0x23); // TX Buffer - 10039419 to 10039554
  writeRegister(0x45, 0x11); // TX Buffer - 10039568 to 10039704
  writeRegister(0x46, 0x13); // TX Buffer - 10039716 to 10039851
  writeRegister(0x04, 0x07); // TX - 10039865 to 10039999
  writeRegister(0x00, 0xFF); // CS0 - 10046646 to 10046782
  writeRegister(0x01, 0xFF); // CS1 - 10046796 to 10046936
  writeRegister(0x16, 0xC0); // FIFO CTRL - 10046947 to 10047085
  writeRegister(0x40, 0x04); // TX Buffer - 10047095 to 10047228
  writeRegister(0x41, 0x0E); // TX Buffer - 10047242 to 10047377
  writeRegister(0x44, 0x23); // TX Buffer - 10047390 to 10047525
  writeRegister(0x45, 0x11); // TX Buffer - 10047539 to 10047675
  writeRegister(0x46, 0x13); // TX Buffer - 10047687 to 10047830
  writeRegister(0x04, 0x07); // TX - 10047836 to 10047970
  writeRegister(0x00, 0xFF); // CS0 - 10054617 to 10054758
  writeRegister(0x01, 0xFF); // CS1 - 10054767 to 10054907
  writeRegister(0x16, 0xC0); // FIFO CTRL - 10054921 to 10055056
  writeRegister(0x40, 0x04); // TX Buffer - 10055069 to 10055203
  writeRegister(0x41, 0x0E); // TX Buffer - 10055213 to 10055351
  writeRegister(0x44, 0x23); // TX Buffer - 10055361 to 10055501
  writeRegister(0x45, 0x11); // TX Buffer - 10055510 to 10055648
  writeRegister(0x46, 0x13); // TX Buffer - 10055658 to 10055798
  writeRegister(0x04, 0x07); // TX - 10055811 to 10055946
  writeRegister(0x00, 0xFF); // CS0 - 10062673 to 10062814
  writeRegister(0x01, 0xFF); // CS1 - 10062823 to 10062963
  writeRegister(0x16, 0xC0); // FIFO CTRL - 10062977 to 10063113
  writeRegister(0x40, 0x04); // TX Buffer - 10063125 to 10063260
  writeRegister(0x41, 0x0E); // TX Buffer - 10063272 to 10063407
  writeRegister(0x44, 0x23); // TX Buffer - 10063421 to 10063555
  writeRegister(0x45, 0x11); // TX Buffer - 10063569 to 10063705
  writeRegister(0x46, 0x13); // TX Buffer - 10063718 to 10063854
  writeRegister(0x04, 0x07); // TX - 10063867 to 10064002
  writeRegister(0x00, 0xFF); // CS0 - 10070644 to 10070785
  writeRegister(0x01, 0xFF); // CS1 - 10070797 to 10070942
  writeRegister(0x16, 0xC0); // FIFO CTRL - 10070948 to 10071086
  writeRegister(0x40, 0x04); // TX Buffer - 10071096 to 10071230
  writeRegister(0x41, 0x0E); // TX Buffer - 10071243 to 10071378
  writeRegister(0x44, 0x23); // TX Buffer - 10071392 to 10071526
  writeRegister(0x45, 0x11); // TX Buffer - 10071540 to 10071676
  writeRegister(0x46, 0x13); // TX Buffer - 10071689 to 10071825
  writeRegister(0x04, 0x07); // TX - 10071838 to 10071973
  writeRegister(0x00, 0xFF); // CS0 - 10078619 to 10078762
  writeRegister(0x01, 0xFF); // CS1 - 10078769 to 10078910
  writeRegister(0x16, 0xC0); // FIFO CTRL - 10078922 to 10079057
  writeRegister(0x40, 0x04); // TX Buffer - 10079071 to 10079204
  writeRegister(0x41, 0x0E); // TX Buffer - 10079214 to 10079352
  writeRegister(0x44, 0x23); // TX Buffer - 10079363 to 10079502
  writeRegister(0x45, 0x11); // TX Buffer - 10079511 to 10079649
  writeRegister(0x46, 0x13); // TX Buffer - 10079660 to 10079798
  writeRegister(0x04, 0x07); // TX - 10079809 to 10079946
  writeRegister(0x00, 0xFF); // CS0 - 10086674 to 10086815
  writeRegister(0x01, 0xFF); // CS1 - 10086824 to 10086964
  writeRegister(0x16, 0xC0); // FIFO CTRL - 10086978 to 10087113
  writeRegister(0x40, 0x04); // TX Buffer - 10087127 to 10087260
  writeRegister(0x41, 0x0E); // TX Buffer - 10087270 to 10087408
  writeRegister(0x44, 0x23); // TX Buffer - 10087419 to 10087558
  writeRegister(0x45, 0x11); // TX Buffer - 10087567 to 10087705
  writeRegister(0x46, 0x13); // TX Buffer - 10087715 to 10087854
  writeRegister(0x04, 0x07); // TX - 10087868 to 10088002
  writeRegister(0x00, 0xFF); // CS0 - 10094645 to 10094785
  writeRegister(0x01, 0xFF); // CS1 - 10094799 to 10094943
  writeRegister(0x16, 0xC0); // FIFO CTRL - 10094949 to 10095090
  writeRegister(0x40, 0x04); // TX Buffer - 10095098 to 10095231
  writeRegister(0x41, 0x0E); // TX Buffer - 10095245 to 10095379
  writeRegister(0x44, 0x23); // TX Buffer - 10095393 to 10095529
  writeRegister(0x45, 0x11); // TX Buffer - 10095542 to 10095676
  writeRegister(0x46, 0x13); // TX Buffer - 10095690 to 10095825
  writeRegister(0x04, 0x07); // TX - 10095839 to 10095973
  writeRegister(0x00, 0xFF); // CS0 - 10102620 to 10102756
  writeRegister(0x01, 0xFF); // CS1 - 10102770 to 10102911
  writeRegister(0x16, 0xC0); // FIFO CTRL - 10102924 to 10103058
  writeRegister(0x40, 0x04); // TX Buffer - 10103072 to 10103205
  writeRegister(0x41, 0x0E); // TX Buffer - 10103216 to 10103354
  writeRegister(0x44, 0x23); // TX Buffer - 10103364 to 10103506
  writeRegister(0x45, 0x11); // TX Buffer - 10103513 to 10103655
  writeRegister(0x46, 0x13); // TX Buffer - 10103661 to 10103801
  writeRegister(0x04, 0x07); // TX - 10103810 to 10103952
  writeRegister(0x00, 0xFF); // CS0 - 10110676 to 10110819
  writeRegister(0x01, 0xFF); // CS1 - 10110826 to 10110967
  writeRegister(0x16, 0xC0); // FIFO CTRL - 10110979 to 10111114
  writeRegister(0x40, 0x04); // TX Buffer - 10111128 to 10111261
  writeRegister(0x41, 0x0E); // TX Buffer - 10111271 to 10111410
  writeRegister(0x44, 0x23); // TX Buffer - 10111420 to 10111558
  writeRegister(0x45, 0x11); // TX Buffer - 10111568 to 10111708
  writeRegister(0x46, 0x13); // TX Buffer - 10111717 to 10111855
  writeRegister(0x04, 0x07); // TX - 10111866 to 10112003
  writeRegister(0x00, 0xFF); // CS0 - 10118647 to 10118786
  writeRegister(0x01, 0xFF); // CS1 - 10118800 to 10118938
  writeRegister(0x16, 0xC0); // FIFO CTRL - 10118951 to 10119085
  writeRegister(0x40, 0x04); // TX Buffer - 10119099 to 10119232
  writeRegister(0x41, 0x0E); // TX Buffer - 10119246 to 10119381
  writeRegister(0x44, 0x23); // TX Buffer - 10119394 to 10119529
  writeRegister(0x45, 0x11); // TX Buffer - 10119543 to 10119679
  writeRegister(0x46, 0x13); // TX Buffer - 10119691 to 10119828
  writeRegister(0x04, 0x07); // TX - 10119840 to 10119974
  writeRegister(0x00, 0xFF); // CS0 - 10126621 to 10126757
  writeRegister(0x01, 0xFF); // CS1 - 10126771 to 10126911
  writeRegister(0x16, 0xC0); // FIFO CTRL - 10126922 to 10127060
  writeRegister(0x40, 0x04); // TX Buffer - 10127070 to 10127203
  writeRegister(0x41, 0x0E); // TX Buffer - 10127217 to 10127352
  writeRegister(0x44, 0x23); // TX Buffer - 10127365 to 10127500
  writeRegister(0x45, 0x11); // TX Buffer - 10127514 to 10127650
  writeRegister(0x46, 0x13); // TX Buffer - 10127662 to 10127805
  writeRegister(0x04, 0x07); // TX - 10127811 to 10127947
  writeRegister(0x00, 0xFF); // CS0 - 10134677 to 10134813
  writeRegister(0x01, 0xFF); // CS1 - 10134827 to 10134967
  writeRegister(0x16, 0xC0); // FIFO CTRL - 10134981 to 10135115
  writeRegister(0x40, 0x04); // TX Buffer - 10135129 to 10135262
  writeRegister(0x41, 0x0E); // TX Buffer - 10135273 to 10135411
  writeRegister(0x44, 0x23); // TX Buffer - 10135421 to 10135563
  writeRegister(0x45, 0x11); // TX Buffer - 10135570 to 10135712
  writeRegister(0x46, 0x13); // TX Buffer - 10135718 to 10135858
  writeRegister(0x04, 0x07); // TX - 10135867 to 10136009
  writeRegister(0x00, 0xFF); // CS0 - 10142648 to 10142789
  writeRegister(0x01, 0xFF); // CS1 - 10142798 to 10142938
  writeRegister(0x16, 0xC0); // FIFO CTRL - 10142952 to 10143087
  writeRegister(0x40, 0x04); // TX Buffer - 10143100 to 10143235
  writeRegister(0x41, 0x0E); // TX Buffer - 10143247 to 10143382
  writeRegister(0x44, 0x23); // TX Buffer - 10143396 to 10143530
  writeRegister(0x45, 0x11); // TX Buffer - 10143544 to 10143680
  writeRegister(0x46, 0x13); // TX Buffer - 10143693 to 10143829
  writeRegister(0x04, 0x07); // TX - 10143842 to 10143977
  writeRegister(0x00, 0xFF); // CS0 - 10150623 to 10150760
  writeRegister(0x01, 0xFF); // CS1 - 10150772 to 10150914
  writeRegister(0x16, 0xC0); // FIFO CTRL - 10150923 to 10151061
  writeRegister(0x40, 0x04); // TX Buffer - 10151071 to 10151205
  writeRegister(0x41, 0x0E); // TX Buffer - 10151218 to 10151353
  writeRegister(0x44, 0x23); // TX Buffer - 10151367 to 10151501
  writeRegister(0x45, 0x11); // TX Buffer - 10151515 to 10151651
  writeRegister(0x46, 0x13); // TX Buffer - 10151664 to 10151800
  writeRegister(0x04, 0x07); // TX - 10151813 to 10151948
  writeRegister(0x00, 0xFF); // CS0 - 10158678 to 10158816
  writeRegister(0x01, 0xFF); // CS1 - 10158828 to 10158968
  writeRegister(0x16, 0xC0); // FIFO CTRL - 10158979 to 10159117
  writeRegister(0x40, 0x04); // TX Buffer - 10159127 to 10159260
  writeRegister(0x41, 0x0E); // TX Buffer - 10159274 to 10159409
  writeRegister(0x44, 0x23); // TX Buffer - 10159423 to 10159557
  writeRegister(0x45, 0x11); // TX Buffer - 10159571 to 10159707
  writeRegister(0x46, 0x13); // TX Buffer - 10159719 to 10159862
  writeRegister(0x04, 0x07); // TX - 10159868 to 10160004
  writeRegister(0x00, 0xFF); // CS0 - 10166649 to 10166790
  writeRegister(0x01, 0xFF); // CS1 - 10166799 to 10166939
  writeRegister(0x16, 0xC0); // FIFO CTRL - 10166953 to 10167088
  writeRegister(0x40, 0x04); // TX Buffer - 10167102 to 10167235
  writeRegister(0x41, 0x0E); // TX Buffer - 10167245 to 10167383
  writeRegister(0x44, 0x23); // TX Buffer - 10167394 to 10167533
  writeRegister(0x45, 0x11); // TX Buffer - 10167542 to 10167680
  writeRegister(0x46, 0x13); // TX Buffer - 10167691 to 10167829
  writeRegister(0x04, 0x07); // TX - 10167843 to 10167977
  writeRegister(0x00, 0xFF); // CS0 - 10174620 to 10174760
  writeRegister(0x01, 0xFF); // CS1 - 10174774 to 10174918
  writeRegister(0x16, 0xC0); // FIFO CTRL - 10174924 to 10175062
  writeRegister(0x40, 0x04); // TX Buffer - 10175073 to 10175206
  writeRegister(0x41, 0x0E); // TX Buffer - 10175220 to 10175354
  writeRegister(0x44, 0x23); // TX Buffer - 10175368 to 10175504
  writeRegister(0x45, 0x11); // TX Buffer - 10175517 to 10175651
  writeRegister(0x46, 0x13); // TX Buffer - 10175665 to 10175800
  writeRegister(0x04, 0x07); // TX - 10175814 to 10175948
  writeRegister(0x00, 0xFF); // CS0 - 10182680 to 10182817
  writeRegister(0x01, 0xFF); // CS1 - 10182830 to 10182971
  writeRegister(0x16, 0xC0); // FIFO CTRL - 10182980 to 10183118
  writeRegister(0x40, 0x04); // TX Buffer - 10183128 to 10183262
  writeRegister(0x41, 0x0E); // TX Buffer - 10183275 to 10183410
  writeRegister(0x44, 0x23); // TX Buffer - 10183424 to 10183560
  writeRegister(0x45, 0x11); // TX Buffer - 10183572 to 10183707
  writeRegister(0x46, 0x13); // TX Buffer - 10183721 to 10183857
  writeRegister(0x04, 0x07); // TX - 10183870 to 10184005
  writeRegister(0x00, 0xFF); // CS0 - 10190651 to 10190794
  writeRegister(0x01, 0xFF); // CS1 - 10190801 to 10190942
  writeRegister(0x16, 0xC0); // FIFO CTRL - 10190954 to 10191089
  writeRegister(0x40, 0x04); // TX Buffer - 10191103 to 10191236
  writeRegister(0x41, 0x0E); // TX Buffer - 10191246 to 10191385
  writeRegister(0x44, 0x23); // TX Buffer - 10191395 to 10191533
  writeRegister(0x45, 0x11); // TX Buffer - 10191543 to 10191683
  writeRegister(0x46, 0x13); // TX Buffer - 10191692 to 10191830
  writeRegister(0x04, 0x07); // TX - 10191841 to 10191978
  writeRegister(0x00, 0xFF); // CS0 - 10198622 to 10198761
  writeRegister(0x01, 0xFF); // CS1 - 10198775 to 10198913
  writeRegister(0x16, 0xC0); // FIFO CTRL - 10198926 to 10199060
  writeRegister(0x40, 0x04); // TX Buffer - 10199074 to 10199207
  writeRegister(0x41, 0x0E); // TX Buffer - 10199221 to 10199356
  writeRegister(0x44, 0x23); // TX Buffer - 10199369 to 10199504
  writeRegister(0x45, 0x11); // TX Buffer - 10199518 to 10199654
  writeRegister(0x46, 0x13); // TX Buffer - 10199666 to 10199803
  writeRegister(0x04, 0x07); // TX - 10199815 to 10199949
  writeRegister(0x00, 0xFF); // CS0 - 10206678 to 10206817
  writeRegister(0x01, 0xFF); // CS1 - 10206831 to 10206975
  writeRegister(0x16, 0xC0); // FIFO CTRL - 10206981 to 10207119
  writeRegister(0x40, 0x04); // TX Buffer - 10207130 to 10207263
  writeRegister(0x41, 0x0E); // TX Buffer - 10207277 to 10207411
  writeRegister(0x44, 0x23); // TX Buffer - 10207425 to 10207561
  writeRegister(0x45, 0x11); // TX Buffer - 10207574 to 10207708
  writeRegister(0x46, 0x13); // TX Buffer - 10207722 to 10207857
  writeRegister(0x04, 0x07); // TX - 10207871 to 10208005
  writeRegister(0x00, 0xFF); // CS0 - 10214652 to 10214796
  writeRegister(0x01, 0xFF); // CS1 - 10214802 to 10214942
  writeRegister(0x16, 0xC0); // FIFO CTRL - 10214956 to 10215092
  writeRegister(0x40, 0x04); // TX Buffer - 10215104 to 10215239
  writeRegister(0x41, 0x0E); // TX Buffer - 10215248 to 10215386
  writeRegister(0x44, 0x23); // TX Buffer - 10215396 to 10215538
  writeRegister(0x45, 0x11); // TX Buffer - 10215545 to 10215687
  writeRegister(0x46, 0x13); // TX Buffer - 10215693 to 10215833
  writeRegister(0x04, 0x07); // TX - 10215842 to 10215984
  writeRegister(0x00, 0xFF); // CS0 - 10222623 to 10222764
  writeRegister(0x01, 0xFF); // CS1 - 10222776 to 10222913
  writeRegister(0x16, 0xC0); // FIFO CTRL - 10222927 to 10223062
  writeRegister(0x40, 0x04); // TX Buffer - 10223075 to 10223209
  writeRegister(0x41, 0x0E); // TX Buffer - 10223222 to 10223357
  writeRegister(0x44, 0x23); // TX Buffer - 10223371 to 10223505
  writeRegister(0x45, 0x11); // TX Buffer - 10223519 to 10223655
  writeRegister(0x46, 0x13); // TX Buffer - 10223668 to 10223804
  writeRegister(0x04, 0x07); // TX - 10223817 to 10223952
  writeRegister(0x00, 0xFF); // CS0 - 10230679 to 10230820
  writeRegister(0x01, 0xFF); // CS1 - 10230832 to 10230970
  writeRegister(0x16, 0xC0); // FIFO CTRL - 10230983 to 10231117
  writeRegister(0x40, 0x04); // TX Buffer - 10231131 to 10231264
  writeRegister(0x41, 0x0E); // TX Buffer - 10231278 to 10231413
  writeRegister(0x44, 0x23); // TX Buffer - 10231427 to 10231561
  writeRegister(0x45, 0x11); // TX Buffer - 10231575 to 10231711
  writeRegister(0x46, 0x13); // TX Buffer - 10231723 to 10231860
  writeRegister(0x04, 0x07); // TX - 10231872 to 10232008
  writeRegister(0x00, 0xFF); // CS0 - 10238653 to 10238791
  writeRegister(0x01, 0xFF); // CS1 - 10238803 to 10238943
  writeRegister(0x16, 0xC0); // FIFO CTRL - 10238954 to 10239092
  writeRegister(0x40, 0x04); // TX Buffer - 10239102 to 10239243
  writeRegister(0x41, 0x0E); // TX Buffer - 10239249 to 10239390
  writeRegister(0x44, 0x23); // TX Buffer - 10239398 to 10239540
  writeRegister(0x45, 0x11); // TX Buffer - 10239546 to 10239688
  writeRegister(0x46, 0x13); // TX Buffer - 10239694 to 10239837
  writeRegister(0x04, 0x07); // TX - 10239843 to 10239985
  writeRegister(0x00, 0xFF); // CS0 - 10246624 to 10246764
  writeRegister(0x01, 0xFF); // CS1 - 10246774 to 10246914
  writeRegister(0x16, 0xC0); // FIFO CTRL - 10246928 to 10247063
  writeRegister(0x40, 0x04); // TX Buffer - 10247077 to 10247210
  writeRegister(0x41, 0x0E); // TX Buffer - 10247224 to 10247358
  writeRegister(0x44, 0x23); // TX Buffer - 10247372 to 10247508
  writeRegister(0x45, 0x11); // TX Buffer - 10247521 to 10247655
  writeRegister(0x46, 0x13); // TX Buffer - 10247669 to 10247804
  writeRegister(0x04, 0x07); // TX - 10247818 to 10247952
  writeRegister(0x00, 0xFF); // CS0 - 10254680 to 10254821
  writeRegister(0x01, 0xFF); // CS1 - 10254834 to 10254970
  writeRegister(0x16, 0xC0); // FIFO CTRL - 10254984 to 10255119
  writeRegister(0x40, 0x04); // TX Buffer - 10255132 to 10255266
  writeRegister(0x41, 0x0E); // TX Buffer - 10255279 to 10255414
  writeRegister(0x44, 0x23); // TX Buffer - 10255428 to 10255564
  writeRegister(0x45, 0x11); // TX Buffer - 10255576 to 10255712
  writeRegister(0x46, 0x13); // TX Buffer - 10255725 to 10255861
  writeRegister(0x04, 0x07); // TX - 10255874 to 10256009
  writeRegister(0x00, 0xFF); // CS0 - 10262655 to 10262792
  writeRegister(0x01, 0xFF); // CS1 - 10262805 to 10262946
  writeRegister(0x16, 0xC0); // FIFO CTRL - 10262955 to 10263093
  writeRegister(0x40, 0x04); // TX Buffer - 10263103 to 10263237
  writeRegister(0x41, 0x0E); // TX Buffer - 10263250 to 10263385
  writeRegister(0x44, 0x23); // TX Buffer - 10263399 to 10263535
  writeRegister(0x45, 0x11); // TX Buffer - 10263547 to 10263682
  writeRegister(0x46, 0x13); // TX Buffer - 10263696 to 10263838
  writeRegister(0x04, 0x07); // TX - 10263845 to 10263980
  writeRegister(0x00, 0xFF); // CS0 - 10270626 to 10270765
  writeRegister(0x01, 0xFF); // CS1 - 10270776 to 10270917
  writeRegister(0x16, 0xC0); // FIFO CTRL - 10270930 to 10271064
  writeRegister(0x40, 0x04); // TX Buffer - 10271078 to 10271211
  writeRegister(0x41, 0x0E); // TX Buffer - 10271222 to 10271360
  writeRegister(0x44, 0x23); // TX Buffer - 10271370 to 10271508
  writeRegister(0x45, 0x11); // TX Buffer - 10271518 to 10271658
  writeRegister(0x46, 0x13); // TX Buffer - 10271667 to 10271807
  writeRegister(0x04, 0x07); // TX - 10271819 to 10271953
  writeRegister(0x00, 0xFF); // CS0 - 10278682 to 10278821
  writeRegister(0x01, 0xFF); // CS1 - 10278831 to 10278973
  writeRegister(0x16, 0xC0); // FIFO CTRL - 10278985 to 10279120
  writeRegister(0x40, 0x04); // TX Buffer - 10279134 to 10279267
  writeRegister(0x41, 0x0E); // TX Buffer - 10279281 to 10279415
  writeRegister(0x44, 0x23); // TX Buffer - 10279429 to 10279565
  writeRegister(0x45, 0x11); // TX Buffer - 10279578 to 10279712
  writeRegister(0x46, 0x13); // TX Buffer - 10279726 to 10279861
  writeRegister(0x04, 0x07); // TX - 10279875 to 10280009
  writeRegister(0x00, 0xFF); // CS0 - 10286653 to 10286792
  writeRegister(0x01, 0xFF); // CS1 - 10286806 to 10286950
  writeRegister(0x16, 0xC0); // FIFO CTRL - 10286956 to 10287094
  writeRegister(0x40, 0x04); // TX Buffer - 10287105 to 10287238
  writeRegister(0x41, 0x0E); // TX Buffer - 10287252 to 10287388
  writeRegister(0x44, 0x23); // TX Buffer - 10287400 to 10287536
  writeRegister(0x45, 0x11); // TX Buffer - 10287549 to 10287683
  writeRegister(0x46, 0x13); // TX Buffer - 10287697 to 10287832
  writeRegister(0x04, 0x07); // TX - 10287846 to 10287980
  writeRegister(0x00, 0xFF); // CS0 - 10294627 to 10294771
  writeRegister(0x01, 0xFF); // CS1 - 10294777 to 10294917
  writeRegister(0x16, 0xC0); // FIFO CTRL - 10294931 to 10295067
  writeRegister(0x40, 0x04); // TX Buffer - 10295079 to 10295214
  writeRegister(0x41, 0x0E); // TX Buffer - 10295223 to 10295361
  writeRegister(0x44, 0x23); // TX Buffer - 10295371 to 10295509
  writeRegister(0x45, 0x11); // TX Buffer - 10295520 to 10295659
  writeRegister(0x46, 0x13); // TX Buffer - 10295668 to 10295808
  writeRegister(0x04, 0x07); // TX - 10295817 to 10295956
  writeRegister(0x00, 0xFF); // CS0 - 10302683 to 10302822
  writeRegister(0x01, 0xFF); // CS1 - 10302833 to 10302974
  writeRegister(0x16, 0xC0); // FIFO CTRL - 10302987 to 10303121
  writeRegister(0x40, 0x04); // TX Buffer - 10303135 to 10303268
  writeRegister(0x41, 0x0E); // TX Buffer - 10303279 to 10303417
  writeRegister(0x44, 0x23); // TX Buffer - 10303427 to 10303565
  writeRegister(0x45, 0x11); // TX Buffer - 10303576 to 10303715
  writeRegister(0x46, 0x13); // TX Buffer - 10303724 to 10303864
  writeRegister(0x04, 0x07); // TX - 10303876 to 10304012
  writeRegister(0x00, 0xFF); // CS0 - 10310661 to 10310802
  writeRegister(0x01, 0xFF); // CS1 - 10310815 to 10310951
  writeRegister(0x16, 0xC0); // FIFO CTRL - 10310965 to 10311100
  writeRegister(0x40, 0x04); // TX Buffer - 10311113 to 10311247
  writeRegister(0x41, 0x0E); // TX Buffer - 10311260 to 10311395
  writeRegister(0x44, 0x23); // TX Buffer - 10311409 to 10311545
  writeRegister(0x45, 0x11); // TX Buffer - 10311557 to 10311692
  writeRegister(0x46, 0x13); // TX Buffer - 10311706 to 10311842
  writeRegister(0x04, 0x07); // TX - 10311855 to 10311990
  writeRegister(0x00, 0xFF); // CS0 - 10318636 to 10318773
  writeRegister(0x01, 0xFF); // CS1 - 10318786 to 10318927
  writeRegister(0x16, 0xC0); // FIFO CTRL - 10318936 to 10319074
  writeRegister(0x40, 0x04); // TX Buffer - 10319085 to 10319218
  writeRegister(0x41, 0x0E); // TX Buffer - 10319232 to 10319366
  writeRegister(0x44, 0x23); // TX Buffer - 10319380 to 10319516
  writeRegister(0x45, 0x11); // TX Buffer - 10319528 to 10319663
  writeRegister(0x46, 0x13); // TX Buffer - 10319677 to 10319818
  writeRegister(0x04, 0x07); // TX - 10319826 to 10319961
  writeRegister(0x00, 0xFF); // CS0 - 10326692 to 10326829
  writeRegister(0x01, 0xFF); // CS1 - 10326841 to 10326983
  writeRegister(0x16, 0xC0); // FIFO CTRL - 10326995 to 10327130
  writeRegister(0x40, 0x04); // TX Buffer - 10327144 to 10327277
  writeRegister(0x41, 0x0E); // TX Buffer - 10327287 to 10327425
  writeRegister(0x44, 0x23); // TX Buffer - 10327436 to 10327578
  writeRegister(0x45, 0x11); // TX Buffer - 10327584 to 10327726
  writeRegister(0x46, 0x13); // TX Buffer - 10327733 to 10327871
  writeRegister(0x04, 0x07); // TX - 10327882 to 10328023
  writeRegister(0x00, 0xFF); // CS0 - 10334663 to 10334802
  writeRegister(0x01, 0xFF); // CS1 - 10334813 to 10334954
  writeRegister(0x16, 0xC0); // FIFO CTRL - 10334966 to 10335101
  writeRegister(0x40, 0x04); // TX Buffer - 10335115 to 10335248
  writeRegister(0x41, 0x0E); // TX Buffer - 10335262 to 10335396
  writeRegister(0x44, 0x23); // TX Buffer - 10335410 to 10335546
  writeRegister(0x45, 0x11); // TX Buffer - 10335559 to 10335693
  writeRegister(0x46, 0x13); // TX Buffer - 10335707 to 10335842
  writeRegister(0x04, 0x07); // TX - 10335856 to 10335990
  writeRegister(0x00, 0xFF); // CS0 - 10342637 to 10342773
  writeRegister(0x01, 0xFF); // CS1 - 10342787 to 10342927
  writeRegister(0x16, 0xC0); // FIFO CTRL - 10342937 to 10343077
  writeRegister(0x40, 0x04); // TX Buffer - 10343086 to 10343219
  writeRegister(0x41, 0x0E); // TX Buffer - 10343233 to 10343369
  writeRegister(0x44, 0x23); // TX Buffer - 10343381 to 10343517
  writeRegister(0x45, 0x11); // TX Buffer - 10343530 to 10343664
  writeRegister(0x46, 0x13); // TX Buffer - 10343678 to 10343813
  writeRegister(0x04, 0x07); // TX - 10343827 to 10343961
  writeRegister(0x00, 0xFF); // CS0 - 10350693 to 10350830
  writeRegister(0x01, 0xFF); // CS1 - 10350843 to 10350984
  writeRegister(0x16, 0xC0); // FIFO CTRL - 10350993 to 10351131
  writeRegister(0x40, 0x04); // TX Buffer - 10351142 to 10351275
  writeRegister(0x41, 0x0E); // TX Buffer - 10351289 to 10351423
  writeRegister(0x44, 0x23); // TX Buffer - 10351437 to 10351573
  writeRegister(0x45, 0x11); // TX Buffer - 10351586 to 10351720
  writeRegister(0x46, 0x13); // TX Buffer - 10351734 to 10351877
  writeRegister(0x04, 0x07); // TX - 10351883 to 10352017
  writeRegister(0x00, 0xFF); // CS0 - 10358664 to 10358805
  writeRegister(0x01, 0xFF); // CS1 - 10358814 to 10358955
  writeRegister(0x16, 0xC0); // FIFO CTRL - 10358968 to 10359102
  writeRegister(0x40, 0x04); // TX Buffer - 10359116 to 10359249
  writeRegister(0x41, 0x0E); // TX Buffer - 10359260 to 10359398
  writeRegister(0x44, 0x23); // TX Buffer - 10359408 to 10359546
  writeRegister(0x45, 0x11); // TX Buffer - 10359557 to 10359696
  writeRegister(0x46, 0x13); // TX Buffer - 10359705 to 10359845
  writeRegister(0x04, 0x07); // TX - 10359857 to 10359993
  writeRegister(0x00, 0xFF); // CS0 - 10366635 to 10366776
  writeRegister(0x01, 0xFF); // CS1 - 10366788 to 10366932
  writeRegister(0x16, 0xC0); // FIFO CTRL - 10366939 to 10367077
  writeRegister(0x40, 0x04); // TX Buffer - 10367087 to 10367220
  writeRegister(0x41, 0x0E); // TX Buffer - 10367234 to 10367369
  writeRegister(0x44, 0x23); // TX Buffer - 10367383 to 10367517
  writeRegister(0x45, 0x11); // TX Buffer - 10367531 to 10367667
  writeRegister(0x46, 0x13); // TX Buffer - 10367679 to 10367816
  writeRegister(0x04, 0x07); // TX - 10367828 to 10367964
  writeRegister(0x00, 0xFF); // CS0 - 10374694 to 10374830
  writeRegister(0x01, 0xFF); // CS1 - 10374844 to 10374984
  writeRegister(0x16, 0xC0); // FIFO CTRL - 10374994 to 10375133
  writeRegister(0x40, 0x04); // TX Buffer - 10375143 to 10375276
  writeRegister(0x41, 0x0E); // TX Buffer - 10375290 to 10375425
  writeRegister(0x44, 0x23); // TX Buffer - 10375438 to 10375573
  writeRegister(0x45, 0x11); // TX Buffer - 10375587 to 10375723
  writeRegister(0x46, 0x13); // TX Buffer - 10375735 to 10375870
  writeRegister(0x04, 0x07); // TX - 10375884 to 10376018
  writeRegister(0x00, 0xFF); // CS0 - 10382665 to 10382809
  writeRegister(0x01, 0xFF); // CS1 - 10382815 to 10382955
  writeRegister(0x16, 0xC0); // FIFO CTRL - 10382969 to 10383104
  writeRegister(0x40, 0x04); // TX Buffer - 10383117 to 10383251
  writeRegister(0x41, 0x0E); // TX Buffer - 10383261 to 10383399
  writeRegister(0x44, 0x23); // TX Buffer - 10383409 to 10383549
  writeRegister(0x45, 0x11); // TX Buffer - 10383558 to 10383697
  writeRegister(0x46, 0x13); // TX Buffer - 10383706 to 10383846
  writeRegister(0x04, 0x07); // TX - 10383855 to 10383994
  writeRegister(0x00, 0xFF); // CS0 - 10390636 to 10390777
  writeRegister(0x01, 0xFF); // CS1 - 10390790 to 10390926
  writeRegister(0x16, 0xC0); // FIFO CTRL - 10390940 to 10391075
  writeRegister(0x40, 0x04); // TX Buffer - 10391088 to 10391222
  writeRegister(0x41, 0x0E); // TX Buffer - 10391235 to 10391370
  writeRegister(0x44, 0x23); // TX Buffer - 10391384 to 10391520
  writeRegister(0x45, 0x11); // TX Buffer - 10391532 to 10391667
  writeRegister(0x46, 0x13); // TX Buffer - 10391681 to 10391817
  writeRegister(0x04, 0x07); // TX - 10391830 to 10391965
  writeRegister(0x00, 0xFF); // CS0 - 10398692 to 10398833
  writeRegister(0x01, 0xFF); // CS1 - 10398845 to 10398990
  writeRegister(0x16, 0xC0); // FIFO CTRL - 10398996 to 10399134
  writeRegister(0x40, 0x04); // TX Buffer - 10399144 to 10399279
  writeRegister(0x41, 0x0E); // TX Buffer - 10399291 to 10399426
  writeRegister(0x44, 0x23); // TX Buffer - 10399440 to 10399574
  writeRegister(0x45, 0x11); // TX Buffer - 10399588 to 10399724
  writeRegister(0x46, 0x13); // TX Buffer - 10399737 to 10399873
  writeRegister(0x04, 0x07); // TX - 10399886 to 10400021
  writeRegister(0x00, 0xFF); // CS0 - 10406667 to 10406810
  writeRegister(0x01, 0xFF); // CS1 - 10406816 to 10406958
  writeRegister(0x16, 0xC0); // FIFO CTRL - 10406970 to 10407105
  writeRegister(0x40, 0x04); // TX Buffer - 10407119 to 10407252
  writeRegister(0x41, 0x0E); // TX Buffer - 10407262 to 10407400
  writeRegister(0x44, 0x23); // TX Buffer - 10407411 to 10407553
  writeRegister(0x45, 0x11); // TX Buffer - 10407559 to 10407701
  writeRegister(0x46, 0x13); // TX Buffer - 10407708 to 10407846
  writeRegister(0x04, 0x07); // TX - 10407857 to 10407998
  writeRegister(0x00, 0xFF); // CS0 - 10414638 to 10414777
  writeRegister(0x01, 0xFF); // CS1 - 10414791 to 10414929
  writeRegister(0x16, 0xC0); // FIFO CTRL - 10414941 to 10415076
  writeRegister(0x40, 0x04); // TX Buffer - 10415090 to 10415223
  writeRegister(0x41, 0x0E); // TX Buffer - 10415237 to 10415373
  writeRegister(0x44, 0x23); // TX Buffer - 10415385 to 10415521
  writeRegister(0x45, 0x11); // TX Buffer - 10415534 to 10415668
  writeRegister(0x46, 0x13); // TX Buffer - 10415682 to 10415817
  writeRegister(0x04, 0x07); // TX - 10415831 to 10415965
  writeRegister(0x00, 0xFF); // CS0 - 10422693 to 10422834
  writeRegister(0x01, 0xFF); // CS1 - 10422847 to 10422983
  writeRegister(0x16, 0xC0); // FIFO CTRL - 10422997 to 10423132
  writeRegister(0x40, 0x04); // TX Buffer - 10423146 to 10423279
  writeRegister(0x41, 0x0E); // TX Buffer - 10423293 to 10423427
  writeRegister(0x44, 0x23); // TX Buffer - 10423441 to 10423577
  writeRegister(0x45, 0x11); // TX Buffer - 10423589 to 10423724
  writeRegister(0x46, 0x13); // TX Buffer - 10423738 to 10423873
  writeRegister(0x04, 0x07); // TX - 10423887 to 10424021
  writeRegister(0x00, 0xFF); // CS0 - 10430668 to 10430804
  writeRegister(0x01, 0xFF); // CS1 - 10430818 to 10430959
  writeRegister(0x16, 0xC0); // FIFO CTRL - 10430968 to 10431106
  writeRegister(0x40, 0x04); // TX Buffer - 10431117 to 10431256
  writeRegister(0x41, 0x0E); // TX Buffer - 10431264 to 10431406
  writeRegister(0x44, 0x23); // TX Buffer - 10431412 to 10431554
  writeRegister(0x45, 0x11); // TX Buffer - 10431561 to 10431703
  writeRegister(0x46, 0x13); // TX Buffer - 10431709 to 10431852
  writeRegister(0x04, 0x07); // TX - 10431858 to 10432000
  writeRegister(0x00, 0xFF); // CS0 - 10438639 to 10438780
  writeRegister(0x01, 0xFF); // CS1 - 10438789 to 10438930
  writeRegister(0x16, 0xC0); // FIFO CTRL - 10438943 to 10439077
  writeRegister(0x40, 0x04); // TX Buffer - 10439091 to 10439224
  writeRegister(0x41, 0x0E); // TX Buffer - 10439238 to 10439373
  writeRegister(0x44, 0x23); // TX Buffer - 10439387 to 10439521
  writeRegister(0x45, 0x11); // TX Buffer - 10439535 to 10439671
  writeRegister(0x46, 0x13); // TX Buffer - 10439683 to 10439820
  writeRegister(0x04, 0x07); // TX - 10439832 to 10439968
  writeRegister(0x00, 0xFF); // CS0 - 10446695 to 10446834
  writeRegister(0x01, 0xFF); // CS1 - 10446848 to 10446986
  writeRegister(0x16, 0xC0); // FIFO CTRL - 10446998 to 10447133
  writeRegister(0x40, 0x04); // TX Buffer - 10447147 to 10447280
  writeRegister(0x41, 0x0E); // TX Buffer - 10447294 to 10447429
  writeRegister(0x44, 0x23); // TX Buffer - 10447442 to 10447577
  writeRegister(0x45, 0x11); // TX Buffer - 10447591 to 10447727
  writeRegister(0x46, 0x13); // TX Buffer - 10447739 to 10447874
  writeRegister(0x04, 0x07); // TX - 10447888 to 10448022
  writeRegister(0x00, 0xFF); // CS0 - 10454669 to 10454805
  writeRegister(0x01, 0xFF); // CS1 - 10454819 to 10454959
  writeRegister(0x16, 0xC0); // FIFO CTRL - 10454970 to 10455108
  writeRegister(0x40, 0x04); // TX Buffer - 10455118 to 10455251
  writeRegister(0x41, 0x0E); // TX Buffer - 10455265 to 10455400
  writeRegister(0x44, 0x23); // TX Buffer - 10455413 to 10455548
  writeRegister(0x45, 0x11); // TX Buffer - 10455562 to 10455698
  writeRegister(0x46, 0x13); // TX Buffer - 10455710 to 10455853
  writeRegister(0x04, 0x07); // TX - 10455859 to 10455993
  writeRegister(0x00, 0xFF); // CS0 - 10462640 to 10462781
  writeRegister(0x01, 0xFF); // CS1 - 10462790 to 10462930
  writeRegister(0x16, 0xC0); // FIFO CTRL - 10462944 to 10463079
  writeRegister(0x40, 0x04); // TX Buffer - 10463092 to 10463226
  writeRegister(0x41, 0x0E); // TX Buffer - 10463236 to 10463374
  writeRegister(0x44, 0x23); // TX Buffer - 10463384 to 10463524
  writeRegister(0x45, 0x11); // TX Buffer - 10463533 to 10463671
  writeRegister(0x46, 0x13); // TX Buffer - 10463681 to 10463821
  writeRegister(0x04, 0x07); // TX - 10463834 to 10463969
  writeRegister(0x00, 0xFF); // CS0 - 10470696 to 10470837
  writeRegister(0x01, 0xFF); // CS1 - 10470846 to 10470986
  writeRegister(0x16, 0xC0); // FIFO CTRL - 10471000 to 10471136
  writeRegister(0x40, 0x04); // TX Buffer - 10471148 to 10471281
  writeRegister(0x41, 0x0E); // TX Buffer - 10471295 to 10471430
  writeRegister(0x44, 0x23); // TX Buffer - 10471444 to 10471578
  writeRegister(0x45, 0x11); // TX Buffer - 10471592 to 10471728
  writeRegister(0x46, 0x13); // TX Buffer - 10471741 to 10471877
  writeRegister(0x04, 0x07); // TX - 10471890 to 10472025
  writeRegister(0x00, 0xFF); // CS0 - 10478667 to 10478808
  writeRegister(0x01, 0xFF); // CS1 - 10478820 to 10478965
  writeRegister(0x16, 0xC0); // FIFO CTRL - 10478971 to 10479109
  writeRegister(0x40, 0x04); // TX Buffer - 10479119 to 10479254
  writeRegister(0x41, 0x0E); // TX Buffer - 10479266 to 10479401
  writeRegister(0x44, 0x23); // TX Buffer - 10479415 to 10479549
  writeRegister(0x45, 0x11); // TX Buffer - 10479563 to 10479699
  writeRegister(0x46, 0x13); // TX Buffer - 10479712 to 10479848
  writeRegister(0x04, 0x07); // TX - 10479861 to 10479996
  writeRegister(0x00, 0xFF); // CS0 - 10486642 to 10486785
  writeRegister(0x01, 0xFF); // CS1 - 10486792 to 10486933
  writeRegister(0x16, 0xC0); // FIFO CTRL - 10486945 to 10487080
  writeRegister(0x40, 0x04); // TX Buffer - 10487094 to 10487227
  writeRegister(0x41, 0x0E); // TX Buffer - 10487237 to 10487375
  writeRegister(0x44, 0x23); // TX Buffer - 10487386 to 10487525
  writeRegister(0x45, 0x11); // TX Buffer - 10487534 to 10487672
  writeRegister(0x46, 0x13); // TX Buffer - 10487683 to 10487821
  writeRegister(0x04, 0x07); // TX - 10487832 to 10487969
  writeRegister(0x00, 0xFF); // CS0 - 10494697 to 10494838
  writeRegister(0x01, 0xFF); // CS1 - 10494847 to 10494987
  writeRegister(0x16, 0xC0); // FIFO CTRL - 10495001 to 10495136
  writeRegister(0x40, 0x04); // TX Buffer - 10495150 to 10495283
  writeRegister(0x41, 0x0E); // TX Buffer - 10495293 to 10495431
  writeRegister(0x44, 0x23); // TX Buffer - 10495442 to 10495581
  writeRegister(0x45, 0x11); // TX Buffer - 10495590 to 10495728
  writeRegister(0x46, 0x13); // TX Buffer - 10495738 to 10495877
  writeRegister(0x04, 0x07); // TX - 10495891 to 10496025
  writeRegister(0x00, 0xFF); // CS0 - 10502668 to 10502808
  writeRegister(0x01, 0xFF); // CS1 - 10502822 to 10502966
  writeRegister(0x16, 0xC0); // FIFO CTRL - 10502972 to 10503113
  writeRegister(0x40, 0x04); // TX Buffer - 10503121 to 10503254
  writeRegister(0x41, 0x0E); // TX Buffer - 10503268 to 10503402
  writeRegister(0x44, 0x23); // TX Buffer - 10503416 to 10503552
  writeRegister(0x45, 0x11); // TX Buffer - 10503565 to 10503699
  writeRegister(0x46, 0x13); // TX Buffer - 10503713 to 10503848
  writeRegister(0x04, 0x07); // TX - 10503862 to 10503996
  writeRegister(0x00, 0xFF); // CS0 - 10510643 to 10510779
  writeRegister(0x01, 0xFF); // CS1 - 10510793 to 10510934
  writeRegister(0x16, 0xC0); // FIFO CTRL - 10510947 to 10511081
  writeRegister(0x40, 0x04); // TX Buffer - 10511095 to 10511228
  writeRegister(0x41, 0x0E); // TX Buffer - 10511239 to 10511377
  writeRegister(0x44, 0x23); // TX Buffer - 10511387 to 10511529
  writeRegister(0x45, 0x11); // TX Buffer - 10511536 to 10511678
  writeRegister(0x46, 0x13); // TX Buffer - 10511684 to 10511824
  writeRegister(0x04, 0x07); // TX - 10511833 to 10511975
  writeRegister(0x00, 0xFF); // CS0 - 10518699 to 10518842
  writeRegister(0x01, 0xFF); // CS1 - 10518849 to 10518990
  writeRegister(0x16, 0xC0); // FIFO CTRL - 10519002 to 10519137
  writeRegister(0x40, 0x04); // TX Buffer - 10519151 to 10519284
  writeRegister(0x41, 0x0E); // TX Buffer - 10519294 to 10519433
  writeRegister(0x44, 0x23); // TX Buffer - 10519443 to 10519582
  writeRegister(0x45, 0x11); // TX Buffer - 10519591 to 10519729
  writeRegister(0x46, 0x13); // TX Buffer - 10519740 to 10519878
  writeRegister(0x04, 0x07); // TX - 10519889 to 10520026
  writeRegister(0x00, 0xFF); // CS0 - 10526670 to 10526809
  writeRegister(0x01, 0xFF); // CS1 - 10526823 to 10526961
  writeRegister(0x16, 0xC0); // FIFO CTRL - 10526974 to 10527108
  writeRegister(0x40, 0x04); // TX Buffer - 10527122 to 10527255
  writeRegister(0x41, 0x0E); // TX Buffer - 10527269 to 10527404
  writeRegister(0x44, 0x23); // TX Buffer - 10527417 to 10527552
  writeRegister(0x45, 0x11); // TX Buffer - 10527566 to 10527702
  writeRegister(0x46, 0x13); // TX Buffer - 10527714 to 10527849
  writeRegister(0x04, 0x07); // TX - 10527863 to 10527997
  writeRegister(0x00, 0xFF); // CS0 - 10534644 to 10534780
  writeRegister(0x01, 0xFF); // CS1 - 10534794 to 10534934
  writeRegister(0x16, 0xC0); // FIFO CTRL - 10534945 to 10535083
  writeRegister(0x40, 0x04); // TX Buffer - 10535093 to 10535226
  writeRegister(0x41, 0x0E); // TX Buffer - 10535240 to 10535375
  writeRegister(0x44, 0x23); // TX Buffer - 10535388 to 10535523
  writeRegister(0x45, 0x11); // TX Buffer - 10535537 to 10535673
  writeRegister(0x46, 0x13); // TX Buffer - 10535685 to 10535828
  writeRegister(0x04, 0x07); // TX - 10535834 to 10535970
  writeRegister(0x00, 0xFF); // CS0 - 10542700 to 10542836
  writeRegister(0x01, 0xFF); // CS1 - 10542850 to 10542991
  writeRegister(0x16, 0xC0); // FIFO CTRL - 10543004 to 10543138
  writeRegister(0x40, 0x04); // TX Buffer - 10543152 to 10543285
  writeRegister(0x41, 0x0E); // TX Buffer - 10543296 to 10543434
  writeRegister(0x44, 0x23); // TX Buffer - 10543444 to 10543586
  writeRegister(0x45, 0x11); // TX Buffer - 10543593 to 10543735
  writeRegister(0x46, 0x13); // TX Buffer - 10543741 to 10543881
  writeRegister(0x04, 0x07); // TX - 10543890 to 10544032
  writeRegister(0x00, 0xFF); // CS0 - 10550671 to 10550812
  writeRegister(0x01, 0xFF); // CS1 - 10550821 to 10550961
  writeRegister(0x16, 0xC0); // FIFO CTRL - 10550975 to 10551111
  writeRegister(0x40, 0x04); // TX Buffer - 10551123 to 10551258
  writeRegister(0x41, 0x0E); // TX Buffer - 10551270 to 10551405
  writeRegister(0x44, 0x23); // TX Buffer - 10551419 to 10551553
  writeRegister(0x45, 0x11); // TX Buffer - 10551567 to 10551703
  writeRegister(0x46, 0x13); // TX Buffer - 10551716 to 10551852
  writeRegister(0x04, 0x07); // TX - 10551865 to 10552000
  writeRegister(0x00, 0xFF); // CS0 - 10558646 to 10558783
  writeRegister(0x01, 0xFF); // CS1 - 10558795 to 10558937
  writeRegister(0x16, 0xC0); // FIFO CTRL - 10558946 to 10559084
  writeRegister(0x40, 0x04); // TX Buffer - 10559094 to 10559228
  writeRegister(0x41, 0x0E); // TX Buffer - 10559241 to 10559376
  writeRegister(0x44, 0x23); // TX Buffer - 10559390 to 10559524
  writeRegister(0x45, 0x11); // TX Buffer - 10559538 to 10559674
  writeRegister(0x46, 0x13); // TX Buffer - 10559687 to 10559823
  writeRegister(0x04, 0x07); // TX - 10559836 to 10559971
  writeRegister(0x00, 0xFF); // CS0 - 10566701 to 10566839
  writeRegister(0x01, 0xFF); // CS1 - 10566851 to 10566991
  writeRegister(0x16, 0xC0); // FIFO CTRL - 10567002 to 10567140
  writeRegister(0x40, 0x04); // TX Buffer - 10567150 to 10567283
  writeRegister(0x41, 0x0E); // TX Buffer - 10567297 to 10567432
  writeRegister(0x44, 0x23); // TX Buffer - 10567446 to 10567580
  writeRegister(0x45, 0x11); // TX Buffer - 10567594 to 10567730
  writeRegister(0x46, 0x13); // TX Buffer - 10567742 to 10567885
  writeRegister(0x04, 0x07); // TX - 10567891 to 10568027
  writeRegister(0x00, 0xFF); // CS0 - 10574672 to 10574813
  writeRegister(0x01, 0xFF); // CS1 - 10574822 to 10574962
  writeRegister(0x16, 0xC0); // FIFO CTRL - 10574976 to 10575111
  writeRegister(0x40, 0x04); // TX Buffer - 10575125 to 10575258
  writeRegister(0x41, 0x0E); // TX Buffer - 10575268 to 10575406
  writeRegister(0x44, 0x23); // TX Buffer - 10575417 to 10575556
  writeRegister(0x45, 0x11); // TX Buffer - 10575565 to 10575703
  writeRegister(0x46, 0x13); // TX Buffer - 10575714 to 10575852
  writeRegister(0x04, 0x07); // TX - 10575866 to 10576000
  writeRegister(0x00, 0xFF); // CS0 - 10582643 to 10582783
  writeRegister(0x01, 0xFF); // CS1 - 10582797 to 10582941
  writeRegister(0x16, 0xC0); // FIFO CTRL - 10582947 to 10583085
  writeRegister(0x40, 0x04); // TX Buffer - 10583096 to 10583229
  writeRegister(0x41, 0x0E); // TX Buffer - 10583243 to 10583377
  writeRegister(0x44, 0x23); // TX Buffer - 10583391 to 10583527
  writeRegister(0x45, 0x11); // TX Buffer - 10583540 to 10583674
  writeRegister(0x46, 0x13); // TX Buffer - 10583688 to 10583823
  writeRegister(0x04, 0x07); // TX - 10583837 to 10583971
  writeRegister(0x00, 0xFF); // CS0 - 10590703 to 10590840
  writeRegister(0x01, 0xFF); // CS1 - 10590853 to 10590994
  writeRegister(0x16, 0xC0); // FIFO CTRL - 10591003 to 10591141
  writeRegister(0x40, 0x04); // TX Buffer - 10591151 to 10591285
  writeRegister(0x41, 0x0E); // TX Buffer - 10591298 to 10591433
  writeRegister(0x44, 0x23); // TX Buffer - 10591447 to 10591583
  writeRegister(0x45, 0x11); // TX Buffer - 10591595 to 10591731
  writeRegister(0x46, 0x13); // TX Buffer - 10591744 to 10591880
  writeRegister(0x04, 0x07); // TX - 10591893 to 10592028
  writeRegister(0x00, 0xFF); // CS0 - 10598674 to 10598817
  writeRegister(0x01, 0xFF); // CS1 - 10598824 to 10598965
  writeRegister(0x16, 0xC0); // FIFO CTRL - 10598977 to 10599112
  writeRegister(0x40, 0x04); // TX Buffer - 10599126 to 10599259
  writeRegister(0x41, 0x0E); // TX Buffer - 10599269 to 10599408
  writeRegister(0x44, 0x23); // TX Buffer - 10599418 to 10599556
  writeRegister(0x45, 0x11); // TX Buffer - 10599566 to 10599706
  writeRegister(0x46, 0x13); // TX Buffer - 10599715 to 10599853
  writeRegister(0x04, 0x07); // TX - 10599864 to 10600001
  writeRegister(0x00, 0xFF); // CS0 - 10606645 to 10606784
  writeRegister(0x01, 0xFF); // CS1 - 10606798 to 10606936
  writeRegister(0x16, 0xC0); // FIFO CTRL - 10606949 to 10607083
  writeRegister(0x40, 0x04); // TX Buffer - 10607097 to 10607230
  writeRegister(0x41, 0x0E); // TX Buffer - 10607244 to 10607379
  writeRegister(0x44, 0x23); // TX Buffer - 10607392 to 10607527
  writeRegister(0x45, 0x11); // TX Buffer - 10607541 to 10607677
  writeRegister(0x46, 0x13); // TX Buffer - 10607689 to 10607826
  writeRegister(0x04, 0x07); // TX - 10607838 to 10607972
  writeRegister(0x00, 0xFF); // CS0 - 10614701 to 10614840
  writeRegister(0x01, 0xFF); // CS1 - 10614854 to 10614998
  writeRegister(0x16, 0xC0); // FIFO CTRL - 10615004 to 10615142
  writeRegister(0x40, 0x04); // TX Buffer - 10615153 to 10615286
  writeRegister(0x41, 0x0E); // TX Buffer - 10615300 to 10615434
  writeRegister(0x44, 0x23); // TX Buffer - 10615448 to 10615584
  writeRegister(0x45, 0x11); // TX Buffer - 10615597 to 10615731
  writeRegister(0x46, 0x13); // TX Buffer - 10615745 to 10615880
  writeRegister(0x04, 0x07); // TX - 10615894 to 10616028
  writeRegister(0x00, 0xFF); // CS0 - 10622675 to 10622819
  writeRegister(0x01, 0xFF); // CS1 - 10622825 to 10622965
  writeRegister(0x16, 0xC0); // FIFO CTRL - 10622979 to 10623115
  writeRegister(0x40, 0x04); // TX Buffer - 10623127 to 10623260
  writeRegister(0x41, 0x0E); // TX Buffer - 10623271 to 10623409
  writeRegister(0x44, 0x23); // TX Buffer - 10623419 to 10623561
  writeRegister(0x45, 0x11); // TX Buffer - 10623568 to 10623710
  writeRegister(0x46, 0x13); // TX Buffer - 10623716 to 10623856
  writeRegister(0x04, 0x07); // TX - 10623865 to 10624007
  writeRegister(0x00, 0xFF); // CS0 - 10630646 to 10630787
  writeRegister(0x01, 0xFF); // CS1 - 10630799 to 10630936
  writeRegister(0x16, 0xC0); // FIFO CTRL - 10630950 to 10631085
  writeRegister(0x40, 0x04); // TX Buffer - 10631098 to 10631232
  writeRegister(0x41, 0x0E); // TX Buffer - 10631245 to 10631380
  writeRegister(0x44, 0x23); // TX Buffer - 10631394 to 10631528
  writeRegister(0x45, 0x11); // TX Buffer - 10631542 to 10631678
  writeRegister(0x46, 0x13); // TX Buffer - 10631691 to 10631827
  writeRegister(0x04, 0x07); // TX - 10631840 to 10631975
  writeRegister(0x00, 0xFF); // CS0 - 10638702 to 10638843
  writeRegister(0x01, 0xFF); // CS1 - 10638855 to 10638993
  writeRegister(0x16, 0xC0); // FIFO CTRL - 10639006 to 10639140
  writeRegister(0x40, 0x04); // TX Buffer - 10639154 to 10639287
  writeRegister(0x41, 0x0E); // TX Buffer - 10639301 to 10639436
  writeRegister(0x44, 0x23); // TX Buffer - 10639450 to 10639584
  writeRegister(0x45, 0x11); // TX Buffer - 10639598 to 10639734
  writeRegister(0x46, 0x13); // TX Buffer - 10639746 to 10639883
  writeRegister(0x04, 0x07); // TX - 10639895 to 10640031
  writeRegister(0x00, 0xFF); // CS0 - 10646676 to 10646814
  writeRegister(0x01, 0xFF); // CS1 - 10646826 to 10646966
  writeRegister(0x16, 0xC0); // FIFO CTRL - 10646977 to 10647115
  writeRegister(0x40, 0x04); // TX Buffer - 10647125 to 10647266
  writeRegister(0x41, 0x0E); // TX Buffer - 10647272 to 10647413
  writeRegister(0x44, 0x23); // TX Buffer - 10647421 to 10647563
  writeRegister(0x45, 0x11); // TX Buffer - 10647569 to 10647711
  writeRegister(0x46, 0x13); // TX Buffer - 10647717 to 10647860
  writeRegister(0x04, 0x07); // TX - 10647866 to 10648008
  writeRegister(0x00, 0xFF); // CS0 - 10654732 to 10654876
  writeRegister(0x01, 0xFF); // CS1 - 10654882 to 10655022
  writeRegister(0x16, 0xC0); // FIFO CTRL - 10655036 to 10655171
  writeRegister(0x40, 0x04); // TX Buffer - 10655184 to 10655318
  writeRegister(0x41, 0x0E); // TX Buffer - 10655328 to 10655466
  writeRegister(0x44, 0x23); // TX Buffer - 10655476 to 10655619
  writeRegister(0x45, 0x11); // TX Buffer - 10655625 to 10655767
  writeRegister(0x46, 0x13); // TX Buffer - 10655773 to 10655913
  writeRegister(0x04, 0x07); // TX - 10655922 to 10656064
  writeRegister(0x00, 0xFF); // CS0 - 10662703 to 10662844
  writeRegister(0x01, 0xFF); // CS1 - 10662857 to 10662993
  writeRegister(0x16, 0xC0); // FIFO CTRL - 10663007 to 10663142
  writeRegister(0x40, 0x04); // TX Buffer - 10663155 to 10663289
  writeRegister(0x41, 0x0E); // TX Buffer - 10663302 to 10663437
  writeRegister(0x44, 0x23); // TX Buffer - 10663451 to 10663587
  writeRegister(0x45, 0x11); // TX Buffer - 10663599 to 10663735
  writeRegister(0x46, 0x13); // TX Buffer - 10663748 to 10663884
  writeRegister(0x04, 0x07); // TX - 10663897 to 10664032
  writeRegister(0x00, 0xFF); // CS0 - 10670678 to 10670815
  writeRegister(0x01, 0xFF); // CS1 - 10670828 to 10670969
  writeRegister(0x16, 0xC0); // FIFO CTRL - 10670978 to 10671116
  writeRegister(0x40, 0x04); // TX Buffer - 10671126 to 10671260
  writeRegister(0x41, 0x0E); // TX Buffer - 10671273 to 10671408
  writeRegister(0x44, 0x23); // TX Buffer - 10671422 to 10671558
  writeRegister(0x45, 0x11); // TX Buffer - 10671570 to 10671705
  writeRegister(0x46, 0x13); // TX Buffer - 10671719 to 10671861
  writeRegister(0x04, 0x07); // TX - 10671868 to 10672003
  writeRegister(0x00, 0xFF); // CS0 - 10678733 to 10678871
  writeRegister(0x01, 0xFF); // CS1 - 10678883 to 10679023
  writeRegister(0x16, 0xC0); // FIFO CTRL - 10679034 to 10679172
  writeRegister(0x40, 0x04); // TX Buffer - 10679182 to 10679323
  writeRegister(0x41, 0x0E); // TX Buffer - 10679329 to 10679470
  writeRegister(0x44, 0x23); // TX Buffer - 10679478 to 10679620
  writeRegister(0x45, 0x11); // TX Buffer - 10679626 to 10679768
  writeRegister(0x46, 0x13); // TX Buffer - 10679775 to 10679917
  writeRegister(0x04, 0x07); // TX - 10679924 to 10680065
  writeRegister(0x00, 0xFF); // CS0 - 10686705 to 10686844
  writeRegister(0x01, 0xFF); // CS1 - 10686854 to 10686996
  writeRegister(0x16, 0xC0); // FIFO CTRL - 10687008 to 10687143
  writeRegister(0x40, 0x04); // TX Buffer - 10687157 to 10687290
  writeRegister(0x41, 0x0E); // TX Buffer - 10687304 to 10687438
  writeRegister(0x44, 0x23); // TX Buffer - 10687452 to 10687588
  writeRegister(0x45, 0x11); // TX Buffer - 10687601 to 10687735
  writeRegister(0x46, 0x13); // TX Buffer - 10687749 to 10687884
  writeRegister(0x04, 0x07); // TX - 10687898 to 10688032
  writeRegister(0x00, 0xFF); // CS0 - 10694679 to 10694815
  writeRegister(0x01, 0xFF); // CS1 - 10694829 to 10694969
  writeRegister(0x16, 0xC0); // FIFO CTRL - 10694980 to 10695118
  writeRegister(0x40, 0x04); // TX Buffer - 10695128 to 10695261
  writeRegister(0x41, 0x0E); // TX Buffer - 10695275 to 10695410
  writeRegister(0x44, 0x23); // TX Buffer - 10695423 to 10695558
  writeRegister(0x45, 0x11); // TX Buffer - 10695572 to 10695708
  writeRegister(0x46, 0x13); // TX Buffer - 10695720 to 10695857
  writeRegister(0x04, 0x07); // TX - 10695869 to 10696005
  writeRegister(0x00, 0xFF); // CS0 - 10702673 to 10702817
  writeRegister(0x01, 0xFF); // CS1 - 10702823 to 10702963
  writeRegister(0x16, 0xC0); // FIFO CTRL - 10702977 to 10703112
  writeRegister(0x40, 0x04); // TX Buffer - 10703125 to 10703259
  writeRegister(0x41, 0x0E); // TX Buffer - 10703269 to 10703407
  writeRegister(0x44, 0x23); // TX Buffer - 10703417 to 10703560
  writeRegister(0x45, 0x11); // TX Buffer - 10703566 to 10703708
  writeRegister(0x46, 0x13); // TX Buffer - 10703714 to 10703854
  writeRegister(0x04, 0x07); // TX - 10703863 to 10704005
  writeRegister(0x00, 0xFF); // CS0 - 10710729 to 10710873
  writeRegister(0x01, 0xFF); // CS1 - 10710879 to 10711019
  writeRegister(0x16, 0xC0); // FIFO CTRL - 10711033 to 10711169
  writeRegister(0x40, 0x04); // TX Buffer - 10711181 to 10711316
  writeRegister(0x41, 0x0E); // TX Buffer - 10711325 to 10711463
  writeRegister(0x44, 0x23); // TX Buffer - 10711473 to 10711611
  writeRegister(0x45, 0x11); // TX Buffer - 10711622 to 10711761
  writeRegister(0x46, 0x13); // TX Buffer - 10711770 to 10711910
  writeRegister(0x04, 0x07); // TX - 10711919 to 10712058
  writeRegister(0x00, 0xFF); // CS0 - 10718700 to 10718841
  writeRegister(0x01, 0xFF); // CS1 - 10718853 to 10718990
  writeRegister(0x16, 0xC0); // FIFO CTRL - 10719004 to 10719139
  writeRegister(0x40, 0x04); // TX Buffer - 10719152 to 10719286
  writeRegister(0x41, 0x0E); // TX Buffer - 10719299 to 10719434
  writeRegister(0x44, 0x23); // TX Buffer - 10719448 to 10719582
  writeRegister(0x45, 0x11); // TX Buffer - 10719596 to 10719732
  writeRegister(0x46, 0x13); // TX Buffer - 10719745 to 10719881
  writeRegister(0x04, 0x07); // TX - 10719894 to 10720029
  writeRegister(0x00, 0xFF); // CS0 - 10726675 to 10726812
  writeRegister(0x01, 0xFF); // CS1 - 10726825 to 10726966
  writeRegister(0x16, 0xC0); // FIFO CTRL - 10726975 to 10727113
  writeRegister(0x40, 0x04); // TX Buffer - 10727123 to 10727263
  writeRegister(0x41, 0x0E); // TX Buffer - 10727270 to 10727411
  writeRegister(0x44, 0x23); // TX Buffer - 10727419 to 10727561
  writeRegister(0x45, 0x11); // TX Buffer - 10727567 to 10727709
  writeRegister(0x46, 0x13); // TX Buffer - 10727716 to 10727858
  writeRegister(0x04, 0x07); // TX - 10727865 to 10728006
  writeRegister(0x00, 0xFF); // CS0 - 10734730 to 10734874
  writeRegister(0x01, 0xFF); // CS1 - 10734880 to 10735020
  writeRegister(0x16, 0xC0); // FIFO CTRL - 10735034 to 10735169
  writeRegister(0x40, 0x04); // TX Buffer - 10735183 to 10735316
  writeRegister(0x41, 0x0E); // TX Buffer - 10735326 to 10735464
  writeRegister(0x44, 0x23); // TX Buffer - 10735475 to 10735617
  writeRegister(0x45, 0x11); // TX Buffer - 10735623 to 10735765
  writeRegister(0x46, 0x13); // TX Buffer - 10735771 to 10735910
  writeRegister(0x04, 0x07); // TX - 10735920 to 10736062
  writeRegister(0x00, 0xFF); // CS0 - 10742701 to 10742841
  writeRegister(0x01, 0xFF); // CS1 - 10742855 to 10742991
  writeRegister(0x16, 0xC0); // FIFO CTRL - 10743005 to 10743140
  writeRegister(0x40, 0x04); // TX Buffer - 10743154 to 10743287
  writeRegister(0x41, 0x0E); // TX Buffer - 10743301 to 10743435
  writeRegister(0x44, 0x23); // TX Buffer - 10743449 to 10743585
  writeRegister(0x45, 0x11); // TX Buffer - 10743598 to 10743732
  writeRegister(0x46, 0x13); // TX Buffer - 10743746 to 10743881
  writeRegister(0x04, 0x07); // TX - 10743895 to 10744029
  writeRegister(0x00, 0xFF); // CS0 - 10750676 to 10750812
  writeRegister(0x01, 0xFF); // CS1 - 10750826 to 10750967
  writeRegister(0x16, 0xC0); // FIFO CTRL - 10750976 to 10751114
  writeRegister(0x40, 0x04); // TX Buffer - 10751125 to 10751258
  writeRegister(0x41, 0x0E); // TX Buffer - 10751272 to 10751406
  writeRegister(0x44, 0x23); // TX Buffer - 10751420 to 10751556
  writeRegister(0x45, 0x11); // TX Buffer - 10751569 to 10751703
  writeRegister(0x46, 0x13); // TX Buffer - 10751717 to 10751860
  writeRegister(0x04, 0x07); // TX - 10751866 to 10752000
  writeRegister(0x00, 0xFF); // CS0 - 10758732 to 10758869
  writeRegister(0x01, 0xFF); // CS1 - 10758882 to 10759023
  writeRegister(0x16, 0xC0); // FIFO CTRL - 10759032 to 10759170
  writeRegister(0x40, 0x04); // TX Buffer - 10759180 to 10759320
  writeRegister(0x41, 0x0E); // TX Buffer - 10759327 to 10759470
  writeRegister(0x44, 0x23); // TX Buffer - 10759476 to 10759618
  writeRegister(0x45, 0x11); // TX Buffer - 10759624 to 10759767
  writeRegister(0x46, 0x13); // TX Buffer - 10759773 to 10759915
  writeRegister(0x04, 0x07); // TX - 10759922 to 10760063
  writeRegister(0x00, 0xFF); // CS0 - 10766703 to 10766842
  writeRegister(0x01, 0xFF); // CS1 - 10766853 to 10766994
  writeRegister(0x16, 0xC0); // FIFO CTRL - 10767007 to 10767141
  writeRegister(0x40, 0x04); // TX Buffer - 10767155 to 10767288
  writeRegister(0x41, 0x0E); // TX Buffer - 10767302 to 10767437
  writeRegister(0x44, 0x23); // TX Buffer - 10767450 to 10767585
  writeRegister(0x45, 0x11); // TX Buffer - 10767599 to 10767735
  writeRegister(0x46, 0x13); // TX Buffer - 10767747 to 10767884
  writeRegister(0x04, 0x07); // TX - 10767896 to 10768030
  writeRegister(0x00, 0xFF); // CS0 - 10774674 to 10774813
  writeRegister(0x01, 0xFF); // CS1 - 10774827 to 10774971
  writeRegister(0x16, 0xC0); // FIFO CTRL - 10774978 to 10775116
  writeRegister(0x40, 0x04); // TX Buffer - 10775126 to 10775259
  writeRegister(0x41, 0x0E); // TX Buffer - 10775273 to 10775408
  writeRegister(0x44, 0x23); // TX Buffer - 10775421 to 10775556
  writeRegister(0x45, 0x11); // TX Buffer - 10775570 to 10775706
  writeRegister(0x46, 0x13); // TX Buffer - 10775718 to 10775855
  writeRegister(0x04, 0x07); // TX - 10775867 to 10776003
  writeRegister(0x00, 0xFF); // CS0 - 10782733 to 10782869
  writeRegister(0x01, 0xFF); // CS1 - 10782883 to 10783023
  writeRegister(0x16, 0xC0); // FIFO CTRL - 10783033 to 10783171
  writeRegister(0x40, 0x04); // TX Buffer - 10783182 to 10783315
  writeRegister(0x41, 0x0E); // TX Buffer - 10783329 to 10783465
  writeRegister(0x44, 0x23); // TX Buffer - 10783477 to 10783613
  writeRegister(0x45, 0x11); // TX Buffer - 10783626 to 10783760
  writeRegister(0x46, 0x13); // TX Buffer - 10783774 to 10783917
  writeRegister(0x04, 0x07); // TX - 10783923 to 10784057
  writeRegister(0x00, 0xFF); // CS0 - 10790704 to 10790845
  writeRegister(0x01, 0xFF); // CS1 - 10790854 to 10790994
  writeRegister(0x16, 0xC0); // FIFO CTRL - 10791008 to 10791143
  writeRegister(0x40, 0x04); // TX Buffer - 10791156 to 10791291
  writeRegister(0x41, 0x0E); // TX Buffer - 10791300 to 10791438
  writeRegister(0x44, 0x23); // TX Buffer - 10791448 to 10791586
  writeRegister(0x45, 0x11); // TX Buffer - 10791597 to 10791736
  writeRegister(0x46, 0x13); // TX Buffer - 10791745 to 10791885
  writeRegister(0x04, 0x07); // TX - 10791898 to 10792033
  writeRegister(0x00, 0xFF); // CS0 - 10798675 to 10798816
  writeRegister(0x01, 0xFF); // CS1 - 10798828 to 10798973
  writeRegister(0x16, 0xC0); // FIFO CTRL - 10798979 to 10799120
  writeRegister(0x40, 0x04); // TX Buffer - 10799127 to 10799261
  writeRegister(0x41, 0x0E); // TX Buffer - 10799274 to 10799409
  writeRegister(0x44, 0x23); // TX Buffer - 10799423 to 10799557
  writeRegister(0x45, 0x11); // TX Buffer - 10799571 to 10799707
  writeRegister(0x46, 0x13); // TX Buffer - 10799720 to 10799856
  writeRegister(0x04, 0x07); // TX - 10799869 to 10800004
  writeRegister(0x00, 0xFF); // CS0 - 10806731 to 10806872
  writeRegister(0x01, 0xFF); // CS1 - 10806884 to 10807028
  writeRegister(0x16, 0xC0); // FIFO CTRL - 10807035 to 10807173
  writeRegister(0x40, 0x04); // TX Buffer - 10807183 to 10807316
  writeRegister(0x41, 0x0E); // TX Buffer - 10807330 to 10807465
  writeRegister(0x44, 0x23); // TX Buffer - 10807479 to 10807613
  writeRegister(0x45, 0x11); // TX Buffer - 10807627 to 10807763
  writeRegister(0x46, 0x13); // TX Buffer - 10807775 to 10807912
  writeRegister(0x04, 0x07); // TX - 10807924 to 10808060
  writeRegister(0x00, 0xFF); // CS0 - 10814705 to 10814849
  writeRegister(0x01, 0xFF); // CS1 - 10814855 to 10814995
  writeRegister(0x16, 0xC0); // FIFO CTRL - 10815009 to 10815144
  writeRegister(0x40, 0x04); // TX Buffer - 10815158 to 10815291
  writeRegister(0x41, 0x0E); // TX Buffer - 10815301 to 10815439
  writeRegister(0x44, 0x23); // TX Buffer - 10815450 to 10815589
  writeRegister(0x45, 0x11); // TX Buffer - 10815598 to 10815736
  writeRegister(0x46, 0x13); // TX Buffer - 10815747 to 10815885
  writeRegister(0x04, 0x07); // TX - 10815895 to 10816033
  writeRegister(0x00, 0xFF); // CS0 - 10822676 to 10822816
  writeRegister(0x01, 0xFF); // CS1 - 10822830 to 10822966
  writeRegister(0x16, 0xC0); // FIFO CTRL - 10822980 to 10823115
  writeRegister(0x40, 0x04); // TX Buffer - 10823129 to 10823262
  writeRegister(0x41, 0x0E); // TX Buffer - 10823276 to 10823410
  writeRegister(0x44, 0x23); // TX Buffer - 10823424 to 10823560
  writeRegister(0x45, 0x11); // TX Buffer - 10823573 to 10823707
  writeRegister(0x46, 0x13); // TX Buffer - 10823721 to 10823856
  writeRegister(0x04, 0x07); // TX - 10823870 to 10824004
  writeRegister(0x00, 0xFF); // CS0 - 10830732 to 10830873
  writeRegister(0x01, 0xFF); // CS1 - 10830886 to 10831030
  writeRegister(0x16, 0xC0); // FIFO CTRL - 10831036 to 10831177
  writeRegister(0x40, 0x04); // TX Buffer - 10831184 to 10831318
  writeRegister(0x41, 0x0E); // TX Buffer - 10831331 to 10831466
  writeRegister(0x44, 0x23); // TX Buffer - 10831480 to 10831616
  writeRegister(0x45, 0x11); // TX Buffer - 10831628 to 10831763
  writeRegister(0x46, 0x13); // TX Buffer - 10831777 to 10831913
  writeRegister(0x04, 0x07); // TX - 10831926 to 10832061
  writeRegister(0x00, 0xFF); // CS0 - 10838707 to 10838844
  writeRegister(0x01, 0xFF); // CS1 - 10838857 to 10838998
  writeRegister(0x16, 0xC0); // FIFO CTRL - 10839010 to 10839145
  writeRegister(0x40, 0x04); // TX Buffer - 10839159 to 10839292
  writeRegister(0x41, 0x0E); // TX Buffer - 10839303 to 10839441
  writeRegister(0x44, 0x23); // TX Buffer - 10839451 to 10839593
  writeRegister(0x45, 0x11); // TX Buffer - 10839599 to 10839742
  writeRegister(0x46, 0x13); // TX Buffer - 10839748 to 10839886
  writeRegister(0x04, 0x07); // TX - 10839897 to 10840038
  writeRegister(0x00, 0xFF); // CS0 - 10846678 to 10846817
  writeRegister(0x01, 0xFF); // CS1 - 10846828 to 10846969
  writeRegister(0x16, 0xC0); // FIFO CTRL - 10846982 to 10847116
  writeRegister(0x40, 0x04); // TX Buffer - 10847130 to 10847263
  writeRegister(0x41, 0x0E); // TX Buffer - 10847277 to 10847412
  writeRegister(0x44, 0x23); // TX Buffer - 10847425 to 10847560
  writeRegister(0x45, 0x11); // TX Buffer - 10847574 to 10847710
  writeRegister(0x46, 0x13); // TX Buffer - 10847722 to 10847859
  writeRegister(0x04, 0x07); // TX - 10847871 to 10848005
  writeRegister(0x00, 0xFF); // CS0 - 10854734 to 10854873
  writeRegister(0x01, 0xFF); // CS1 - 10854887 to 10855025
  writeRegister(0x16, 0xC0); // FIFO CTRL - 10855037 to 10855172
  writeRegister(0x40, 0x04); // TX Buffer - 10855186 to 10855319
  writeRegister(0x41, 0x0E); // TX Buffer - 10855333 to 10855467
  writeRegister(0x44, 0x23); // TX Buffer - 10855481 to 10855617
  writeRegister(0x45, 0x11); // TX Buffer - 10855630 to 10855764
  writeRegister(0x46, 0x13); // TX Buffer - 10855778 to 10855913
  writeRegister(0x04, 0x07); // TX - 10855927 to 10856061
  writeRegister(0x00, 0xFF); // CS0 - 10862708 to 10862844
  writeRegister(0x01, 0xFF); // CS1 - 10862858 to 10862998
  writeRegister(0x16, 0xC0); // FIFO CTRL - 10863008 to 10863148
  writeRegister(0x40, 0x04); // TX Buffer - 10863157 to 10863290
  writeRegister(0x41, 0x0E); // TX Buffer - 10863304 to 10863440
  writeRegister(0x44, 0x23); // TX Buffer - 10863452 to 10863588
  writeRegister(0x45, 0x11); // TX Buffer - 10863601 to 10863735
  writeRegister(0x46, 0x13); // TX Buffer - 10863749 to 10863892
  writeRegister(0x04, 0x07); // TX - 10863898 to 10864032
  writeRegister(0x00, 0xFF); // CS0 - 10870679 to 10870820
  writeRegister(0x01, 0xFF); // CS1 - 10870829 to 10870969
  writeRegister(0x16, 0xC0); // FIFO CTRL - 10870983 to 10871118
  writeRegister(0x40, 0x04); // TX Buffer - 10871131 to 10871265
  writeRegister(0x41, 0x0E); // TX Buffer - 10871275 to 10871413
  writeRegister(0x44, 0x23); // TX Buffer - 10871423 to 10871561
  writeRegister(0x45, 0x11); // TX Buffer - 10871572 to 10871711
  writeRegister(0x46, 0x13); // TX Buffer - 10871720 to 10871860
  writeRegister(0x04, 0x07); // TX - 10871873 to 10872008
  writeRegister(0x00, 0xFF); // CS0 - 10878735 to 10878876
  writeRegister(0x01, 0xFF); // CS1 - 10878885 to 10879026
  writeRegister(0x16, 0xC0); // FIFO CTRL - 10879039 to 10879173
  writeRegister(0x40, 0x04); // TX Buffer - 10879187 to 10879320
  writeRegister(0x41, 0x0E); // TX Buffer - 10879334 to 10879469
  writeRegister(0x44, 0x23); // TX Buffer - 10879483 to 10879617
  writeRegister(0x45, 0x11); // TX Buffer - 10879631 to 10879767
  writeRegister(0x46, 0x13); // TX Buffer - 10879779 to 10879916
  writeRegister(0x04, 0x07); // TX - 10879928 to 10880064
  writeRegister(0x00, 0xFF); // CS0 - 10886709 to 10886847
  writeRegister(0x01, 0xFF); // CS1 - 10886859 to 10886999
  writeRegister(0x16, 0xC0); // FIFO CTRL - 10887010 to 10887148
  writeRegister(0x40, 0x04); // TX Buffer - 10887158 to 10887291
  writeRegister(0x41, 0x0E); // TX Buffer - 10887305 to 10887440
  writeRegister(0x44, 0x23); // TX Buffer - 10887454 to 10887588
  writeRegister(0x45, 0x11); // TX Buffer - 10887602 to 10887738
  writeRegister(0x46, 0x13); // TX Buffer - 10887750 to 10887887
  writeRegister(0x04, 0x07); // TX - 10887899 to 10888035
  writeRegister(0x00, 0xFF); // CS0 - 10894680 to 10894824
  writeRegister(0x01, 0xFF); // CS1 - 10894830 to 10894970
  writeRegister(0x16, 0xC0); // FIFO CTRL - 10894984 to 10895119
  writeRegister(0x40, 0x04); // TX Buffer - 10895133 to 10895266
  writeRegister(0x41, 0x0E); // TX Buffer - 10895276 to 10895414
  writeRegister(0x44, 0x23); // TX Buffer - 10895425 to 10895564
  writeRegister(0x45, 0x11); // TX Buffer - 10895573 to 10895711
  writeRegister(0x46, 0x13); // TX Buffer - 10895722 to 10895860
  writeRegister(0x04, 0x07); // TX - 10895870 to 10896008
  writeRegister(0x00, 0xFF); // CS0 - 10902736 to 10902877
  writeRegister(0x01, 0xFF); // CS1 - 10902886 to 10903026
  writeRegister(0x16, 0xC0); // FIFO CTRL - 10903040 to 10903175
  writeRegister(0x40, 0x04); // TX Buffer - 10903188 to 10903322
  writeRegister(0x41, 0x0E); // TX Buffer - 10903332 to 10903470
  writeRegister(0x44, 0x23); // TX Buffer - 10903480 to 10903620
  writeRegister(0x45, 0x11); // TX Buffer - 10903629 to 10903768
  writeRegister(0x46, 0x13); // TX Buffer - 10903777 to 10903917
  writeRegister(0x04, 0x07); // TX - 10903930 to 10904065
  writeRegister(0x00, 0xFF); // CS0 - 10910707 to 10910848
  writeRegister(0x01, 0xFF); // CS1 - 10910861 to 10911005
  writeRegister(0x16, 0xC0); // FIFO CTRL - 10911011 to 10911149
  writeRegister(0x40, 0x04); // TX Buffer - 10911159 to 10911293
  writeRegister(0x41, 0x0E); // TX Buffer - 10911306 to 10911441
  writeRegister(0x44, 0x23); // TX Buffer - 10911455 to 10911591
  writeRegister(0x45, 0x11); // TX Buffer - 10911603 to 10911738
  writeRegister(0x46, 0x13); // TX Buffer - 10911752 to 10911888
  writeRegister(0x04, 0x07); // TX - 10911901 to 10912036
  writeRegister(0x00, 0xFF); // CS0 - 10918682 to 10918825
  writeRegister(0x01, 0xFF); // CS1 - 10918832 to 10918973
  writeRegister(0x16, 0xC0); // FIFO CTRL - 10918986 to 10919120
  writeRegister(0x40, 0x04); // TX Buffer - 10919134 to 10919267
  writeRegister(0x41, 0x0E); // TX Buffer - 10919278 to 10919416
  writeRegister(0x44, 0x23); // TX Buffer - 10919426 to 10919568
  writeRegister(0x45, 0x11); // TX Buffer - 10919574 to 10919717
  writeRegister(0x46, 0x13); // TX Buffer - 10919723 to 10919863
  writeRegister(0x04, 0x07); // TX - 10919872 to 10920012
  writeRegister(0x00, 0xFF); // CS0 - 10926738 to 10926881
  writeRegister(0x01, 0xFF); // CS1 - 10926887 to 10927029
  writeRegister(0x16, 0xC0); // FIFO CTRL - 10927041 to 10927176
  writeRegister(0x40, 0x04); // TX Buffer - 10927190 to 10927323
  writeRegister(0x41, 0x0E); // TX Buffer - 10927333 to 10927471
  writeRegister(0x44, 0x23); // TX Buffer - 10927482 to 10927621
  writeRegister(0x45, 0x11); // TX Buffer - 10927630 to 10927768
  writeRegister(0x46, 0x13); // TX Buffer - 10927779 to 10927917
  writeRegister(0x04, 0x07); // TX - 10927928 to 10928065
  writeRegister(0x00, 0xFF); // CS0 - 10934709 to 10934848
  writeRegister(0x01, 0xFF); // CS1 - 10934862 to 10935000
  writeRegister(0x16, 0xC0); // FIFO CTRL - 10935012 to 10935147
  writeRegister(0x40, 0x04); // TX Buffer - 10935161 to 10935294
  writeRegister(0x41, 0x0E); // TX Buffer - 10935308 to 10935444
  writeRegister(0x44, 0x23); // TX Buffer - 10935456 to 10935592
  writeRegister(0x45, 0x11); // TX Buffer - 10935605 to 10935739
  writeRegister(0x46, 0x13); // TX Buffer - 10935753 to 10935888
  writeRegister(0x04, 0x07); // TX - 10935902 to 10936036
  writeRegister(0x00, 0xFF); // CS0 - 10942683 to 10942819
  writeRegister(0x01, 0xFF); // CS1 - 10942833 to 10942973
  writeRegister(0x16, 0xC0); // FIFO CTRL - 10942983 to 10943122
  writeRegister(0x40, 0x04); // TX Buffer - 10943132 to 10943273
  writeRegister(0x41, 0x0E); // TX Buffer - 10943279 to 10943420
  writeRegister(0x44, 0x23); // TX Buffer - 10943427 to 10943569
  writeRegister(0x45, 0x11); // TX Buffer - 10943576 to 10943718
  writeRegister(0x46, 0x13); // TX Buffer - 10943724 to 10943867
  writeRegister(0x04, 0x07); // TX - 10943873 to 10944015
  writeRegister(0x00, 0xFF); // CS0 - 10950739 to 10950881
  writeRegister(0x01, 0xFF); // CS1 - 10950889 to 10951030
  writeRegister(0x16, 0xC0); // FIFO CTRL - 10951043 to 10951177
  writeRegister(0x40, 0x04); // TX Buffer - 10951191 to 10951324
  writeRegister(0x41, 0x0E); // TX Buffer - 10951335 to 10951473
  writeRegister(0x44, 0x23); // TX Buffer - 10951483 to 10951625
  writeRegister(0x45, 0x11); // TX Buffer - 10951632 to 10951774
  writeRegister(0x46, 0x13); // TX Buffer - 10951780 to 10951920
  writeRegister(0x04, 0x07); // TX - 10951929 to 10952071
  writeRegister(0x00, 0xFF); // CS0 - 10958710 to 10958851
  writeRegister(0x01, 0xFF); // CS1 - 10958863 to 10959001
  writeRegister(0x16, 0xC0); // FIFO CTRL - 10959014 to 10959148
  writeRegister(0x40, 0x04); // TX Buffer - 10959162 to 10959295
  writeRegister(0x41, 0x0E); // TX Buffer - 10959309 to 10959444
  writeRegister(0x44, 0x23); // TX Buffer - 10959458 to 10959592
  writeRegister(0x45, 0x11); // TX Buffer - 10959606 to 10959742
  writeRegister(0x46, 0x13); // TX Buffer - 10959754 to 10959891
  writeRegister(0x04, 0x07); // TX - 10959903 to 10960039
  writeRegister(0x00, 0xFF); // CS0 - 10966684 to 10966822
  writeRegister(0x01, 0xFF); // CS1 - 10966834 to 10966974
  writeRegister(0x16, 0xC0); // FIFO CTRL - 10966985 to 10967123
  writeRegister(0x40, 0x04); // TX Buffer - 10967133 to 10967266
  writeRegister(0x41, 0x0E); // TX Buffer - 10967280 to 10967415
  writeRegister(0x44, 0x23); // TX Buffer - 10967429 to 10967563
  writeRegister(0x45, 0x11); // TX Buffer - 10967577 to 10967713
  writeRegister(0x46, 0x13); // TX Buffer - 10967726 to 10967868
  writeRegister(0x04, 0x07); // TX - 10967874 to 10968010
  writeRegister(0x00, 0xFF); // CS0 - 10974740 to 10974876
  writeRegister(0x01, 0xFF); // CS1 - 10974890 to 10975030
  writeRegister(0x16, 0xC0); // FIFO CTRL - 10975041 to 10975179
  writeRegister(0x40, 0x04); // TX Buffer - 10975189 to 10975330
  writeRegister(0x41, 0x0E); // TX Buffer - 10975336 to 10975477
  writeRegister(0x44, 0x23); // TX Buffer - 10975484 to 10975627
  writeRegister(0x45, 0x11); // TX Buffer - 10975633 to 10975775
  writeRegister(0x46, 0x13); // TX Buffer - 10975781 to 10975924
  writeRegister(0x04, 0x07); // TX - 10975930 to 10976072
  writeRegister(0x00, 0xFF); // CS0 - 10982711 to 10982852
  writeRegister(0x01, 0xFF); // CS1 - 10982861 to 10983001
  writeRegister(0x16, 0xC0); // FIFO CTRL - 10983015 to 10983150
  writeRegister(0x40, 0x04); // TX Buffer - 10983163 to 10983297
  writeRegister(0x41, 0x0E); // TX Buffer - 10983310 to 10983445
  writeRegister(0x44, 0x23); // TX Buffer - 10983459 to 10983595
  writeRegister(0x45, 0x11); // TX Buffer - 10983607 to 10983742
  writeRegister(0x46, 0x13); // TX Buffer - 10983756 to 10983892
  writeRegister(0x04, 0x07); // TX - 10983905 to 10984040
  writeRegister(0x00, 0xFF); // CS0 - 10990682 to 10990823
  writeRegister(0x01, 0xFF); // CS1 - 10990836 to 10990980
  writeRegister(0x16, 0xC0); // FIFO CTRL - 10990986 to 10991124
  writeRegister(0x40, 0x04); // TX Buffer - 10991135 to 10991268
  writeRegister(0x41, 0x0E); // TX Buffer - 10991282 to 10991416
  writeRegister(0x44, 0x23); // TX Buffer - 10991430 to 10991566
  writeRegister(0x45, 0x11); // TX Buffer - 10991578 to 10991713
  writeRegister(0x46, 0x13); // TX Buffer - 10991727 to 10991862
  writeRegister(0x04, 0x07); // TX - 10991876 to 10992011
  writeRegister(0x00, 0xFF); // CS0 - 10998742 to 10998879
  writeRegister(0x01, 0xFF); // CS1 - 10998891 to 10999033
  writeRegister(0x16, 0xC0); // FIFO CTRL - 10999042 to 10999180
  writeRegister(0x40, 0x04); // TX Buffer - 10999190 to 10999324
  writeRegister(0x41, 0x0E); // TX Buffer - 10999337 to 10999472
  writeRegister(0x44, 0x23); // TX Buffer - 10999486 to 10999620
  writeRegister(0x45, 0x11); // TX Buffer - 10999634 to 10999770
  writeRegister(0x46, 0x13); // TX Buffer - 10999783 to 10999925
  writeRegister(0x04, 0x07); // TX - 10999932 to 11000067
  writeRegister(0x00, 0xFF); // CS0 - 11006713 to 11006852
  writeRegister(0x01, 0xFF); // CS1 - 11006863 to 11007004
  writeRegister(0x16, 0xC0); // FIFO CTRL - 11007016 to 11007151
  writeRegister(0x40, 0x04); // TX Buffer - 11007165 to 11007298
  writeRegister(0x41, 0x0E); // TX Buffer - 11007308 to 11007446
  writeRegister(0x44, 0x23); // TX Buffer - 11007457 to 11007596
  writeRegister(0x45, 0x11); // TX Buffer - 11007605 to 11007743
  writeRegister(0x46, 0x13); // TX Buffer - 11007754 to 11007892
  writeRegister(0x04, 0x07); // TX - 11007906 to 11008040
  writeRegister(0x00, 0xFF); // CS0 - 11014684 to 11014823
  writeRegister(0x01, 0xFF); // CS1 - 11014837 to 11014981
  writeRegister(0x16, 0xC0); // FIFO CTRL - 11014987 to 11015130
  writeRegister(0x40, 0x04); // TX Buffer - 11015136 to 11015269
  writeRegister(0x41, 0x0E); // TX Buffer - 11015283 to 11015419
  writeRegister(0x44, 0x23); // TX Buffer - 11015431 to 11015567
  writeRegister(0x45, 0x11); // TX Buffer - 11015580 to 11015714
  writeRegister(0x46, 0x13); // TX Buffer - 11015728 to 11015863
  writeRegister(0x04, 0x07); // TX - 11015877 to 11016011
  writeRegister(0x00, 0xFF); // CS0 - 11022739 to 11022879
  writeRegister(0x01, 0xFF); // CS1 - 11022893 to 11023037
  writeRegister(0x16, 0xC0); // FIFO CTRL - 11023043 to 11023181
  writeRegister(0x40, 0x04); // TX Buffer - 11023192 to 11023325
  writeRegister(0x41, 0x0E); // TX Buffer - 11023339 to 11023473
  writeRegister(0x44, 0x23); // TX Buffer - 11023487 to 11023623
  writeRegister(0x45, 0x11); // TX Buffer - 11023636 to 11023770
  writeRegister(0x46, 0x13); // TX Buffer - 11023784 to 11023919
  writeRegister(0x04, 0x07); // TX - 11023933 to 11024067
  writeRegister(0x00, 0xFF); // CS0 - 11030714 to 11030858
  writeRegister(0x01, 0xFF); // CS1 - 11030864 to 11031005
  writeRegister(0x16, 0xC0); // FIFO CTRL - 11031018 to 11031152
  writeRegister(0x40, 0x04); // TX Buffer - 11031166 to 11031299
  writeRegister(0x41, 0x0E); // TX Buffer - 11031310 to 11031448
  writeRegister(0x44, 0x23); // TX Buffer - 11031458 to 11031596
  writeRegister(0x45, 0x11); // TX Buffer - 11031607 to 11031746
  writeRegister(0x46, 0x13); // TX Buffer - 11031755 to 11031895
  writeRegister(0x04, 0x07); // TX - 11031904 to 11032043
  writeRegister(0x00, 0xFF); // CS0 - 11038685 to 11038826
  writeRegister(0x01, 0xFF); // CS1 - 11038838 to 11038976
  writeRegister(0x16, 0xC0); // FIFO CTRL - 11038989 to 11039123
  writeRegister(0x40, 0x04); // TX Buffer - 11039137 to 11039270
  writeRegister(0x41, 0x0E); // TX Buffer - 11039284 to 11039419
  writeRegister(0x44, 0x23); // TX Buffer - 11039433 to 11039567
  writeRegister(0x45, 0x11); // TX Buffer - 11039581 to 11039717
  writeRegister(0x46, 0x13); // TX Buffer - 11039729 to 11039866
  writeRegister(0x04, 0x07); // TX - 11039878 to 11040014
  writeRegister(0x00, 0xFF); // CS0 - 11046741 to 11046880
  writeRegister(0x01, 0xFF); // CS1 - 11046894 to 11047038
  writeRegister(0x16, 0xC0); // FIFO CTRL - 11047045 to 11047187
  writeRegister(0x40, 0x04); // TX Buffer - 11047193 to 11047326
  writeRegister(0x41, 0x0E); // TX Buffer - 11047340 to 11047475
  writeRegister(0x44, 0x23); // TX Buffer - 11047488 to 11047623
  writeRegister(0x45, 0x11); // TX Buffer - 11047637 to 11047773
  writeRegister(0x46, 0x13); // TX Buffer - 11047785 to 11047920
  writeRegister(0x04, 0x07); // TX - 11047934 to 11048068
  writeRegister(0x00, 0xFF); // CS0 - 11054715 to 11054851
  writeRegister(0x01, 0xFF); // CS1 - 11054865 to 11055005
  writeRegister(0x16, 0xC0); // FIFO CTRL - 11055019 to 11055154
  writeRegister(0x40, 0x04); // TX Buffer - 11055167 to 11055301
  writeRegister(0x41, 0x0E); // TX Buffer - 11055311 to 11055449
  writeRegister(0x44, 0x23); // TX Buffer - 11055459 to 11055602
  writeRegister(0x45, 0x11); // TX Buffer - 11055608 to 11055750
  writeRegister(0x46, 0x13); // TX Buffer - 11055756 to 11055896
  writeRegister(0x04, 0x07); // TX - 11055905 to 11056047
  writeRegister(0x00, 0xFF); // CS0 - 11062686 to 11062827
  writeRegister(0x01, 0xFF); // CS1 - 11062836 to 11062976
  writeRegister(0x16, 0xC0); // FIFO CTRL - 11062990 to 11063125
  writeRegister(0x40, 0x04); // TX Buffer - 11063138 to 11063272
  writeRegister(0x41, 0x0E); // TX Buffer - 11063285 to 11063420
  writeRegister(0x44, 0x23); // TX Buffer - 11063434 to 11063570
  writeRegister(0x45, 0x11); // TX Buffer - 11063582 to 11063717
  writeRegister(0x46, 0x13); // TX Buffer - 11063731 to 11063867
  writeRegister(0x04, 0x07); // TX - 11063880 to 11064015
  writeRegister(0x00, 0xFF); // CS0 - 11070742 to 11070883
  writeRegister(0x01, 0xFF); // CS1 - 11070895 to 11071032
  writeRegister(0x16, 0xC0); // FIFO CTRL - 11071046 to 11071182
  writeRegister(0x40, 0x04); // TX Buffer - 11071194 to 11071329
  writeRegister(0x41, 0x0E); // TX Buffer - 11071341 to 11071476
  writeRegister(0x44, 0x23); // TX Buffer - 11071490 to 11071624
  writeRegister(0x45, 0x11); // TX Buffer - 11071638 to 11071774
  writeRegister(0x46, 0x13); // TX Buffer - 11071787 to 11071923
  writeRegister(0x04, 0x07); // TX - 11071936 to 11072071
  writeRegister(0x00, 0xFF); // CS0 - 11078717 to 11078854
  writeRegister(0x01, 0xFF); // CS1 - 11078866 to 11079008
  writeRegister(0x16, 0xC0); // FIFO CTRL - 11079017 to 11079155
  writeRegister(0x40, 0x04); // TX Buffer - 11079165 to 11079299
  writeRegister(0x41, 0x0E); // TX Buffer - 11079312 to 11079447
  writeRegister(0x44, 0x23); // TX Buffer - 11079461 to 11079595
  writeRegister(0x45, 0x11); // TX Buffer - 11079609 to 11079745
  writeRegister(0x46, 0x13); // TX Buffer - 11079758 to 11079900
  writeRegister(0x04, 0x07); // TX - 11079907 to 11080042
  writeRegister(0x00, 0xFF); // CS0 - 11086688 to 11086827
  writeRegister(0x01, 0xFF); // CS1 - 11086838 to 11086979
  writeRegister(0x16, 0xC0); // FIFO CTRL - 11086991 to 11087126
  writeRegister(0x40, 0x04); // TX Buffer - 11087140 to 11087273
  writeRegister(0x41, 0x0E); // TX Buffer - 11087283 to 11087423
  writeRegister(0x44, 0x23); // TX Buffer - 11087432 to 11087571
  writeRegister(0x45, 0x11); // TX Buffer - 11087580 to 11087718
  writeRegister(0x46, 0x13); // TX Buffer - 11087729 to 11087867
  writeRegister(0x04, 0x07); // TX - 11087881 to 11088015
  writeRegister(0x00, 0xFF); // CS0 - 11094743 to 11094884
  writeRegister(0x01, 0xFF); // CS1 - 11094893 to 11095033
  writeRegister(0x16, 0xC0); // FIFO CTRL - 11095047 to 11095182
  writeRegister(0x40, 0x04); // TX Buffer - 11095196 to 11095329
  writeRegister(0x41, 0x0E); // TX Buffer - 11095343 to 11095477
  writeRegister(0x44, 0x23); // TX Buffer - 11095491 to 11095627
  writeRegister(0x45, 0x11); // TX Buffer - 11095639 to 11095774
  writeRegister(0x46, 0x13); // TX Buffer - 11095788 to 11095923
  writeRegister(0x04, 0x07); // TX - 11095937 to 11096071
  writeRegister(0x00, 0xFF); // CS0 - 11102718 to 11102854
  writeRegister(0x01, 0xFF); // CS1 - 11102868 to 11103009
  writeRegister(0x16, 0xC0); // FIFO CTRL - 11103018 to 11103156
  writeRegister(0x40, 0x04); // TX Buffer - 11103167 to 11103300
  writeRegister(0x41, 0x0E); // TX Buffer - 11103314 to 11103448
  writeRegister(0x44, 0x23); // TX Buffer - 11103462 to 11103598
  writeRegister(0x45, 0x11); // TX Buffer - 11103611 to 11103745
  writeRegister(0x46, 0x13); // TX Buffer - 11103759 to 11103894
  writeRegister(0x04, 0x07); // TX - 11103908 to 11104042
  writeRegister(0x00, 0xFF); // CS0 - 11110689 to 11110833
  writeRegister(0x01, 0xFF); // CS1 - 11110839 to 11110980
  writeRegister(0x16, 0xC0); // FIFO CTRL - 11110993 to 11111127
  writeRegister(0x40, 0x04); // TX Buffer - 11111141 to 11111274
  writeRegister(0x41, 0x0E); // TX Buffer - 11111285 to 11111423
  writeRegister(0x44, 0x23); // TX Buffer - 11111433 to 11111571
  writeRegister(0x45, 0x11); // TX Buffer - 11111582 to 11111721
  writeRegister(0x46, 0x13); // TX Buffer - 11111730 to 11111870
  writeRegister(0x04, 0x07); // TX - 11111879 to 11112018
  writeRegister(0x00, 0xFF); // CS0 - 11118745 to 11118884
  writeRegister(0x01, 0xFF); // CS1 - 11118895 to 11119036
  writeRegister(0x16, 0xC0); // FIFO CTRL - 11119048 to 11119183
  writeRegister(0x40, 0x04); // TX Buffer - 11119197 to 11119330
  writeRegister(0x41, 0x0E); // TX Buffer - 11119340 to 11119479
  writeRegister(0x44, 0x23); // TX Buffer - 11119489 to 11119627
  writeRegister(0x45, 0x11); // TX Buffer - 11119637 to 11119777
  writeRegister(0x46, 0x13); // TX Buffer - 11119786 to 11119924
  writeRegister(0x04, 0x07); // TX - 11119938 to 11120072
  writeRegister(0x00, 0xFF); // CS0 - 11126716 to 11126855
  writeRegister(0x01, 0xFF); // CS1 - 11126869 to 11127013
  writeRegister(0x16, 0xC0); // FIFO CTRL - 11127020 to 11127158
  writeRegister(0x40, 0x04); // TX Buffer - 11127168 to 11127301
  writeRegister(0x41, 0x0E); // TX Buffer - 11127315 to 11127450
  writeRegister(0x44, 0x23); // TX Buffer - 11127463 to 11127598
  writeRegister(0x45, 0x11); // TX Buffer - 11127612 to 11127748
  writeRegister(0x46, 0x13); // TX Buffer - 11127760 to 11127897
  writeRegister(0x04, 0x07); // TX - 11127909 to 11128043
  writeRegister(0x00, 0xFF); // CS0 - 11134690 to 11134834
  writeRegister(0x01, 0xFF); // CS1 - 11134840 to 11134980
  writeRegister(0x16, 0xC0); // FIFO CTRL - 11134994 to 11135129
  writeRegister(0x40, 0x04); // TX Buffer - 11135142 to 11135276
  writeRegister(0x41, 0x0E); // TX Buffer - 11135286 to 11135424
  writeRegister(0x44, 0x23); // TX Buffer - 11135434 to 11135577
  writeRegister(0x45, 0x11); // TX Buffer - 11135583 to 11135725
  writeRegister(0x46, 0x13); // TX Buffer - 11135731 to 11135871
  writeRegister(0x04, 0x07); // TX - 11135880 to 11136022
  writeRegister(0x00, 0xFF); // CS0 - 11142746 to 11142890
  writeRegister(0x01, 0xFF); // CS1 - 11142896 to 11143036
  writeRegister(0x16, 0xC0); // FIFO CTRL - 11143050 to 11143186
  writeRegister(0x40, 0x04); // TX Buffer - 11143198 to 11143331
  writeRegister(0x41, 0x0E); // TX Buffer - 11143342 to 11143480
  writeRegister(0x44, 0x23); // TX Buffer - 11143490 to 11143628
  writeRegister(0x45, 0x11); // TX Buffer - 11143639 to 11143778
  writeRegister(0x46, 0x13); // TX Buffer - 11143787 to 11143927
  writeRegister(0x04, 0x07); // TX - 11143936 to 11144075
  writeRegister(0x00, 0xFF); // CS0 - 11150717 to 11150858
  writeRegister(0x01, 0xFF); // CS1 - 11150870 to 11151007
  writeRegister(0x16, 0xC0); // FIFO CTRL - 11151021 to 11151156
  writeRegister(0x40, 0x04); // TX Buffer - 11151169 to 11151303
  writeRegister(0x41, 0x0E); // TX Buffer - 11151316 to 11151451
  writeRegister(0x44, 0x23); // TX Buffer - 11151465 to 11151599
  writeRegister(0x45, 0x11); // TX Buffer - 11151613 to 11151749
  writeRegister(0x46, 0x13); // TX Buffer - 11151762 to 11151898
  writeRegister(0x04, 0x07); // TX - 11151911 to 11152046
  writeRegister(0x00, 0xFF); // CS0 - 11158692 to 11158829
  writeRegister(0x01, 0xFF); // CS1 - 11158842 to 11158983
  writeRegister(0x16, 0xC0); // FIFO CTRL - 11158992 to 11159130
  writeRegister(0x40, 0x04); // TX Buffer - 11159140 to 11159280
  writeRegister(0x41, 0x0E); // TX Buffer - 11159287 to 11159428
  writeRegister(0x44, 0x23); // TX Buffer - 11159436 to 11159578
  writeRegister(0x45, 0x11); // TX Buffer - 11159584 to 11159726
  writeRegister(0x46, 0x13); // TX Buffer - 11159733 to 11159875
  writeRegister(0x04, 0x07); // TX - 11159882 to 11160023
  writeRegister(0x00, 0xFF); // CS0 - 11166747 to 11166891
  writeRegister(0x01, 0xFF); // CS1 - 11166897 to 11167037
  writeRegister(0x16, 0xC0); // FIFO CTRL - 11167051 to 11167186
  writeRegister(0x40, 0x04); // TX Buffer - 11167200 to 11167333
  writeRegister(0x41, 0x0E); // TX Buffer - 11167343 to 11167481
  writeRegister(0x44, 0x23); // TX Buffer - 11167492 to 11167634
  writeRegister(0x45, 0x11); // TX Buffer - 11167640 to 11167782
  writeRegister(0x46, 0x13); // TX Buffer - 11167788 to 11167927
  writeRegister(0x04, 0x07); // TX - 11167937 to 11168079
  writeRegister(0x00, 0xFF); // CS0 - 11174718 to 11174858
  writeRegister(0x01, 0xFF); // CS1 - 11174872 to 11175008
  writeRegister(0x16, 0xC0); // FIFO CTRL - 11175022 to 11175157
  writeRegister(0x40, 0x04); // TX Buffer - 11175171 to 11175304
  writeRegister(0x41, 0x0E); // TX Buffer - 11175318 to 11175452
  writeRegister(0x44, 0x23); // TX Buffer - 11175466 to 11175602
  writeRegister(0x45, 0x11); // TX Buffer - 11175615 to 11175749
  writeRegister(0x46, 0x13); // TX Buffer - 11175763 to 11175898
  writeRegister(0x04, 0x07); // TX - 11175912 to 11176046
  writeRegister(0x00, 0xFF); // CS0 - 11182693 to 11182829
  writeRegister(0x01, 0xFF); // CS1 - 11182843 to 11182984
  writeRegister(0x16, 0xC0); // FIFO CTRL - 11182993 to 11183131
  writeRegister(0x40, 0x04); // TX Buffer - 11183142 to 11183275
  writeRegister(0x41, 0x0E); // TX Buffer - 11183289 to 11183423
  writeRegister(0x44, 0x23); // TX Buffer - 11183437 to 11183573
  writeRegister(0x45, 0x11); // TX Buffer - 11183586 to 11183720
  writeRegister(0x46, 0x13); // TX Buffer - 11183734 to 11183877
  writeRegister(0x04, 0x07); // TX - 11183883 to 11184017
  writeRegister(0x00, 0xFF); // CS0 - 11190749 to 11190886
  writeRegister(0x01, 0xFF); // CS1 - 11190899 to 11191040
  writeRegister(0x16, 0xC0); // FIFO CTRL - 11191049 to 11191187
  writeRegister(0x40, 0x04); // TX Buffer - 11191197 to 11191337
  writeRegister(0x41, 0x0E); // TX Buffer - 11191344 to 11191487
  writeRegister(0x44, 0x23); // TX Buffer - 11191493 to 11191635
  writeRegister(0x45, 0x11); // TX Buffer - 11191641 to 11191782
  writeRegister(0x46, 0x13); // TX Buffer - 11191790 to 11191932
  writeRegister(0x04, 0x07); // TX - 11191939 to 11192080
  writeRegister(0x00, 0xFF); // CS0 - 11198720 to 11198859
  writeRegister(0x01, 0xFF); // CS1 - 11198870 to 11199011
  writeRegister(0x16, 0xC0); // FIFO CTRL - 11199024 to 11199158
  writeRegister(0x40, 0x04); // TX Buffer - 11199172 to 11199305
  writeRegister(0x41, 0x0E); // TX Buffer - 11199319 to 11199454
  writeRegister(0x44, 0x23); // TX Buffer - 11199467 to 11199602
  writeRegister(0x45, 0x11); // TX Buffer - 11199616 to 11199752
  writeRegister(0x46, 0x13); // TX Buffer - 11199764 to 11199899
  writeRegister(0x04, 0x07); // TX - 11199913 to 11200047
  writeRegister(0x00, 0xFF); // CS0 - 11206691 to 11206830
  writeRegister(0x01, 0xFF); // CS1 - 11206844 to 11206988
  writeRegister(0x16, 0xC0); // FIFO CTRL - 11206995 to 11207133
  writeRegister(0x40, 0x04); // TX Buffer - 11207143 to 11207276
  writeRegister(0x41, 0x0E); // TX Buffer - 11207290 to 11207425
  writeRegister(0x44, 0x23); // TX Buffer - 11207438 to 11207573
  writeRegister(0x45, 0x11); // TX Buffer - 11207587 to 11207723
  writeRegister(0x46, 0x13); // TX Buffer - 11207735 to 11207872
  writeRegister(0x04, 0x07); // TX - 11207884 to 11208020
  writeRegister(0x00, 0xFF); // CS0 - 11214750 to 11214886
  writeRegister(0x01, 0xFF); // CS1 - 11214900 to 11215041
  writeRegister(0x16, 0xC0); // FIFO CTRL - 11215050 to 11215188
  writeRegister(0x40, 0x04); // TX Buffer - 11215199 to 11215332
  writeRegister(0x41, 0x0E); // TX Buffer - 11215346 to 11215482
  writeRegister(0x44, 0x23); // TX Buffer - 11215494 to 11215630
  writeRegister(0x45, 0x11); // TX Buffer - 11215643 to 11215777
  writeRegister(0x46, 0x13); // TX Buffer - 11215791 to 11215934
  writeRegister(0x04, 0x07); // TX - 11215940 to 11216074
  writeRegister(0x00, 0xFF); // CS0 - 11222721 to 11222862
  writeRegister(0x01, 0xFF); // CS1 - 11222871 to 11223011
  writeRegister(0x16, 0xC0); // FIFO CTRL - 11223025 to 11223161
  writeRegister(0x40, 0x04); // TX Buffer - 11223173 to 11223308
  writeRegister(0x41, 0x0E); // TX Buffer - 11223317 to 11223455
  writeRegister(0x44, 0x23); // TX Buffer - 11223465 to 11223603
  writeRegister(0x45, 0x11); // TX Buffer - 11223614 to 11223753
  writeRegister(0x46, 0x13); // TX Buffer - 11223762 to 11223902
  writeRegister(0x04, 0x07); // TX - 11223915 to 11224050
  writeRegister(0x00, 0xFF); // CS0 - 11230692 to 11230833
  writeRegister(0x01, 0xFF); // CS1 - 11230845 to 11230990
  writeRegister(0x16, 0xC0); // FIFO CTRL - 11230996 to 11231137
  writeRegister(0x40, 0x04); // TX Buffer - 11231144 to 11231278
  writeRegister(0x41, 0x0E); // TX Buffer - 11231291 to 11231426
  writeRegister(0x44, 0x23); // TX Buffer - 11231440 to 11231574
  writeRegister(0x45, 0x11); // TX Buffer - 11231588 to 11231724
  writeRegister(0x46, 0x13); // TX Buffer - 11231737 to 11231873
  writeRegister(0x04, 0x07); // TX - 11231886 to 11232021
  writeRegister(0x00, 0xFF); // CS0 - 11238748 to 11238889
  writeRegister(0x01, 0xFF); // CS1 - 11238901 to 11239045
  writeRegister(0x16, 0xC0); // FIFO CTRL - 11239052 to 11239190
  writeRegister(0x40, 0x04); // TX Buffer - 11239200 to 11239333
  writeRegister(0x41, 0x0E); // TX Buffer - 11239347 to 11239482
  writeRegister(0x44, 0x23); // TX Buffer - 11239496 to 11239630
  writeRegister(0x45, 0x11); // TX Buffer - 11239644 to 11239780
  writeRegister(0x46, 0x13); // TX Buffer - 11239792 to 11239929
  writeRegister(0x04, 0x07); // TX - 11239941 to 11240077
  writeRegister(0x00, 0xFF); // CS0 - 11246722 to 11246866
  writeRegister(0x01, 0xFF); // CS1 - 11246872 to 11247012
  writeRegister(0x16, 0xC0); // FIFO CTRL - 11247026 to 11247161
  writeRegister(0x40, 0x04); // TX Buffer - 11247175 to 11247308
  writeRegister(0x41, 0x0E); // TX Buffer - 11247318 to 11247456
  writeRegister(0x44, 0x23); // TX Buffer - 11247467 to 11247606
  writeRegister(0x45, 0x11); // TX Buffer - 11247615 to 11247753
  writeRegister(0x46, 0x13); // TX Buffer - 11247764 to 11247902
  writeRegister(0x04, 0x07); // TX - 11247912 to 11248050
  writeRegister(0x00, 0xFF); // CS0 - 11254693 to 11254833
  writeRegister(0x01, 0xFF); // CS1 - 11254847 to 11254983
  writeRegister(0x16, 0xC0); // FIFO CTRL - 11254997 to 11255132
  writeRegister(0x40, 0x04); // TX Buffer - 11255146 to 11255279
  writeRegister(0x41, 0x0E); // TX Buffer - 11255293 to 11255427
  writeRegister(0x44, 0x23); // TX Buffer - 11255441 to 11255577
  writeRegister(0x45, 0x11); // TX Buffer - 11255590 to 11255724
  writeRegister(0x46, 0x13); // TX Buffer - 11255738 to 11255873
  writeRegister(0x04, 0x07); // TX - 11255887 to 11256021
  writeRegister(0x00, 0xFF); // CS0 - 11262749 to 11262890
  writeRegister(0x01, 0xFF); // CS1 - 11262903 to 11263047
  writeRegister(0x16, 0xC0); // FIFO CTRL - 11263053 to 11263194
  writeRegister(0x40, 0x04); // TX Buffer - 11263201 to 11263335
  writeRegister(0x41, 0x0E); // TX Buffer - 11263348 to 11263483
  writeRegister(0x44, 0x23); // TX Buffer - 11263497 to 11263633
  writeRegister(0x45, 0x11); // TX Buffer - 11263645 to 11263780
  writeRegister(0x46, 0x13); // TX Buffer - 11263794 to 11263930
  writeRegister(0x04, 0x07); // TX - 11263943 to 11264078
  writeRegister(0x00, 0xFF); // CS0 - 11270724 to 11270861
  writeRegister(0x01, 0xFF); // CS1 - 11270874 to 11271015
  writeRegister(0x16, 0xC0); // FIFO CTRL - 11271027 to 11271162
  writeRegister(0x40, 0x04); // TX Buffer - 11271176 to 11271309
  writeRegister(0x41, 0x0E); // TX Buffer - 11271319 to 11271458
  writeRegister(0x44, 0x23); // TX Buffer - 11271468 to 11271610
  writeRegister(0x45, 0x11); // TX Buffer - 11271616 to 11271759
  writeRegister(0x46, 0x13); // TX Buffer - 11271765 to 11271903
  writeRegister(0x04, 0x07); // TX - 11271914 to 11272055
  writeRegister(0x00, 0xFF); // CS0 - 11278780 to 11278923
  writeRegister(0x01, 0xFF); // CS1 - 11278929 to 11279071
  writeRegister(0x16, 0xC0); // FIFO CTRL - 11279083 to 11279218
  writeRegister(0x40, 0x04); // TX Buffer - 11279232 to 11279365
  writeRegister(0x41, 0x0E); // TX Buffer - 11279375 to 11279513
  writeRegister(0x44, 0x23); // TX Buffer - 11279524 to 11279663
  writeRegister(0x45, 0x11); // TX Buffer - 11279672 to 11279810
  writeRegister(0x46, 0x13); // TX Buffer - 11279821 to 11279959
  writeRegister(0x04, 0x07); // TX - 11279970 to 11280107
  writeRegister(0x00, 0xFF); // CS0 - 11286751 to 11286890
  writeRegister(0x01, 0xFF); // CS1 - 11286904 to 11287042
  writeRegister(0x16, 0xC0); // FIFO CTRL - 11287054 to 11287189
  writeRegister(0x40, 0x04); // TX Buffer - 11287203 to 11287336
  writeRegister(0x41, 0x0E); // TX Buffer - 11287350 to 11287484
  writeRegister(0x44, 0x23); // TX Buffer - 11287498 to 11287634
  writeRegister(0x45, 0x11); // TX Buffer - 11287647 to 11287781
  writeRegister(0x46, 0x13); // TX Buffer - 11287795 to 11287930
  writeRegister(0x04, 0x07); // TX - 11287944 to 11288078
  writeRegister(0x00, 0xFF); // CS0 - 11294725 to 11294861
  writeRegister(0x01, 0xFF); // CS1 - 11294875 to 11295015
  writeRegister(0x16, 0xC0); // FIFO CTRL - 11295025 to 11295165
  writeRegister(0x40, 0x04); // TX Buffer - 11295174 to 11295307
  writeRegister(0x41, 0x0E); // TX Buffer - 11295321 to 11295457
  writeRegister(0x44, 0x23); // TX Buffer - 11295469 to 11295605
  writeRegister(0x45, 0x11); // TX Buffer - 11295618 to 11295752
  writeRegister(0x46, 0x13); // TX Buffer - 11295766 to 11295909
  writeRegister(0x04, 0x07); // TX - 11295915 to 11296049
  writeRegister(0x00, 0xFF); // CS0 - 11302781 to 11302918
  writeRegister(0x01, 0xFF); // CS1 - 11302931 to 11303072
  writeRegister(0x16, 0xC0); // FIFO CTRL - 11303085 to 11303219
  writeRegister(0x40, 0x04); // TX Buffer - 11303233 to 11303366
  writeRegister(0x41, 0x0E); // TX Buffer - 11303377 to 11303515
  writeRegister(0x44, 0x23); // TX Buffer - 11303525 to 11303667
  writeRegister(0x45, 0x11); // TX Buffer - 11303673 to 11303816
  writeRegister(0x46, 0x13); // TX Buffer - 11303822 to 11303962
  writeRegister(0x04, 0x07); // TX - 11303971 to 11304113
  writeRegister(0x00, 0xFF); // CS0 - 11310752 to 11310893
  writeRegister(0x01, 0xFF); // CS1 - 11310902 to 11311043
  writeRegister(0x16, 0xC0); // FIFO CTRL - 11311056 to 11311190
  writeRegister(0x40, 0x04); // TX Buffer - 11311204 to 11311337
  writeRegister(0x41, 0x0E); // TX Buffer - 11311351 to 11311486
  writeRegister(0x44, 0x23); // TX Buffer - 11311500 to 11311634
  writeRegister(0x45, 0x11); // TX Buffer - 11311648 to 11311784
  writeRegister(0x46, 0x13); // TX Buffer - 11311796 to 11311933
  writeRegister(0x04, 0x07); // TX - 11311945 to 11312081
  writeRegister(0x00, 0xFF); // CS0 - 11318726 to 11318864
  writeRegister(0x01, 0xFF); // CS1 - 11318876 to 11319016
  writeRegister(0x16, 0xC0); // FIFO CTRL - 11319027 to 11319165
  writeRegister(0x40, 0x04); // TX Buffer - 11319175 to 11319308
  writeRegister(0x41, 0x0E); // TX Buffer - 11319322 to 11319457
  writeRegister(0x44, 0x23); // TX Buffer - 11319471 to 11319605
  writeRegister(0x45, 0x11); // TX Buffer - 11319619 to 11319755
  writeRegister(0x46, 0x13); // TX Buffer - 11319767 to 11319904
  writeRegister(0x04, 0x07); // TX - 11319916 to 11320052
  writeRegister(0x00, 0xFF); // CS0 - 11326782 to 11326918
  writeRegister(0x01, 0xFF); // CS1 - 11326932 to 11327072
  writeRegister(0x16, 0xC0); // FIFO CTRL - 11327082 to 11327221
  writeRegister(0x40, 0x04); // TX Buffer - 11327231 to 11327364
  writeRegister(0x41, 0x0E); // TX Buffer - 11327378 to 11327513
  writeRegister(0x44, 0x23); // TX Buffer - 11327526 to 11327661
  writeRegister(0x45, 0x11); // TX Buffer - 11327675 to 11327811
  writeRegister(0x46, 0x13); // TX Buffer - 11327823 to 11327966
  writeRegister(0x04, 0x07); // TX - 11327972 to 11328106
  writeRegister(0x00, 0xFF); // CS0 - 11334753 to 11334894
  writeRegister(0x01, 0xFF); // CS1 - 11334903 to 11335043
  writeRegister(0x16, 0xC0); // FIFO CTRL - 11335057 to 11335192
  writeRegister(0x40, 0x04); // TX Buffer - 11335205 to 11335339
  writeRegister(0x41, 0x0E); // TX Buffer - 11335349 to 11335487
  writeRegister(0x44, 0x23); // TX Buffer - 11335497 to 11335637
  writeRegister(0x45, 0x11); // TX Buffer - 11335646 to 11335785
  writeRegister(0x46, 0x13); // TX Buffer - 11335794 to 11335934
  writeRegister(0x04, 0x07); // TX - 11335947 to 11336082
  writeRegister(0x00, 0xFF); // CS0 - 11342724 to 11342865
  writeRegister(0x01, 0xFF); // CS1 - 11342878 to 11343022
  writeRegister(0x16, 0xC0); // FIFO CTRL - 11343028 to 11343166
  writeRegister(0x40, 0x04); // TX Buffer - 11343176 to 11343310
  writeRegister(0x41, 0x0E); // TX Buffer - 11343323 to 11343458
  writeRegister(0x44, 0x23); // TX Buffer - 11343472 to 11343608
  writeRegister(0x45, 0x11); // TX Buffer - 11343620 to 11343755
  writeRegister(0x46, 0x13); // TX Buffer - 11343769 to 11343905
  writeRegister(0x04, 0x07); // TX - 11343918 to 11344053
  writeRegister(0x00, 0xFF); // CS0 - 11350783 to 11350921
  writeRegister(0x01, 0xFF); // CS1 - 11350933 to 11351075
  writeRegister(0x16, 0xC0); // FIFO CTRL - 11351084 to 11351222
  writeRegister(0x40, 0x04); // TX Buffer - 11351232 to 11351367
  writeRegister(0x41, 0x0E); // TX Buffer - 11351379 to 11351514
  writeRegister(0x44, 0x23); // TX Buffer - 11351528 to 11351662
  writeRegister(0x45, 0x11); // TX Buffer - 11351676 to 11351812
  writeRegister(0x46, 0x13); // TX Buffer - 11351825 to 11351961
  writeRegister(0x04, 0x07); // TX - 11351974 to 11352109
  writeRegister(0x00, 0xFF); // CS0 - 11358755 to 11358898
  writeRegister(0x01, 0xFF); // CS1 - 11358904 to 11359046
  writeRegister(0x16, 0xC0); // FIFO CTRL - 11359058 to 11359193
  writeRegister(0x40, 0x04); // TX Buffer - 11359207 to 11359340
  writeRegister(0x41, 0x0E); // TX Buffer - 11359350 to 11359488
  writeRegister(0x44, 0x23); // TX Buffer - 11359499 to 11359638
  writeRegister(0x45, 0x11); // TX Buffer - 11359647 to 11359785
  writeRegister(0x46, 0x13); // TX Buffer - 11359796 to 11359934
  writeRegister(0x04, 0x07); // TX - 11359945 to 11360082
  writeRegister(0x00, 0xFF); // CS0 - 11366726 to 11366865
  writeRegister(0x01, 0xFF); // CS1 - 11366879 to 11367017
  writeRegister(0x16, 0xC0); // FIFO CTRL - 11367029 to 11367164
  writeRegister(0x40, 0x04); // TX Buffer - 11367178 to 11367311
  writeRegister(0x41, 0x0E); // TX Buffer - 11367325 to 11367461
  writeRegister(0x44, 0x23); // TX Buffer - 11367473 to 11367609
  writeRegister(0x45, 0x11); // TX Buffer - 11367622 to 11367756
  writeRegister(0x46, 0x13); // TX Buffer - 11367770 to 11367905
  writeRegister(0x04, 0x07); // TX - 11367919 to 11368053
  writeRegister(0x00, 0xFF); // CS0 - 11374781 to 11374922
  writeRegister(0x01, 0xFF); // CS1 - 11374935 to 11375079
  writeRegister(0x16, 0xC0); // FIFO CTRL - 11375085 to 11375223
  writeRegister(0x40, 0x04); // TX Buffer - 11375234 to 11375367
  writeRegister(0x41, 0x0E); // TX Buffer - 11375381 to 11375515
  writeRegister(0x44, 0x23); // TX Buffer - 11375529 to 11375665
  writeRegister(0x45, 0x11); // TX Buffer - 11375677 to 11375812
  writeRegister(0x46, 0x13); // TX Buffer - 11375826 to 11375961
  writeRegister(0x04, 0x07); // TX - 11375975 to 11376109
  writeRegister(0x00, 0xFF); // CS0 - 11382756 to 11382898
  writeRegister(0x01, 0xFF); // CS1 - 11382906 to 11383047
  writeRegister(0x16, 0xC0); // FIFO CTRL - 11383060 to 11383194
  writeRegister(0x40, 0x04); // TX Buffer - 11383208 to 11383341
  writeRegister(0x41, 0x0E); // TX Buffer - 11383352 to 11383490
  writeRegister(0x44, 0x23); // TX Buffer - 11383500 to 11383642
  writeRegister(0x45, 0x11); // TX Buffer - 11383649 to 11383791
  writeRegister(0x46, 0x13); // TX Buffer - 11383797 to 11383937
  writeRegister(0x04, 0x07); // TX - 11383946 to 11384088
  writeRegister(0x00, 0xFF); // CS0 - 11390727 to 11390868
  writeRegister(0x01, 0xFF); // CS1 - 11390880 to 11391018
  writeRegister(0x16, 0xC0); // FIFO CTRL - 11391031 to 11391165
  writeRegister(0x40, 0x04); // TX Buffer - 11391179 to 11391312
  writeRegister(0x41, 0x0E); // TX Buffer - 11391326 to 11391461
  writeRegister(0x44, 0x23); // TX Buffer - 11391475 to 11391609
  writeRegister(0x45, 0x11); // TX Buffer - 11391623 to 11391759
  writeRegister(0x46, 0x13); // TX Buffer - 11391771 to 11391908
  writeRegister(0x04, 0x07); // TX - 11391920 to 11392056
  writeRegister(0x00, 0xFF); // CS0 - 11398783 to 11398922
  writeRegister(0x01, 0xFF); // CS1 - 11398936 to 11399074
  writeRegister(0x16, 0xC0); // FIFO CTRL - 11399086 to 11399221
  writeRegister(0x40, 0x04); // TX Buffer - 11399235 to 11399368
  writeRegister(0x41, 0x0E); // TX Buffer - 11399382 to 11399517
  writeRegister(0x44, 0x23); // TX Buffer - 11399530 to 11399665
  writeRegister(0x45, 0x11); // TX Buffer - 11399679 to 11399815
  writeRegister(0x46, 0x13); // TX Buffer - 11399827 to 11399962
  writeRegister(0x04, 0x07); // TX - 11399976 to 11400110
  writeRegister(0x00, 0xFF); // CS0 - 11406757 to 11406893
  writeRegister(0x01, 0xFF); // CS1 - 11406907 to 11407047
  writeRegister(0x16, 0xC0); // FIFO CTRL - 11407058 to 11407196
  writeRegister(0x40, 0x04); // TX Buffer - 11407206 to 11407347
  writeRegister(0x41, 0x0E); // TX Buffer - 11407353 to 11407494
  writeRegister(0x44, 0x23); // TX Buffer - 11407501 to 11407644
  writeRegister(0x45, 0x11); // TX Buffer - 11407650 to 11407792
  writeRegister(0x46, 0x13); // TX Buffer - 11407798 to 11407941
  writeRegister(0x04, 0x07); // TX - 11407947 to 11408089
  writeRegister(0x00, 0xFF); // CS0 - 11414728 to 11414869
  writeRegister(0x01, 0xFF); // CS1 - 11414878 to 11415018
  writeRegister(0x16, 0xC0); // FIFO CTRL - 11415032 to 11415167
  writeRegister(0x40, 0x04); // TX Buffer - 11415180 to 11415314
  writeRegister(0x41, 0x0E); // TX Buffer - 11415327 to 11415462
  writeRegister(0x44, 0x23); // TX Buffer - 11415476 to 11415612
  writeRegister(0x45, 0x11); // TX Buffer - 11415624 to 11415759
  writeRegister(0x46, 0x13); // TX Buffer - 11415773 to 11415909
  writeRegister(0x04, 0x07); // TX - 11415922 to 11416057
  writeRegister(0x00, 0xFF); // CS0 - 11422784 to 11422925
  writeRegister(0x01, 0xFF); // CS1 - 11422937 to 11423074
  writeRegister(0x16, 0xC0); // FIFO CTRL - 11423088 to 11423224
  writeRegister(0x40, 0x04); // TX Buffer - 11423236 to 11423369
  writeRegister(0x41, 0x0E); // TX Buffer - 11423383 to 11423518
  writeRegister(0x44, 0x23); // TX Buffer - 11423532 to 11423666
  writeRegister(0x45, 0x11); // TX Buffer - 11423680 to 11423816
  writeRegister(0x46, 0x13); // TX Buffer - 11423829 to 11423965
  writeRegister(0x04, 0x07); // TX - 11423977 to 11424113
  writeRegister(0x00, 0xFF); // CS0 - 11430759 to 11430896
  writeRegister(0x01, 0xFF); // CS1 - 11430908 to 11431050
  writeRegister(0x16, 0xC0); // FIFO CTRL - 11431059 to 11431197
  writeRegister(0x40, 0x04); // TX Buffer - 11431207 to 11431342
  writeRegister(0x41, 0x0E); // TX Buffer - 11431354 to 11431489
  writeRegister(0x44, 0x23); // TX Buffer - 11431503 to 11431637
  writeRegister(0x45, 0x11); // TX Buffer - 11431651 to 11431787
  writeRegister(0x46, 0x13); // TX Buffer - 11431800 to 11431942
  writeRegister(0x04, 0x07); // TX - 11431949 to 11432084
  writeRegister(0x00, 0xFF); // CS0 - 11438730 to 11438869
  writeRegister(0x01, 0xFF); // CS1 - 11438880 to 11439021
  writeRegister(0x16, 0xC0); // FIFO CTRL - 11439033 to 11439168
  writeRegister(0x40, 0x04); // TX Buffer - 11439182 to 11439315
  writeRegister(0x41, 0x0E); // TX Buffer - 11439325 to 11439463
  writeRegister(0x44, 0x23); // TX Buffer - 11439474 to 11439613
  writeRegister(0x45, 0x11); // TX Buffer - 11439622 to 11439760
  writeRegister(0x46, 0x13); // TX Buffer - 11439771 to 11439909
  writeRegister(0x04, 0x07); // TX - 11439923 to 11440057
  writeRegister(0x00, 0xFF); // CS0 - 11446785 to 11446926
  writeRegister(0x01, 0xFF); // CS1 - 11446935 to 11447075
  writeRegister(0x16, 0xC0); // FIFO CTRL - 11447089 to 11447224
  writeRegister(0x40, 0x04); // TX Buffer - 11447238 to 11447371
  writeRegister(0x41, 0x0E); // TX Buffer - 11447385 to 11447519
  writeRegister(0x44, 0x23); // TX Buffer - 11447533 to 11447669
  writeRegister(0x45, 0x11); // TX Buffer - 11447681 to 11447816
  writeRegister(0x46, 0x13); // TX Buffer - 11447830 to 11447965
  writeRegister(0x04, 0x07); // TX - 11447979 to 11448113
  writeRegister(0x00, 0xFF); // CS0 - 11454756 to 11454897
  writeRegister(0x01, 0xFF); // CS1 - 11454910 to 11455054
  writeRegister(0x16, 0xC0); // FIFO CTRL - 11455060 to 11455198
  writeRegister(0x40, 0x04); // TX Buffer - 11455209 to 11455342
  writeRegister(0x41, 0x0E); // TX Buffer - 11455356 to 11455490
  writeRegister(0x44, 0x23); // TX Buffer - 11455504 to 11455640
  writeRegister(0x45, 0x11); // TX Buffer - 11455652 to 11455787
  writeRegister(0x46, 0x13); // TX Buffer - 11455801 to 11455936
  writeRegister(0x04, 0x07); // TX - 11455950 to 11456084
  writeRegister(0x00, 0xFF); // CS0 - 11462731 to 11462875
  writeRegister(0x01, 0xFF); // CS1 - 11462881 to 11463022
  writeRegister(0x16, 0xC0); // FIFO CTRL - 11463035 to 11463169
  writeRegister(0x40, 0x04); // TX Buffer - 11463183 to 11463316
  writeRegister(0x41, 0x0E); // TX Buffer - 11463327 to 11463465
  writeRegister(0x44, 0x23); // TX Buffer - 11463475 to 11463613
  writeRegister(0x45, 0x11); // TX Buffer - 11463624 to 11463763
  writeRegister(0x46, 0x13); // TX Buffer - 11463772 to 11463912
  writeRegister(0x04, 0x07); // TX - 11463921 to 11464060
  writeRegister(0x00, 0xFF); // CS0 - 11470787 to 11470926
  writeRegister(0x01, 0xFF); // CS1 - 11470937 to 11471078
  writeRegister(0x16, 0xC0); // FIFO CTRL - 11471090 to 11471225
  writeRegister(0x40, 0x04); // TX Buffer - 11471239 to 11471372
  writeRegister(0x41, 0x0E); // TX Buffer - 11471382 to 11471521
  writeRegister(0x44, 0x23); // TX Buffer - 11471531 to 11471670
  writeRegister(0x45, 0x11); // TX Buffer - 11471679 to 11471817
  writeRegister(0x46, 0x13); // TX Buffer - 11471828 to 11471966
  writeRegister(0x04, 0x07); // TX - 11471980 to 11472114
  writeRegister(0x00, 0xFF); // CS0 - 11478758 to 11478897
  writeRegister(0x01, 0xFF); // CS1 - 11478911 to 11479055
  writeRegister(0x16, 0xC0); // FIFO CTRL - 11479061 to 11479204
  writeRegister(0x40, 0x04); // TX Buffer - 11479210 to 11479343
  writeRegister(0x41, 0x0E); // TX Buffer - 11479357 to 11479492
  writeRegister(0x44, 0x23); // TX Buffer - 11479505 to 11479640
  writeRegister(0x45, 0x11); // TX Buffer - 11479654 to 11479790
  writeRegister(0x46, 0x13); // TX Buffer - 11479802 to 11479937
  writeRegister(0x04, 0x07); // TX - 11479951 to 11480085
  writeRegister(0x00, 0xFF); // CS0 - 11486732 to 11486868
  writeRegister(0x01, 0xFF); // CS1 - 11486882 to 11487022
  writeRegister(0x16, 0xC0); // FIFO CTRL - 11487036 to 11487171
  writeRegister(0x40, 0x04); // TX Buffer - 11487184 to 11487318
  writeRegister(0x41, 0x0E); // TX Buffer - 11487328 to 11487466
  writeRegister(0x44, 0x23); // TX Buffer - 11487476 to 11487619
  writeRegister(0x45, 0x11); // TX Buffer - 11487625 to 11487767
  writeRegister(0x46, 0x13); // TX Buffer - 11487773 to 11487913
  writeRegister(0x04, 0x07); // TX - 11487922 to 11488064
  writeRegister(0x00, 0xFF); // CS0 - 11494788 to 11494932
  writeRegister(0x01, 0xFF); // CS1 - 11494938 to 11495079
  writeRegister(0x16, 0xC0); // FIFO CTRL - 11495092 to 11495226
  writeRegister(0x40, 0x04); // TX Buffer - 11495240 to 11495373
  writeRegister(0x41, 0x0E); // TX Buffer - 11495384 to 11495522
  writeRegister(0x44, 0x23); // TX Buffer - 11495532 to 11495670
  writeRegister(0x45, 0x11); // TX Buffer - 11495681 to 11495820
  writeRegister(0x46, 0x13); // TX Buffer - 11495829 to 11495969
  writeRegister(0x04, 0x07); // TX - 11495978 to 11496117
  writeRegister(0x00, 0xFF); // CS0 - 11502759 to 11502900
  writeRegister(0x01, 0xFF); // CS1 - 11502912 to 11503049
  writeRegister(0x16, 0xC0); // FIFO CTRL - 11503063 to 11503199
  writeRegister(0x40, 0x04); // TX Buffer - 11503211 to 11503346
  writeRegister(0x41, 0x0E); // TX Buffer - 11503358 to 11503493
  writeRegister(0x44, 0x23); // TX Buffer - 11503507 to 11503641
  writeRegister(0x45, 0x11); // TX Buffer - 11503655 to 11503791
  writeRegister(0x46, 0x13); // TX Buffer - 11503804 to 11503940
  writeRegister(0x04, 0x07); // TX - 11503953 to 11504088
  writeRegister(0x00, 0xFF); // CS0 - 11510734 to 11510871
  writeRegister(0x01, 0xFF); // CS1 - 11510883 to 11511025
  writeRegister(0x16, 0xC0); // FIFO CTRL - 11511034 to 11511172
  writeRegister(0x40, 0x04); // TX Buffer - 11511182 to 11511316
  writeRegister(0x41, 0x0E); // TX Buffer - 11511329 to 11511464
  writeRegister(0x44, 0x23); // TX Buffer - 11511478 to 11511612
  writeRegister(0x45, 0x11); // TX Buffer - 11511626 to 11511762
  writeRegister(0x46, 0x13); // TX Buffer - 11511775 to 11511917
  writeRegister(0x04, 0x07); // TX - 11511924 to 11512059
  writeRegister(0x00, 0xFF); // CS0 - 11518789 to 11518927
  writeRegister(0x01, 0xFF); // CS1 - 11518939 to 11519079
  writeRegister(0x16, 0xC0); // FIFO CTRL - 11519093 to 11519228
  writeRegister(0x40, 0x04); // TX Buffer - 11519242 to 11519375
  writeRegister(0x41, 0x0E); // TX Buffer - 11519385 to 11519523
  writeRegister(0x44, 0x23); // TX Buffer - 11519534 to 11519676
  writeRegister(0x45, 0x11); // TX Buffer - 11519682 to 11519824
  writeRegister(0x46, 0x13); // TX Buffer - 11519830 to 11519969
  writeRegister(0x04, 0x07); // TX - 11519979 to 11520121
  writeRegister(0x00, 0xFF); // CS0 - 11526760 to 11526901
  writeRegister(0x01, 0xFF); // CS1 - 11526910 to 11527050
  writeRegister(0x16, 0xC0); // FIFO CTRL - 11527064 to 11527199
  writeRegister(0x40, 0x04); // TX Buffer - 11527213 to 11527346
  writeRegister(0x41, 0x0E); // TX Buffer - 11527360 to 11527494
  writeRegister(0x44, 0x23); // TX Buffer - 11527508 to 11527644
  writeRegister(0x45, 0x11); // TX Buffer - 11527656 to 11527791
  writeRegister(0x46, 0x13); // TX Buffer - 11527805 to 11527940
  writeRegister(0x04, 0x07); // TX - 11527954 to 11528088
  writeRegister(0x00, 0xFF); // CS0 - 11534735 to 11534871
  writeRegister(0x01, 0xFF); // CS1 - 11534885 to 11535026
  writeRegister(0x16, 0xC0); // FIFO CTRL - 11535035 to 11535173
  writeRegister(0x40, 0x04); // TX Buffer - 11535184 to 11535317
  writeRegister(0x41, 0x0E); // TX Buffer - 11535331 to 11535465
  writeRegister(0x44, 0x23); // TX Buffer - 11535479 to 11535615
  writeRegister(0x45, 0x11); // TX Buffer - 11535628 to 11535762
  writeRegister(0x46, 0x13); // TX Buffer - 11535776 to 11535911
  writeRegister(0x04, 0x07); // TX - 11535925 to 11536059
  writeRegister(0x00, 0xFF); // CS0 - 11542791 to 11542928
  writeRegister(0x01, 0xFF); // CS1 - 11542941 to 11543082
  writeRegister(0x16, 0xC0); // FIFO CTRL - 11543091 to 11543229
  writeRegister(0x40, 0x04); // TX Buffer - 11543239 to 11543373
  writeRegister(0x41, 0x0E); // TX Buffer - 11543386 to 11543521
  writeRegister(0x44, 0x23); // TX Buffer - 11543535 to 11543671
  writeRegister(0x45, 0x11); // TX Buffer - 11543683 to 11543819
  writeRegister(0x46, 0x13); // TX Buffer - 11543832 to 11543974
  writeRegister(0x04, 0x07); // TX - 11543981 to 11544116
  writeRegister(0x00, 0xFF); // CS0 - 11550762 to 11550901
  writeRegister(0x01, 0xFF); // CS1 - 11550912 to 11551053
  writeRegister(0x16, 0xC0); // FIFO CTRL - 11551065 to 11551200
  writeRegister(0x40, 0x04); // TX Buffer - 11551214 to 11551347
  writeRegister(0x41, 0x0E); // TX Buffer - 11551357 to 11551496
  writeRegister(0x44, 0x23); // TX Buffer - 11551506 to 11551644
  writeRegister(0x45, 0x11); // TX Buffer - 11551654 to 11551794
  writeRegister(0x46, 0x13); // TX Buffer - 11551803 to 11551941
  writeRegister(0x04, 0x07); // TX - 11551955 to 11552089
  writeRegister(0x00, 0xFF); // CS0 - 11558733 to 11558872
  writeRegister(0x01, 0xFF); // CS1 - 11558886 to 11559030
  writeRegister(0x16, 0xC0); // FIFO CTRL - 11559037 to 11559175
  writeRegister(0x40, 0x04); // TX Buffer - 11559185 to 11559318
  writeRegister(0x41, 0x0E); // TX Buffer - 11559332 to 11559467
  writeRegister(0x44, 0x23); // TX Buffer - 11559480 to 11559615
  writeRegister(0x45, 0x11); // TX Buffer - 11559629 to 11559765
  writeRegister(0x46, 0x13); // TX Buffer - 11559777 to 11559914
  writeRegister(0x04, 0x07); // TX - 11559926 to 11560060
  writeRegister(0x00, 0xFF); // CS0 - 11566792 to 11566928
  writeRegister(0x01, 0xFF); // CS1 - 11566942 to 11567083
  writeRegister(0x16, 0xC0); // FIFO CTRL - 11567092 to 11567230
  writeRegister(0x40, 0x04); // TX Buffer - 11567241 to 11567374
  writeRegister(0x41, 0x0E); // TX Buffer - 11567388 to 11567522
  writeRegister(0x44, 0x23); // TX Buffer - 11567536 to 11567672
  writeRegister(0x45, 0x11); // TX Buffer - 11567685 to 11567819
  writeRegister(0x46, 0x13); // TX Buffer - 11567833 to 11567968
  writeRegister(0x04, 0x07); // TX - 11567982 to 11568116
  writeRegister(0x00, 0xFF); // CS0 - 11574763 to 11574907
  writeRegister(0x01, 0xFF); // CS1 - 11574913 to 11575053
  writeRegister(0x16, 0xC0); // FIFO CTRL - 11575067 to 11575203
  writeRegister(0x40, 0x04); // TX Buffer - 11575215 to 11575348
  writeRegister(0x41, 0x0E); // TX Buffer - 11575359 to 11575497
  writeRegister(0x44, 0x23); // TX Buffer - 11575507 to 11575645
  writeRegister(0x45, 0x11); // TX Buffer - 11575656 to 11575795
  writeRegister(0x46, 0x13); // TX Buffer - 11575804 to 11575944
  writeRegister(0x04, 0x07); // TX - 11575953 to 11576092
  writeRegister(0x00, 0xFF); // CS0 - 11582734 to 11582875
  writeRegister(0x01, 0xFF); // CS1 - 11582887 to 11583024
  writeRegister(0x16, 0xC0); // FIFO CTRL - 11583038 to 11583173
  writeRegister(0x40, 0x04); // TX Buffer - 11583186 to 11583321
  writeRegister(0x41, 0x0E); // TX Buffer - 11583333 to 11583468
  writeRegister(0x44, 0x23); // TX Buffer - 11583482 to 11583616
  writeRegister(0x45, 0x11); // TX Buffer - 11583630 to 11583766
  writeRegister(0x46, 0x13); // TX Buffer - 11583779 to 11583915
  writeRegister(0x04, 0x07); // TX - 11583928 to 11584063
  writeRegister(0x00, 0xFF); // CS0 - 11590790 to 11590929
  writeRegister(0x01, 0xFF); // CS1 - 11590943 to 11591087
  writeRegister(0x16, 0xC0); // FIFO CTRL - 11591094 to 11591232
  writeRegister(0x40, 0x04); // TX Buffer - 11591242 to 11591375
  writeRegister(0x41, 0x0E); // TX Buffer - 11591389 to 11591524
  writeRegister(0x44, 0x23); // TX Buffer - 11591538 to 11591672
  writeRegister(0x45, 0x11); // TX Buffer - 11591686 to 11591822
  writeRegister(0x46, 0x13); // TX Buffer - 11591834 to 11591971
  writeRegister(0x04, 0x07); // TX - 11591983 to 11592119
  writeRegister(0x00, 0xFF); // CS0 - 11598764 to 11598908
  writeRegister(0x01, 0xFF); // CS1 - 11598914 to 11599054
  writeRegister(0x16, 0xC0); // FIFO CTRL - 11599068 to 11599203
  writeRegister(0x40, 0x04); // TX Buffer - 11599217 to 11599350
  writeRegister(0x41, 0x0E); // TX Buffer - 11599360 to 11599498
  writeRegister(0x44, 0x23); // TX Buffer - 11599509 to 11599651
  writeRegister(0x45, 0x11); // TX Buffer - 11599657 to 11599799
  writeRegister(0x46, 0x13); // TX Buffer - 11599805 to 11599944
  writeRegister(0x04, 0x07); // TX - 11599954 to 11600096
  writeRegister(0x00, 0xFF); // CS0 - 11606735 to 11606876
  writeRegister(0x01, 0xFF); // CS1 - 11606889 to 11607025
  writeRegister(0x16, 0xC0); // FIFO CTRL - 11607039 to 11607174
  writeRegister(0x40, 0x04); // TX Buffer - 11607188 to 11607321
  writeRegister(0x41, 0x0E); // TX Buffer - 11607335 to 11607469
  writeRegister(0x44, 0x23); // TX Buffer - 11607483 to 11607619
  writeRegister(0x45, 0x11); // TX Buffer - 11607632 to 11607766
  writeRegister(0x46, 0x13); // TX Buffer - 11607780 to 11607915
  writeRegister(0x04, 0x07); // TX - 11607929 to 11608063
  writeRegister(0x00, 0xFF); // CS0 - 11614791 to 11614932
  writeRegister(0x01, 0xFF); // CS1 - 11614945 to 11615081
  writeRegister(0x16, 0xC0); // FIFO CTRL - 11615095 to 11615230
  writeRegister(0x40, 0x04); // TX Buffer - 11615243 to 11615377
  writeRegister(0x41, 0x0E); // TX Buffer - 11615390 to 11615525
  writeRegister(0x44, 0x23); // TX Buffer - 11615539 to 11615675
  writeRegister(0x45, 0x11); // TX Buffer - 11615687 to 11615823
  writeRegister(0x46, 0x13); // TX Buffer - 11615836 to 11615972
  writeRegister(0x04, 0x07); // TX - 11615985 to 11616120
  writeRegister(0x00, 0xFF); // CS0 - 11622766 to 11622903
  writeRegister(0x01, 0xFF); // CS1 - 11622916 to 11623057
  writeRegister(0x16, 0xC0); // FIFO CTRL - 11623066 to 11623204
  writeRegister(0x40, 0x04); // TX Buffer - 11623214 to 11623354
  writeRegister(0x41, 0x0E); // TX Buffer - 11623361 to 11623504
  writeRegister(0x44, 0x23); // TX Buffer - 11623510 to 11623652
  writeRegister(0x45, 0x11); // TX Buffer - 11623658 to 11623799
  writeRegister(0x46, 0x13); // TX Buffer - 11623807 to 11623949
  writeRegister(0x04, 0x07); // TX - 11623956 to 11624097
  writeRegister(0x00, 0xFF); // CS0 - 11630737 to 11630876
  writeRegister(0x01, 0xFF); // CS1 - 11630887 to 11631028
  writeRegister(0x16, 0xC0); // FIFO CTRL - 11631040 to 11631175
  writeRegister(0x40, 0x04); // TX Buffer - 11631189 to 11631322
  writeRegister(0x41, 0x0E); // TX Buffer - 11631336 to 11631471
  writeRegister(0x44, 0x23); // TX Buffer - 11631484 to 11631619
  writeRegister(0x45, 0x11); // TX Buffer - 11631633 to 11631769
  writeRegister(0x46, 0x13); // TX Buffer - 11631781 to 11631916
  writeRegister(0x04, 0x07); // TX - 11631930 to 11632064
  writeRegister(0x00, 0xFF); // CS0 - 11638793 to 11638932
  writeRegister(0x01, 0xFF); // CS1 - 11638946 to 11639084
  writeRegister(0x16, 0xC0); // FIFO CTRL - 11639096 to 11639231
  writeRegister(0x40, 0x04); // TX Buffer - 11639245 to 11639378
  writeRegister(0x41, 0x0E); // TX Buffer - 11639392 to 11639526
  writeRegister(0x44, 0x23); // TX Buffer - 11639540 to 11639676
  writeRegister(0x45, 0x11); // TX Buffer - 11639689 to 11639823
  writeRegister(0x46, 0x13); // TX Buffer - 11639837 to 11639972
  writeRegister(0x04, 0x07); // TX - 11639986 to 11640120
  writeRegister(0x00, 0xFF); // CS0 - 11646767 to 11646903
  writeRegister(0x01, 0xFF); // CS1 - 11646917 to 11647058
  writeRegister(0x16, 0xC0); // FIFO CTRL - 11647067 to 11647205
  writeRegister(0x40, 0x04); // TX Buffer - 11647216 to 11647349
  writeRegister(0x41, 0x0E); // TX Buffer - 11647363 to 11647497
  writeRegister(0x44, 0x23); // TX Buffer - 11647511 to 11647647
  writeRegister(0x45, 0x11); // TX Buffer - 11647660 to 11647794
  writeRegister(0x46, 0x13); // TX Buffer - 11647808 to 11647951
  writeRegister(0x04, 0x07); // TX - 11647957 to 11648091
  writeRegister(0x00, 0xFF); // CS0 - 11654737 to 11654881
  writeRegister(0x01, 0xFF); // CS1 - 11654887 to 11655027
  writeRegister(0x16, 0xC0); // FIFO CTRL - 11655041 to 11655176
  writeRegister(0x40, 0x04); // TX Buffer - 11655190 to 11655323
  writeRegister(0x41, 0x0E); // TX Buffer - 11655333 to 11655471
  writeRegister(0x44, 0x23); // TX Buffer - 11655482 to 11655624
  writeRegister(0x45, 0x11); // TX Buffer - 11655630 to 11655772
  writeRegister(0x46, 0x13); // TX Buffer - 11655778 to 11655917
  writeRegister(0x04, 0x07); // TX - 11655927 to 11656069
  writeRegister(0x00, 0xFF); // CS0 - 11662793 to 11662937
  writeRegister(0x01, 0xFF); // CS1 - 11662943 to 11663083
  writeRegister(0x16, 0xC0); // FIFO CTRL - 11663097 to 11663232
  writeRegister(0x40, 0x04); // TX Buffer - 11663245 to 11663379
  writeRegister(0x41, 0x0E); // TX Buffer - 11663389 to 11663527
  writeRegister(0x44, 0x23); // TX Buffer - 11663537 to 11663675
  writeRegister(0x45, 0x11); // TX Buffer - 11663686 to 11663825
  writeRegister(0x46, 0x13); // TX Buffer - 11663834 to 11663974
  writeRegister(0x04, 0x07); // TX - 11663983 to 11664122
  writeRegister(0x00, 0xFF); // CS0 - 11670764 to 11670905
  writeRegister(0x01, 0xFF); // CS1 - 11670918 to 11671054
  writeRegister(0x16, 0xC0); // FIFO CTRL - 11671068 to 11671203
  writeRegister(0x40, 0x04); // TX Buffer - 11671216 to 11671350
  writeRegister(0x41, 0x0E); // TX Buffer - 11671363 to 11671498
  writeRegister(0x44, 0x23); // TX Buffer - 11671512 to 11671648
  writeRegister(0x45, 0x11); // TX Buffer - 11671660 to 11671796
  writeRegister(0x46, 0x13); // TX Buffer - 11671809 to 11671945
  writeRegister(0x04, 0x07); // TX - 11671958 to 11672093
  writeRegister(0x00, 0xFF); // CS0 - 11678739 to 11678876
  writeRegister(0x01, 0xFF); // CS1 - 11678889 to 11679030
  writeRegister(0x16, 0xC0); // FIFO CTRL - 11679039 to 11679177
  writeRegister(0x40, 0x04); // TX Buffer - 11679187 to 11679327
  writeRegister(0x41, 0x0E); // TX Buffer - 11679334 to 11679477
  writeRegister(0x44, 0x23); // TX Buffer - 11679483 to 11679625
  writeRegister(0x45, 0x11); // TX Buffer - 11679631 to 11679773
  writeRegister(0x46, 0x13); // TX Buffer - 11679780 to 11679922
  writeRegister(0x04, 0x07); // TX - 11679929 to 11680070
  writeRegister(0x00, 0xFF); // CS0 - 11686794 to 11686938
  writeRegister(0x01, 0xFF); // CS1 - 11686944 to 11687084
  writeRegister(0x16, 0xC0); // FIFO CTRL - 11687098 to 11687233
  writeRegister(0x40, 0x04); // TX Buffer - 11687247 to 11687380
  writeRegister(0x41, 0x0E); // TX Buffer - 11687390 to 11687528
  writeRegister(0x44, 0x23); // TX Buffer - 11687539 to 11687681
  writeRegister(0x45, 0x11); // TX Buffer - 11687687 to 11687829
  writeRegister(0x46, 0x13); // TX Buffer - 11687836 to 11687974
  writeRegister(0x04, 0x07); // TX - 11687984 to 11688126
  writeRegister(0x00, 0xFF); // CS0 - 11694766 to 11694905
  writeRegister(0x01, 0xFF); // CS1 - 11694919 to 11695057
  writeRegister(0x16, 0xC0); // FIFO CTRL - 11695069 to 11695204
  writeRegister(0x40, 0x04); // TX Buffer - 11695218 to 11695351
  writeRegister(0x41, 0x0E); // TX Buffer - 11695365 to 11695499
  writeRegister(0x44, 0x23); // TX Buffer - 11695513 to 11695649
  writeRegister(0x45, 0x11); // TX Buffer - 11695662 to 11695796
  writeRegister(0x46, 0x13); // TX Buffer - 11695810 to 11695945
  writeRegister(0x04, 0x07); // TX - 11695959 to 11696093
  writeRegister(0x00, 0xFF); // CS0 - 11702740 to 11702876
  writeRegister(0x01, 0xFF); // CS1 - 11702890 to 11703031
  writeRegister(0x16, 0xC0); // FIFO CTRL - 11703040 to 11703178
  writeRegister(0x40, 0x04); // TX Buffer - 11703189 to 11703322
  writeRegister(0x41, 0x0E); // TX Buffer - 11703336 to 11703470
  writeRegister(0x44, 0x23); // TX Buffer - 11703484 to 11703620
  writeRegister(0x45, 0x11); // TX Buffer - 11703633 to 11703767
  writeRegister(0x46, 0x13); // TX Buffer - 11703781 to 11703924
  writeRegister(0x04, 0x07); // TX - 11703930 to 11704064
  writeRegister(0x00, 0xFF); // CS0 - 11710796 to 11710933
  writeRegister(0x01, 0xFF); // CS1 - 11710946 to 11711087
  writeRegister(0x16, 0xC0); // FIFO CTRL - 11711096 to 11711234
  writeRegister(0x40, 0x04); // TX Buffer - 11711245 to 11711384
  writeRegister(0x41, 0x0E); // TX Buffer - 11711392 to 11711534
  writeRegister(0x44, 0x23); // TX Buffer - 11711540 to 11711682
  writeRegister(0x45, 0x11); // TX Buffer - 11711688 to 11711831
  writeRegister(0x46, 0x13); // TX Buffer - 11711837 to 11711980
  writeRegister(0x04, 0x07); // TX - 11711986 to 11712127
  writeRegister(0x00, 0xFF); // CS0 - 11718767 to 11718906
  writeRegister(0x01, 0xFF); // CS1 - 11718917 to 11719058
  writeRegister(0x16, 0xC0); // FIFO CTRL - 11719071 to 11719205
  writeRegister(0x40, 0x04); // TX Buffer - 11719219 to 11719352
  writeRegister(0x41, 0x0E); // TX Buffer - 11719366 to 11719501
  writeRegister(0x44, 0x23); // TX Buffer - 11719514 to 11719649
  writeRegister(0x45, 0x11); // TX Buffer - 11719663 to 11719799
  writeRegister(0x46, 0x13); // TX Buffer - 11719811 to 11719948
  writeRegister(0x04, 0x07); // TX - 11719960 to 11720096
  writeRegister(0x00, 0xFF); // CS0 - 11726738 to 11726879
  writeRegister(0x01, 0xFF); // CS1 - 11726891 to 11727035
  writeRegister(0x16, 0xC0); // FIFO CTRL - 11727042 to 11727180
  writeRegister(0x40, 0x04); // TX Buffer - 11727190 to 11727323
  writeRegister(0x41, 0x0E); // TX Buffer - 11727337 to 11727472
  writeRegister(0x44, 0x23); // TX Buffer - 11727486 to 11727620
  writeRegister(0x45, 0x11); // TX Buffer - 11727634 to 11727770
  writeRegister(0x46, 0x13); // TX Buffer - 11727782 to 11727919
  writeRegister(0x04, 0x07); // TX - 11727931 to 11728067
  writeRegister(0x00, 0xFF); // CS0 - 11734797 to 11734933
  writeRegister(0x01, 0xFF); // CS1 - 11734947 to 11735087
  writeRegister(0x16, 0xC0); // FIFO CTRL - 11735097 to 11735236
  writeRegister(0x40, 0x04); // TX Buffer - 11735246 to 11735379
  writeRegister(0x41, 0x0E); // TX Buffer - 11735393 to 11735528
  writeRegister(0x44, 0x23); // TX Buffer - 11735541 to 11735677
  writeRegister(0x45, 0x11); // TX Buffer - 11735690 to 11735824
  writeRegister(0x46, 0x13); // TX Buffer - 11735838 to 11735981
  writeRegister(0x04, 0x07); // TX - 11735987 to 11736121
  writeRegister(0x00, 0xFF); // CS0 - 11742768 to 11742909
  writeRegister(0x01, 0xFF); // CS1 - 11742918 to 11743058
  writeRegister(0x16, 0xC0); // FIFO CTRL - 11743072 to 11743207
  writeRegister(0x40, 0x04); // TX Buffer - 11743220 to 11743354
  writeRegister(0x41, 0x0E); // TX Buffer - 11743364 to 11743502
  writeRegister(0x44, 0x23); // TX Buffer - 11743512 to 11743652
  writeRegister(0x45, 0x11); // TX Buffer - 11743661 to 11743800
  writeRegister(0x46, 0x13); // TX Buffer - 11743809 to 11743949
  writeRegister(0x04, 0x07); // TX - 11743962 to 11744097
  writeRegister(0x00, 0xFF); // CS0 - 11750739 to 11750880
  writeRegister(0x01, 0xFF); // CS1 - 11750893 to 11751037
  writeRegister(0x16, 0xC0); // FIFO CTRL - 11751043 to 11751184
  writeRegister(0x40, 0x04); // TX Buffer - 11751191 to 11751325
  writeRegister(0x41, 0x0E); // TX Buffer - 11751338 to 11751473
  writeRegister(0x44, 0x23); // TX Buffer - 11751487 to 11751623
  writeRegister(0x45, 0x11); // TX Buffer - 11751635 to 11751771
  writeRegister(0x46, 0x13); // TX Buffer - 11751784 to 11751920
  writeRegister(0x04, 0x07); // TX - 11751933 to 11752068
  writeRegister(0x00, 0xFF); // CS0 - 11758795 to 11758936
  writeRegister(0x01, 0xFF); // CS1 - 11758948 to 11759092
  writeRegister(0x16, 0xC0); // FIFO CTRL - 11759099 to 11759237
  writeRegister(0x40, 0x04); // TX Buffer - 11759247 to 11759380
  writeRegister(0x41, 0x0E); // TX Buffer - 11759394 to 11759529
  writeRegister(0x44, 0x23); // TX Buffer - 11759543 to 11759677
  writeRegister(0x45, 0x11); // TX Buffer - 11759691 to 11759827
  writeRegister(0x46, 0x13); // TX Buffer - 11759840 to 11759976
  writeRegister(0x04, 0x07); // TX - 11759988 to 11760124
  writeRegister(0x00, 0xFF); // CS0 - 11766769 to 11766913
  writeRegister(0x01, 0xFF); // CS1 - 11766919 to 11767059
  writeRegister(0x16, 0xC0); // FIFO CTRL - 11767073 to 11767208
  writeRegister(0x40, 0x04); // TX Buffer - 11767222 to 11767355
  writeRegister(0x41, 0x0E); // TX Buffer - 11767365 to 11767503
  writeRegister(0x44, 0x23); // TX Buffer - 11767514 to 11767653
  writeRegister(0x45, 0x11); // TX Buffer - 11767662 to 11767800
  writeRegister(0x46, 0x13); // TX Buffer - 11767811 to 11767949
  writeRegister(0x04, 0x07); // TX - 11767960 to 11768097
  writeRegister(0x00, 0xFF); // CS0 - 11774741 to 11774880
  writeRegister(0x01, 0xFF); // CS1 - 11774894 to 11775032
  writeRegister(0x16, 0xC0); // FIFO CTRL - 11775044 to 11775179
  writeRegister(0x40, 0x04); // TX Buffer - 11775193 to 11775326
  writeRegister(0x41, 0x0E); // TX Buffer - 11775340 to 11775474
  writeRegister(0x44, 0x23); // TX Buffer - 11775488 to 11775624
  writeRegister(0x45, 0x11); // TX Buffer - 11775637 to 11775771
  writeRegister(0x46, 0x13); // TX Buffer - 11775785 to 11775920
  writeRegister(0x04, 0x07); // TX - 11775934 to 11776068
  writeRegister(0x00, 0xFF); // CS0 - 11782796 to 11782937
  writeRegister(0x01, 0xFF); // CS1 - 11782950 to 11783094
  writeRegister(0x16, 0xC0); // FIFO CTRL - 11783100 to 11783241
  writeRegister(0x40, 0x04); // TX Buffer - 11783249 to 11783382
  writeRegister(0x41, 0x0E); // TX Buffer - 11783396 to 11783530
  writeRegister(0x44, 0x23); // TX Buffer - 11783544 to 11783680
  writeRegister(0x45, 0x11); // TX Buffer - 11783692 to 11783827
  writeRegister(0x46, 0x13); // TX Buffer - 11783841 to 11783976
  writeRegister(0x04, 0x07); // TX - 11783990 to 11784125
  writeRegister(0x00, 0xFF); // CS0 - 11790771 to 11790908
  writeRegister(0x01, 0xFF); // CS1 - 11790921 to 11791062
  writeRegister(0x16, 0xC0); // FIFO CTRL - 11791075 to 11791209
  writeRegister(0x40, 0x04); // TX Buffer - 11791223 to 11791356
  writeRegister(0x41, 0x0E); // TX Buffer - 11791367 to 11791505
  writeRegister(0x44, 0x23); // TX Buffer - 11791515 to 11791657
  writeRegister(0x45, 0x11); // TX Buffer - 11791663 to 11791806
  writeRegister(0x46, 0x13); // TX Buffer - 11791812 to 11791952
  writeRegister(0x04, 0x07); // TX - 11791961 to 11792101
  writeRegister(0x00, 0xFF); // CS0 - 11798742 to 11798881
  writeRegister(0x01, 0xFF); // CS1 - 11798892 to 11799033
  writeRegister(0x16, 0xC0); // FIFO CTRL - 11799046 to 11799180
  writeRegister(0x40, 0x04); // TX Buffer - 11799194 to 11799327
  writeRegister(0x41, 0x0E); // TX Buffer - 11799341 to 11799476
  writeRegister(0x44, 0x23); // TX Buffer - 11799489 to 11799624
  writeRegister(0x45, 0x11); // TX Buffer - 11799638 to 11799774
  writeRegister(0x46, 0x13); // TX Buffer - 11799786 to 11799923
  writeRegister(0x04, 0x07); // TX - 11799935 to 11800071
  writeRegister(0x00, 0xFF); // CS0 - 11806798 to 11806937
  writeRegister(0x01, 0xFF); // CS1 - 11806951 to 11807089
  writeRegister(0x16, 0xC0); // FIFO CTRL - 11807101 to 11807236
  writeRegister(0x40, 0x04); // TX Buffer - 11807250 to 11807383
  writeRegister(0x41, 0x0E); // TX Buffer - 11807397 to 11807533
  writeRegister(0x44, 0x23); // TX Buffer - 11807545 to 11807681
  writeRegister(0x45, 0x11); // TX Buffer - 11807694 to 11807828
  writeRegister(0x46, 0x13); // TX Buffer - 11807842 to 11807977
  writeRegister(0x04, 0x07); // TX - 11807991 to 11808125
  writeRegister(0x00, 0xFF); // CS0 - 11814772 to 11814908
  writeRegister(0x01, 0xFF); // CS1 - 11814922 to 11815062
  writeRegister(0x16, 0xC0); // FIFO CTRL - 11815072 to 11815211
  writeRegister(0x40, 0x04); // TX Buffer - 11815221 to 11815354
  writeRegister(0x41, 0x0E); // TX Buffer - 11815368 to 11815503
  writeRegister(0x44, 0x23); // TX Buffer - 11815516 to 11815651
  writeRegister(0x45, 0x11); // TX Buffer - 11815665 to 11815801
  writeRegister(0x46, 0x13); // TX Buffer - 11815813 to 11815956
  writeRegister(0x04, 0x07); // TX - 11815962 to 11816096
  writeRegister(0x00, 0xFF); // CS0 - 11822743 to 11822884
  writeRegister(0x01, 0xFF); // CS1 - 11822893 to 11823033
  writeRegister(0x16, 0xC0); // FIFO CTRL - 11823047 to 11823182
  writeRegister(0x40, 0x04); // TX Buffer - 11823195 to 11823329
  writeRegister(0x41, 0x0E); // TX Buffer - 11823339 to 11823477
  writeRegister(0x44, 0x23); // TX Buffer - 11823487 to 11823627
  writeRegister(0x45, 0x11); // TX Buffer - 11823636 to 11823775
  writeRegister(0x46, 0x13); // TX Buffer - 11823784 to 11823924
  writeRegister(0x04, 0x07); // TX - 11823937 to 11824072
  writeRegister(0x00, 0xFF); // CS0 - 11830799 to 11830940
  writeRegister(0x01, 0xFF); // CS1 - 11830949 to 11831090
  writeRegister(0x16, 0xC0); // FIFO CTRL - 11831103 to 11831237
  writeRegister(0x40, 0x04); // TX Buffer - 11831251 to 11831384
  writeRegister(0x41, 0x0E); // TX Buffer - 11831398 to 11831533
  writeRegister(0x44, 0x23); // TX Buffer - 11831547 to 11831681
  writeRegister(0x45, 0x11); // TX Buffer - 11831695 to 11831831
  writeRegister(0x46, 0x13); // TX Buffer - 11831843 to 11831980
  writeRegister(0x04, 0x07); // TX - 11831992 to 11832128
  writeRegister(0x00, 0xFF); // CS0 - 11838773 to 11838911
  writeRegister(0x01, 0xFF); // CS1 - 11838923 to 11839063
  writeRegister(0x16, 0xC0); // FIFO CTRL - 11839074 to 11839212
  writeRegister(0x40, 0x04); // TX Buffer - 11839222 to 11839355
  writeRegister(0x41, 0x0E); // TX Buffer - 11839369 to 11839504
  writeRegister(0x44, 0x23); // TX Buffer - 11839518 to 11839652
  writeRegister(0x45, 0x11); // TX Buffer - 11839666 to 11839802
  writeRegister(0x46, 0x13); // TX Buffer - 11839815 to 11839951
  writeRegister(0x04, 0x07); // TX - 11839963 to 11840099
  writeRegister(0x00, 0xFF); // CS0 - 11846745 to 11846888
  writeRegister(0x01, 0xFF); // CS1 - 11846894 to 11847036
  writeRegister(0x16, 0xC0); // FIFO CTRL - 11847048 to 11847183
  writeRegister(0x40, 0x04); // TX Buffer - 11847197 to 11847330
  writeRegister(0x41, 0x0E); // TX Buffer - 11847340 to 11847478
  writeRegister(0x44, 0x23); // TX Buffer - 11847489 to 11847628
  writeRegister(0x45, 0x11); // TX Buffer - 11847637 to 11847775
  writeRegister(0x46, 0x13); // TX Buffer - 11847786 to 11847924
  writeRegister(0x04, 0x07); // TX - 11847935 to 11848072
  writeRegister(0x00, 0xFF); // CS0 - 11854800 to 11854941
  writeRegister(0x01, 0xFF); // CS1 - 11854950 to 11855090
  writeRegister(0x16, 0xC0); // FIFO CTRL - 11855104 to 11855239
  writeRegister(0x40, 0x04); // TX Buffer - 11855252 to 11855386
  writeRegister(0x41, 0x0E); // TX Buffer - 11855396 to 11855534
  writeRegister(0x44, 0x23); // TX Buffer - 11855545 to 11855684
  writeRegister(0x45, 0x11); // TX Buffer - 11855693 to 11855831
  writeRegister(0x46, 0x13); // TX Buffer - 11855841 to 11855981
  writeRegister(0x04, 0x07); // TX - 11855994 to 11856129
  writeRegister(0x00, 0xFF); // CS0 - 11862771 to 11862912
  writeRegister(0x01, 0xFF); // CS1 - 11862925 to 11863069
  writeRegister(0x16, 0xC0); // FIFO CTRL - 11863075 to 11863213
  writeRegister(0x40, 0x04); // TX Buffer - 11863224 to 11863357
  writeRegister(0x41, 0x0E); // TX Buffer - 11863371 to 11863505
  writeRegister(0x44, 0x23); // TX Buffer - 11863519 to 11863655
  writeRegister(0x45, 0x11); // TX Buffer - 11863667 to 11863802
  writeRegister(0x46, 0x13); // TX Buffer - 11863816 to 11863951
  writeRegister(0x04, 0x07); // TX - 11863965 to 11864099
  writeRegister(0x00, 0xFF); // CS0 - 11870746 to 11870889
  writeRegister(0x01, 0xFF); // CS1 - 11870896 to 11871037
  writeRegister(0x16, 0xC0); // FIFO CTRL - 11871050 to 11871184
  writeRegister(0x40, 0x04); // TX Buffer - 11871198 to 11871331
  writeRegister(0x41, 0x0E); // TX Buffer - 11871342 to 11871480
  writeRegister(0x44, 0x23); // TX Buffer - 11871490 to 11871632
  writeRegister(0x45, 0x11); // TX Buffer - 11871638 to 11871781
  writeRegister(0x46, 0x13); // TX Buffer - 11871787 to 11871927
  writeRegister(0x04, 0x07); // TX - 11871936 to 11872078
  writeRegister(0x00, 0xFF); // CS0 - 11878802 to 11878945
  writeRegister(0x01, 0xFF); // CS1 - 11878952 to 11879093
  writeRegister(0x16, 0xC0); // FIFO CTRL - 11879105 to 11879240
  writeRegister(0x40, 0x04); // TX Buffer - 11879254 to 11879387
  writeRegister(0x41, 0x0E); // TX Buffer - 11879397 to 11879537
  writeRegister(0x44, 0x23); // TX Buffer - 11879546 to 11879685
  writeRegister(0x45, 0x11); // TX Buffer - 11879694 to 11879832
  writeRegister(0x46, 0x13); // TX Buffer - 11879843 to 11879981
  writeRegister(0x04, 0x07); // TX - 11879992 to 11880129
  writeRegister(0x00, 0xFF); // CS0 - 11886773 to 11886912
  writeRegister(0x01, 0xFF); // CS1 - 11886926 to 11887064
  writeRegister(0x16, 0xC0); // FIFO CTRL - 11887076 to 11887211
  writeRegister(0x40, 0x04); // TX Buffer - 11887225 to 11887358
  writeRegister(0x41, 0x0E); // TX Buffer - 11887372 to 11887507
  writeRegister(0x44, 0x23); // TX Buffer - 11887520 to 11887656
  writeRegister(0x45, 0x11); // TX Buffer - 11887669 to 11887803
  writeRegister(0x46, 0x13); // TX Buffer - 11887817 to 11887952
  writeRegister(0x04, 0x07); // TX - 11887966 to 11888100
  writeRegister(0x00, 0xFF); // CS0 - 11894747 to 11894883
  writeRegister(0x01, 0xFF); // CS1 - 11894897 to 11895037
  writeRegister(0x16, 0xC0); // FIFO CTRL - 11895047 to 11895186
  writeRegister(0x40, 0x04); // TX Buffer - 11895196 to 11895337
  writeRegister(0x41, 0x0E); // TX Buffer - 11895343 to 11895484
  writeRegister(0x44, 0x23); // TX Buffer - 11895491 to 11895634
  writeRegister(0x45, 0x11); // TX Buffer - 11895640 to 11895782
  writeRegister(0x46, 0x13); // TX Buffer - 11895788 to 11895931
  writeRegister(0x04, 0x07); // TX - 11895937 to 11896079
  writeRegister(0x00, 0xFF); // CS0 - 11902803 to 11902947
  writeRegister(0x01, 0xFF); // CS1 - 11902953 to 11903094
  writeRegister(0x16, 0xC0); // FIFO CTRL - 11903107 to 11903241
  writeRegister(0x40, 0x04); // TX Buffer - 11903255 to 11903388
  writeRegister(0x41, 0x0E); // TX Buffer - 11903399 to 11903537
  writeRegister(0x44, 0x23); // TX Buffer - 11903547 to 11903689
  writeRegister(0x45, 0x11); // TX Buffer - 11903696 to 11903838
  writeRegister(0x46, 0x13); // TX Buffer - 11903844 to 11903984
  writeRegister(0x04, 0x07); // TX - 11903993 to 11904135
  writeRegister(0x00, 0xFF); // CS0 - 11910774 to 11910915
  writeRegister(0x01, 0xFF); // CS1 - 11910927 to 11911065
  writeRegister(0x16, 0xC0); // FIFO CTRL - 11911078 to 11911212
  writeRegister(0x40, 0x04); // TX Buffer - 11911226 to 11911359
  writeRegister(0x41, 0x0E); // TX Buffer - 11911373 to 11911508
  writeRegister(0x44, 0x23); // TX Buffer - 11911522 to 11911656
  writeRegister(0x45, 0x11); // TX Buffer - 11911670 to 11911806
  writeRegister(0x46, 0x13); // TX Buffer - 11911819 to 11911955
  writeRegister(0x04, 0x07); // TX - 11911967 to 11912103
  writeRegister(0x00, 0xFF); // CS0 - 11918748 to 11918886
  writeRegister(0x01, 0xFF); // CS1 - 11918898 to 11919038
  writeRegister(0x16, 0xC0); // FIFO CTRL - 11919049 to 11919187
  writeRegister(0x40, 0x04); // TX Buffer - 11919197 to 11919332
  writeRegister(0x41, 0x0E); // TX Buffer - 11919344 to 11919479
  writeRegister(0x44, 0x23); // TX Buffer - 11919493 to 11919627
  writeRegister(0x45, 0x11); // TX Buffer - 11919641 to 11919777
  writeRegister(0x46, 0x13); // TX Buffer - 11919790 to 11919932
  writeRegister(0x04, 0x07); // TX - 11919939 to 11920074
  writeRegister(0x00, 0xFF); // CS0 - 11926804 to 11926940
  writeRegister(0x01, 0xFF); // CS1 - 11926954 to 11927094
  writeRegister(0x16, 0xC0); // FIFO CTRL - 11927105 to 11927243
  writeRegister(0x40, 0x04); // TX Buffer - 11927253 to 11927394
  writeRegister(0x41, 0x0E); // TX Buffer - 11927400 to 11927541
  writeRegister(0x44, 0x23); // TX Buffer - 11927548 to 11927691
  writeRegister(0x45, 0x11); // TX Buffer - 11927697 to 11927839
  writeRegister(0x46, 0x13); // TX Buffer - 11927845 to 11927988
  writeRegister(0x04, 0x07); // TX - 11927994 to 11928136
  writeRegister(0x00, 0xFF); // CS0 - 11934775 to 11934916
  writeRegister(0x01, 0xFF); // CS1 - 11934925 to 11935065
  writeRegister(0x16, 0xC0); // FIFO CTRL - 11935079 to 11935214
  writeRegister(0x40, 0x04); // TX Buffer - 11935228 to 11935361
  writeRegister(0x41, 0x0E); // TX Buffer - 11935375 to 11935509
  writeRegister(0x44, 0x23); // TX Buffer - 11935523 to 11935659
  writeRegister(0x45, 0x11); // TX Buffer - 11935671 to 11935806
  writeRegister(0x46, 0x13); // TX Buffer - 11935820 to 11935955
  writeRegister(0x04, 0x07); // TX - 11935969 to 11936104
  writeRegister(0x00, 0xFF); // CS0 - 11942746 to 11942887
  writeRegister(0x01, 0xFF); // CS1 - 11942900 to 11943044
  writeRegister(0x16, 0xC0); // FIFO CTRL - 11943050 to 11943188
  writeRegister(0x40, 0x04); // TX Buffer - 11943199 to 11943332
  writeRegister(0x41, 0x0E); // TX Buffer - 11943346 to 11943480
  writeRegister(0x44, 0x23); // TX Buffer - 11943494 to 11943630
  writeRegister(0x45, 0x11); // TX Buffer - 11943642 to 11943777
  writeRegister(0x46, 0x13); // TX Buffer - 11943791 to 11943926
  writeRegister(0x04, 0x07); // TX - 11943940 to 11944074
  writeRegister(0x00, 0xFF); // CS0 - 11950806 to 11950943
  writeRegister(0x01, 0xFF); // CS1 - 11950956 to 11951097
  writeRegister(0x16, 0xC0); // FIFO CTRL - 11951106 to 11951244
  writeRegister(0x40, 0x04); // TX Buffer - 11951254 to 11951388
  writeRegister(0x41, 0x0E); // TX Buffer - 11951401 to 11951536
  writeRegister(0x44, 0x23); // TX Buffer - 11951550 to 11951686
  writeRegister(0x45, 0x11); // TX Buffer - 11951698 to 11951834
  writeRegister(0x46, 0x13); // TX Buffer - 11951847 to 11951989
  writeRegister(0x04, 0x07); // TX - 11951996 to 11952131
  writeRegister(0x00, 0xFF); // CS0 - 11958777 to 11958916
  writeRegister(0x01, 0xFF); // CS1 - 11958927 to 11959068
  writeRegister(0x16, 0xC0); // FIFO CTRL - 11959080 to 11959215
  writeRegister(0x40, 0x04); // TX Buffer - 11959229 to 11959362
  writeRegister(0x41, 0x0E); // TX Buffer - 11959372 to 11959512
  writeRegister(0x44, 0x23); // TX Buffer - 11959521 to 11959660
  writeRegister(0x45, 0x11); // TX Buffer - 11959669 to 11959807
  writeRegister(0x46, 0x13); // TX Buffer - 11959818 to 11959956
  writeRegister(0x04, 0x07); // TX - 11959970 to 11960104
  writeRegister(0x00, 0xFF); // CS0 - 11966748 to 11966887
  writeRegister(0x01, 0xFF); // CS1 - 11966901 to 11967045
  writeRegister(0x16, 0xC0); // FIFO CTRL - 11967051 to 11967194
  writeRegister(0x40, 0x04); // TX Buffer - 11967200 to 11967333
  writeRegister(0x41, 0x0E); // TX Buffer - 11967347 to 11967482
  writeRegister(0x44, 0x23); // TX Buffer - 11967495 to 11967630
  writeRegister(0x45, 0x11); // TX Buffer - 11967644 to 11967780
  writeRegister(0x46, 0x13); // TX Buffer - 11967792 to 11967927
  writeRegister(0x04, 0x07); // TX - 11967941 to 11968075
  writeRegister(0x00, 0xFF); // CS0 - 11974804 to 11974943
  writeRegister(0x01, 0xFF); // CS1 - 11974957 to 11975101
  writeRegister(0x16, 0xC0); // FIFO CTRL - 11975107 to 11975245
  writeRegister(0x40, 0x04); // TX Buffer - 11975256 to 11975389
  writeRegister(0x41, 0x0E); // TX Buffer - 11975403 to 11975537
  writeRegister(0x44, 0x23); // TX Buffer - 11975551 to 11975687
  writeRegister(0x45, 0x11); // TX Buffer - 11975700 to 11975834
  writeRegister(0x46, 0x13); // TX Buffer - 11975848 to 11975983
  writeRegister(0x04, 0x07); // TX - 11975997 to 11976131
  writeRegister(0x00, 0xFF); // CS0 - 11982778 to 11982922
  writeRegister(0x01, 0xFF); // CS1 - 11982928 to 11983069
  writeRegister(0x16, 0xC0); // FIFO CTRL - 11983082 to 11983216
  writeRegister(0x40, 0x04); // TX Buffer - 11983230 to 11983363
  writeRegister(0x41, 0x0E); // TX Buffer - 11983374 to 11983512
  writeRegister(0x44, 0x23); // TX Buffer - 11983522 to 11983660
  writeRegister(0x45, 0x11); // TX Buffer - 11983671 to 11983810
  writeRegister(0x46, 0x13); // TX Buffer - 11983819 to 11983959
  writeRegister(0x04, 0x07); // TX - 11983968 to 11984107
  writeRegister(0x00, 0xFF); // CS0 - 11990749 to 11990890
  writeRegister(0x01, 0xFF); // CS1 - 11990902 to 11991039
  writeRegister(0x16, 0xC0); // FIFO CTRL - 11991053 to 11991187
  writeRegister(0x40, 0x04); // TX Buffer - 11991201 to 11991334
  writeRegister(0x41, 0x0E); // TX Buffer - 11991348 to 11991483
  writeRegister(0x44, 0x23); // TX Buffer - 11991497 to 11991631
  writeRegister(0x45, 0x11); // TX Buffer - 11991645 to 11991781
  writeRegister(0x46, 0x13); // TX Buffer - 11991794 to 11991930
  writeRegister(0x04, 0x07); // TX - 11991942 to 11992078
  writeRegister(0x00, 0xFF); // CS0 - 11998805 to 11998944
  writeRegister(0x01, 0xFF); // CS1 - 11998958 to 11999102
  writeRegister(0x16, 0xC0); // FIFO CTRL - 11999109 to 11999251
  writeRegister(0x40, 0x04); // TX Buffer - 11999257 to 11999390
  writeRegister(0x41, 0x0E); // TX Buffer - 11999404 to 11999539
  writeRegister(0x44, 0x23); // TX Buffer - 11999552 to 11999687
  writeRegister(0x45, 0x11); // TX Buffer - 11999701 to 11999837
  writeRegister(0x46, 0x13); // TX Buffer - 11999849 to 11999986
  writeRegister(0x04, 0x07); // TX - 11999998 to 12000134
  writeRegister(0x00, 0xFF); // CS0 - 12006779 to 12006915
  writeRegister(0x01, 0xFF); // CS1 - 12006929 to 12007069
  writeRegister(0x16, 0xC0); // FIFO CTRL - 12007083 to 12007218
  writeRegister(0x40, 0x04); // TX Buffer - 12007231 to 12007365
  writeRegister(0x41, 0x0E); // TX Buffer - 12007375 to 12007513
  writeRegister(0x44, 0x23); // TX Buffer - 12007524 to 12007666
  writeRegister(0x45, 0x11); // TX Buffer - 12007672 to 12007814
  writeRegister(0x46, 0x13); // TX Buffer - 12007820 to 12007960
  writeRegister(0x04, 0x07); // TX - 12007969 to 12008111
  writeRegister(0x00, 0xFF); // CS0 - 12014835 to 12014979
  writeRegister(0x01, 0xFF); // CS1 - 12014985 to 12015125
  writeRegister(0x16, 0xC0); // FIFO CTRL - 12015139 to 12015275
  writeRegister(0x40, 0x04); // TX Buffer - 12015287 to 12015422
  writeRegister(0x41, 0x0E); // TX Buffer - 12015431 to 12015569
  writeRegister(0x44, 0x23); // TX Buffer - 12015579 to 12015717
  writeRegister(0x45, 0x11); // TX Buffer - 12015728 to 12015867
  writeRegister(0x46, 0x13); // TX Buffer - 12015876 to 12016016
  writeRegister(0x04, 0x07); // TX - 12016025 to 12016164
  writeRegister(0x00, 0xFF); // CS0 - 12022806 to 12022947
  writeRegister(0x01, 0xFF); // CS1 - 12022959 to 12023096
  writeRegister(0x16, 0xC0); // FIFO CTRL - 12023110 to 12023245
  writeRegister(0x40, 0x04); // TX Buffer - 12023258 to 12023392
  writeRegister(0x41, 0x0E); // TX Buffer - 12023405 to 12023540
  writeRegister(0x44, 0x23); // TX Buffer - 12023554 to 12023688
  writeRegister(0x45, 0x11); // TX Buffer - 12023702 to 12023838
  writeRegister(0x46, 0x13); // TX Buffer - 12023851 to 12023987
  writeRegister(0x04, 0x07); // TX - 12024000 to 12024135
  writeRegister(0x00, 0xFF); // CS0 - 12030781 to 12030918
  writeRegister(0x01, 0xFF); // CS1 - 12030931 to 12031072
  writeRegister(0x16, 0xC0); // FIFO CTRL - 12031081 to 12031219
  writeRegister(0x40, 0x04); // TX Buffer - 12031229 to 12031363
  writeRegister(0x41, 0x0E); // TX Buffer - 12031376 to 12031511
  writeRegister(0x44, 0x23); // TX Buffer - 12031525 to 12031661
  writeRegister(0x45, 0x11); // TX Buffer - 12031673 to 12031809
  writeRegister(0x46, 0x13); // TX Buffer - 12031822 to 12031964
  writeRegister(0x04, 0x07); // TX - 12031971 to 12032106
  writeRegister(0x00, 0xFF); // CS0 - 12038836 to 12038974
  writeRegister(0x01, 0xFF); // CS1 - 12038986 to 12039126
  writeRegister(0x16, 0xC0); // FIFO CTRL - 12039140 to 12039275
  writeRegister(0x40, 0x04); // TX Buffer - 12039289 to 12039422
  writeRegister(0x41, 0x0E); // TX Buffer - 12039432 to 12039570
  writeRegister(0x44, 0x23); // TX Buffer - 12039581 to 12039723
  writeRegister(0x45, 0x11); // TX Buffer - 12039729 to 12039871
  writeRegister(0x46, 0x13); // TX Buffer - 12039878 to 12040016
  writeRegister(0x04, 0x07); // TX - 12040026 to 12040168
  writeRegister(0x00, 0xFF); // CS0 - 12046807 to 12046947
  writeRegister(0x01, 0xFF); // CS1 - 12046957 to 12047097
  writeRegister(0x16, 0xC0); // FIFO CTRL - 12047111 to 12047246
  writeRegister(0x40, 0x04); // TX Buffer - 12047260 to 12047393
  writeRegister(0x41, 0x0E); // TX Buffer - 12047407 to 12047541
  writeRegister(0x44, 0x23); // TX Buffer - 12047555 to 12047691
  writeRegister(0x45, 0x11); // TX Buffer - 12047704 to 12047838
  writeRegister(0x46, 0x13); // TX Buffer - 12047852 to 12047987
  writeRegister(0x04, 0x07); // TX - 12048001 to 12048135
  writeRegister(0x00, 0xFF); // CS0 - 12054770 to 12054910
  writeRegister(0x01, 0xFF); // CS1 - 12054924 to 12055068
  writeRegister(0x16, 0xC0); // FIFO CTRL - 12055074 to 12055212
  writeRegister(0x40, 0x04); // TX Buffer - 12055223 to 12055356
  writeRegister(0x41, 0x0E); // TX Buffer - 12055370 to 12055504
  writeRegister(0x44, 0x23); // TX Buffer - 12055518 to 12055654
  writeRegister(0x45, 0x11); // TX Buffer - 12055667 to 12055801
  writeRegister(0x46, 0x13); // TX Buffer - 12055815 to 12055950
  writeRegister(0x04, 0x07); // TX - 12055964 to 12056098
  writeRegister(0x00, 0xFF); // CS0 - 12062830 to 12062967
  writeRegister(0x01, 0xFF); // CS1 - 12062980 to 12063121
  writeRegister(0x16, 0xC0); // FIFO CTRL - 12063130 to 12063268
  writeRegister(0x40, 0x04); // TX Buffer - 12063278 to 12063412
  writeRegister(0x41, 0x0E); // TX Buffer - 12063425 to 12063560
  writeRegister(0x44, 0x23); // TX Buffer - 12063574 to 12063710
  writeRegister(0x45, 0x11); // TX Buffer - 12063722 to 12063857
  writeRegister(0x46, 0x13); // TX Buffer - 12063871 to 12064013
  writeRegister(0x04, 0x07); // TX - 12064020 to 12064155
  writeRegister(0x00, 0xFF); // CS0 - 12070801 to 12070940
  writeRegister(0x01, 0xFF); // CS1 - 12070951 to 12071092
  writeRegister(0x16, 0xC0); // FIFO CTRL - 12071104 to 12071239
  writeRegister(0x40, 0x04); // TX Buffer - 12071253 to 12071386
  writeRegister(0x41, 0x0E); // TX Buffer - 12071396 to 12071535
  writeRegister(0x44, 0x23); // TX Buffer - 12071545 to 12071683
  writeRegister(0x45, 0x11); // TX Buffer - 12071693 to 12071833
  writeRegister(0x46, 0x13); // TX Buffer - 12071842 to 12071980
  writeRegister(0x04, 0x07); // TX - 12071994 to 12072128
  writeRegister(0x00, 0xFF); // CS0 - 12078772 to 12078911
  writeRegister(0x01, 0xFF); // CS1 - 12078925 to 12079069
  writeRegister(0x16, 0xC0); // FIFO CTRL - 12079076 to 12079218
  writeRegister(0x40, 0x04); // TX Buffer - 12079224 to 12079357
  writeRegister(0x41, 0x0E); // TX Buffer - 12079371 to 12079506
  writeRegister(0x44, 0x23); // TX Buffer - 12079519 to 12079654
  writeRegister(0x45, 0x11); // TX Buffer - 12079668 to 12079804
  writeRegister(0x46, 0x13); // TX Buffer - 12079816 to 12079953
  writeRegister(0x04, 0x07); // TX - 12079965 to 12080099
  writeRegister(0x00, 0xFF); // CS0 - 12086828 to 12086967
  writeRegister(0x01, 0xFF); // CS1 - 12086981 to 12087125
  writeRegister(0x16, 0xC0); // FIFO CTRL - 12087131 to 12087269
  writeRegister(0x40, 0x04); // TX Buffer - 12087280 to 12087413
  writeRegister(0x41, 0x0E); // TX Buffer - 12087427 to 12087561
  writeRegister(0x44, 0x23); // TX Buffer - 12087575 to 12087711
  writeRegister(0x45, 0x11); // TX Buffer - 12087724 to 12087858
  writeRegister(0x46, 0x13); // TX Buffer - 12087872 to 12088007
  writeRegister(0x04, 0x07); // TX - 12088021 to 12088155
  writeRegister(0x00, 0xFF); // CS0 - 12094802 to 12094946
  writeRegister(0x01, 0xFF); // CS1 - 12094952 to 12095092
  writeRegister(0x16, 0xC0); // FIFO CTRL - 12095106 to 12095242
  writeRegister(0x40, 0x04); // TX Buffer - 12095254 to 12095389
  writeRegister(0x41, 0x0E); // TX Buffer - 12095398 to 12095536
  writeRegister(0x44, 0x23); // TX Buffer - 12095546 to 12095684
  writeRegister(0x45, 0x11); // TX Buffer - 12095695 to 12095834
  writeRegister(0x46, 0x13); // TX Buffer - 12095843 to 12095983
  writeRegister(0x04, 0x07); // TX - 12095992 to 12096131
  writeRegister(0x00, 0xFF); // CS0 - 12102773 to 12102914
  writeRegister(0x01, 0xFF); // CS1 - 12102926 to 12103063
  writeRegister(0x16, 0xC0); // FIFO CTRL - 12103077 to 12103212
  writeRegister(0x40, 0x04); // TX Buffer - 12103225 to 12103359
  writeRegister(0x41, 0x0E); // TX Buffer - 12103372 to 12103507
  writeRegister(0x44, 0x23); // TX Buffer - 12103521 to 12103655
  writeRegister(0x45, 0x11); // TX Buffer - 12103669 to 12103805
  writeRegister(0x46, 0x13); // TX Buffer - 12103818 to 12103954
  writeRegister(0x04, 0x07); // TX - 12103967 to 12104102
  writeRegister(0x00, 0xFF); // CS0 - 12110829 to 12110970
  writeRegister(0x01, 0xFF); // CS1 - 12110982 to 12111126
  writeRegister(0x16, 0xC0); // FIFO CTRL - 12111133 to 12111275
  writeRegister(0x40, 0x04); // TX Buffer - 12111281 to 12111414
  writeRegister(0x41, 0x0E); // TX Buffer - 12111428 to 12111563
  writeRegister(0x44, 0x23); // TX Buffer - 12111577 to 12111711
  writeRegister(0x45, 0x11); // TX Buffer - 12111725 to 12111861
  writeRegister(0x46, 0x13); // TX Buffer - 12111873 to 12112010
  writeRegister(0x04, 0x07); // TX - 12112022 to 12112158
  writeRegister(0x00, 0xFF); // CS0 - 12118803 to 12118941
  writeRegister(0x01, 0xFF); // CS1 - 12118953 to 12119093
  writeRegister(0x16, 0xC0); // FIFO CTRL - 12119107 to 12119242
  writeRegister(0x40, 0x04); // TX Buffer - 12119256 to 12119389
  writeRegister(0x41, 0x0E); // TX Buffer - 12119399 to 12119537
  writeRegister(0x44, 0x23); // TX Buffer - 12119548 to 12119690
  writeRegister(0x45, 0x11); // TX Buffer - 12119696 to 12119838
  writeRegister(0x46, 0x13); // TX Buffer - 12119844 to 12119983
  writeRegister(0x04, 0x07); // TX - 12119993 to 12120135
  writeRegister(0x00, 0xFF); // CS0 - 12126774 to 12126914
  writeRegister(0x01, 0xFF); // CS1 - 12126924 to 12127064
  writeRegister(0x16, 0xC0); // FIFO CTRL - 12127078 to 12127213
  writeRegister(0x40, 0x04); // TX Buffer - 12127227 to 12127360
  writeRegister(0x41, 0x0E); // TX Buffer - 12127374 to 12127508
  writeRegister(0x44, 0x23); // TX Buffer - 12127522 to 12127658
  writeRegister(0x45, 0x11); // TX Buffer - 12127671 to 12127805
  writeRegister(0x46, 0x13); // TX Buffer - 12127819 to 12127954
  writeRegister(0x04, 0x07); // TX - 12127968 to 12128102
  writeRegister(0x00, 0xFF); // CS0 - 12134830 to 12134971
  writeRegister(0x01, 0xFF); // CS1 - 12134984 to 12135120
  writeRegister(0x16, 0xC0); // FIFO CTRL - 12135134 to 12135269
  writeRegister(0x40, 0x04); // TX Buffer - 12135282 to 12135416
  writeRegister(0x41, 0x0E); // TX Buffer - 12135429 to 12135564
  writeRegister(0x44, 0x23); // TX Buffer - 12135578 to 12135714
  writeRegister(0x45, 0x11); // TX Buffer - 12135726 to 12135862
  writeRegister(0x46, 0x13); // TX Buffer - 12135875 to 12136011
  writeRegister(0x04, 0x07); // TX - 12136024 to 12136159
  writeRegister(0x00, 0xFF); // CS0 - 12142805 to 12142942
  writeRegister(0x01, 0xFF); // CS1 - 12142955 to 12143096
  writeRegister(0x16, 0xC0); // FIFO CTRL - 12143105 to 12143243
  writeRegister(0x40, 0x04); // TX Buffer - 12143253 to 12143387
  writeRegister(0x41, 0x0E); // TX Buffer - 12143400 to 12143535
  writeRegister(0x44, 0x23); // TX Buffer - 12143549 to 12143685
  writeRegister(0x45, 0x11); // TX Buffer - 12143697 to 12143832
  writeRegister(0x46, 0x13); // TX Buffer - 12143846 to 12143988
  writeRegister(0x04, 0x07); // TX - 12143995 to 12144130
  writeRegister(0x00, 0xFF); // CS0 - 12150776 to 12150915
  writeRegister(0x01, 0xFF); // CS1 - 12150926 to 12151067
  writeRegister(0x16, 0xC0); // FIFO CTRL - 12151080 to 12151214
  writeRegister(0x40, 0x04); // TX Buffer - 12151228 to 12151361
  writeRegister(0x41, 0x0E); // TX Buffer - 12151372 to 12151510
  writeRegister(0x44, 0x23); // TX Buffer - 12151520 to 12151658
  writeRegister(0x45, 0x11); // TX Buffer - 12151668 to 12151808
  writeRegister(0x46, 0x13); // TX Buffer - 12151817 to 12151955
  writeRegister(0x04, 0x07); // TX - 12151969 to 12152103
  writeRegister(0x00, 0xFF); // CS0 - 12158832 to 12158971
  writeRegister(0x01, 0xFF); // CS1 - 12158981 to 12159123
  writeRegister(0x16, 0xC0); // FIFO CTRL - 12159135 to 12159270
  writeRegister(0x40, 0x04); // TX Buffer - 12159284 to 12159417
  writeRegister(0x41, 0x0E); // TX Buffer - 12159431 to 12159565
  writeRegister(0x44, 0x23); // TX Buffer - 12159579 to 12159715
  writeRegister(0x45, 0x11); // TX Buffer - 12159728 to 12159862
  writeRegister(0x46, 0x13); // TX Buffer - 12159876 to 12160011
  writeRegister(0x04, 0x07); // TX - 12160025 to 12160159
  writeRegister(0x00, 0xFF); // CS0 - 12166806 to 12166942
  writeRegister(0x01, 0xFF); // CS1 - 12166956 to 12167097
  writeRegister(0x16, 0xC0); // FIFO CTRL - 12167106 to 12167244
  writeRegister(0x40, 0x04); // TX Buffer - 12167255 to 12167388
  writeRegister(0x41, 0x0E); // TX Buffer - 12167402 to 12167538
  writeRegister(0x44, 0x23); // TX Buffer - 12167550 to 12167686
  writeRegister(0x45, 0x11); // TX Buffer - 12167699 to 12167833
  writeRegister(0x46, 0x13); // TX Buffer - 12167847 to 12167982
  writeRegister(0x04, 0x07); // TX - 12167996 to 12168130
  writeRegister(0x00, 0xFF); // CS0 - 12174777 to 12174921
  writeRegister(0x01, 0xFF); // CS1 - 12174927 to 12175067
  writeRegister(0x16, 0xC0); // FIFO CTRL - 12175081 to 12175217
  writeRegister(0x40, 0x04); // TX Buffer - 12175229 to 12175364
  writeRegister(0x41, 0x0E); // TX Buffer - 12175373 to 12175511
  writeRegister(0x44, 0x23); // TX Buffer - 12175521 to 12175659
  writeRegister(0x45, 0x11); // TX Buffer - 12175670 to 12175809
  writeRegister(0x46, 0x13); // TX Buffer - 12175818 to 12175958
  writeRegister(0x04, 0x07); // TX - 12175967 to 12176106
  writeRegister(0x00, 0xFF); // CS0 - 12182833 to 12182972
  writeRegister(0x01, 0xFF); // CS1 - 12182983 to 12183124
  writeRegister(0x16, 0xC0); // FIFO CTRL - 12183137 to 12183271
  writeRegister(0x40, 0x04); // TX Buffer - 12183285 to 12183418
  writeRegister(0x41, 0x0E); // TX Buffer - 12183429 to 12183567
  writeRegister(0x44, 0x23); // TX Buffer - 12183577 to 12183715
  writeRegister(0x45, 0x11); // TX Buffer - 12183726 to 12183865
  writeRegister(0x46, 0x13); // TX Buffer - 12183874 to 12184014
  writeRegister(0x04, 0x07); // TX - 12184026 to 12184162
  writeRegister(0x00, 0xFF); // CS0 - 12190804 to 12190945
  writeRegister(0x01, 0xFF); // CS1 - 12190957 to 12191101
  writeRegister(0x16, 0xC0); // FIFO CTRL - 12191108 to 12191246
  writeRegister(0x40, 0x04); // TX Buffer - 12191256 to 12191389
  writeRegister(0x41, 0x0E); // TX Buffer - 12191403 to 12191538
  writeRegister(0x44, 0x23); // TX Buffer - 12191552 to 12191686
  writeRegister(0x45, 0x11); // TX Buffer - 12191700 to 12191836
  writeRegister(0x46, 0x13); // TX Buffer - 12191848 to 12191985
  writeRegister(0x04, 0x07); // TX - 12191997 to 12192133
  writeRegister(0x00, 0xFF); // CS0 - 12198778 to 12198922
  writeRegister(0x01, 0xFF); // CS1 - 12198928 to 12199068
  writeRegister(0x16, 0xC0); // FIFO CTRL - 12199082 to 12199217
  writeRegister(0x40, 0x04); // TX Buffer - 12199231 to 12199364
  writeRegister(0x41, 0x0E); // TX Buffer - 12199374 to 12199512
  writeRegister(0x44, 0x23); // TX Buffer - 12199523 to 12199665
  writeRegister(0x45, 0x11); // TX Buffer - 12199671 to 12199813
  writeRegister(0x46, 0x13); // TX Buffer - 12199820 to 12199958
  writeRegister(0x04, 0x07); // TX - 12199968 to 12200110
  writeRegister(0x00, 0xFF); // CS0 - 12206834 to 12206978
  writeRegister(0x01, 0xFF); // CS1 - 12206984 to 12207124
  writeRegister(0x16, 0xC0); // FIFO CTRL - 12207138 to 12207273
  writeRegister(0x40, 0x04); // TX Buffer - 12207286 to 12207420
  writeRegister(0x41, 0x0E); // TX Buffer - 12207430 to 12207568
  writeRegister(0x44, 0x23); // TX Buffer - 12207578 to 12207718
  writeRegister(0x45, 0x11); // TX Buffer - 12207727 to 12207866
  writeRegister(0x46, 0x13); // TX Buffer - 12207875 to 12208015
  writeRegister(0x04, 0x07); // TX - 12208024 to 12208163
  writeRegister(0x00, 0xFF); // CS0 - 12214805 to 12214946
  writeRegister(0x01, 0xFF); // CS1 - 12214959 to 12215095
  writeRegister(0x16, 0xC0); // FIFO CTRL - 12215109 to 12215244
  writeRegister(0x40, 0x04); // TX Buffer - 12215257 to 12215391
  writeRegister(0x41, 0x0E); // TX Buffer - 12215404 to 12215539
  writeRegister(0x44, 0x23); // TX Buffer - 12215553 to 12215689
  writeRegister(0x45, 0x11); // TX Buffer - 12215701 to 12215837
  writeRegister(0x46, 0x13); // TX Buffer - 12215850 to 12215986
  writeRegister(0x04, 0x07); // TX - 12215999 to 12216134
  writeRegister(0x00, 0xFF); // CS0 - 12222780 to 12222917
  writeRegister(0x01, 0xFF); // CS1 - 12222930 to 12223071
  writeRegister(0x16, 0xC0); // FIFO CTRL - 12223080 to 12223218
  writeRegister(0x40, 0x04); // TX Buffer - 12223229 to 12223368
  writeRegister(0x41, 0x0E); // TX Buffer - 12223375 to 12223518
  writeRegister(0x44, 0x23); // TX Buffer - 12223524 to 12223666
  writeRegister(0x45, 0x11); // TX Buffer - 12223672 to 12223815
  writeRegister(0x46, 0x13); // TX Buffer - 12223821 to 12223963
  writeRegister(0x04, 0x07); // TX - 12223970 to 12224111
  writeRegister(0x00, 0xFF); // CS0 - 12230836 to 12230979
  writeRegister(0x01, 0xFF); // CS1 - 12230985 to 12231127
  writeRegister(0x16, 0xC0); // FIFO CTRL - 12231139 to 12231274
  writeRegister(0x40, 0x04); // TX Buffer - 12231288 to 12231421
  writeRegister(0x41, 0x0E); // TX Buffer - 12231431 to 12231569
  writeRegister(0x44, 0x23); // TX Buffer - 12231580 to 12231722
  writeRegister(0x45, 0x11); // TX Buffer - 12231728 to 12231870
  writeRegister(0x46, 0x13); // TX Buffer - 12231877 to 12232015
  writeRegister(0x04, 0x07); // TX - 12232026 to 12232167
  writeRegister(0x00, 0xFF); // CS0 - 12238807 to 12238946
  writeRegister(0x01, 0xFF); // CS1 - 12238960 to 12239098
  writeRegister(0x16, 0xC0); // FIFO CTRL - 12239110 to 12239245
  writeRegister(0x40, 0x04); // TX Buffer - 12239259 to 12239392
  writeRegister(0x41, 0x0E); // TX Buffer - 12239406 to 12239540
  writeRegister(0x44, 0x23); // TX Buffer - 12239554 to 12239690
  writeRegister(0x45, 0x11); // TX Buffer - 12239703 to 12239837
  writeRegister(0x46, 0x13); // TX Buffer - 12239851 to 12239986
  writeRegister(0x04, 0x07); // TX - 12240000 to 12240134
  writeRegister(0x00, 0xFF); // CS0 - 12246781 to 12246917
  writeRegister(0x01, 0xFF); // CS1 - 12246931 to 12247071
  writeRegister(0x16, 0xC0); // FIFO CTRL - 12247081 to 12247221
  writeRegister(0x40, 0x04); // TX Buffer - 12247230 to 12247363
  writeRegister(0x41, 0x0E); // TX Buffer - 12247377 to 12247513
  writeRegister(0x44, 0x23); // TX Buffer - 12247525 to 12247661
  writeRegister(0x45, 0x11); // TX Buffer - 12247674 to 12247808
  writeRegister(0x46, 0x13); // TX Buffer - 12247822 to 12247965
  writeRegister(0x04, 0x07); // TX - 12247971 to 12248105
  writeRegister(0x00, 0xFF); // CS0 - 12254837 to 12254974
  writeRegister(0x01, 0xFF); // CS1 - 12254987 to 12255128
  writeRegister(0x16, 0xC0); // FIFO CTRL - 12255137 to 12255275
  writeRegister(0x40, 0x04); // TX Buffer - 12255286 to 12255425
  writeRegister(0x41, 0x0E); // TX Buffer - 12255433 to 12255575
  writeRegister(0x44, 0x23); // TX Buffer - 12255581 to 12255723
  writeRegister(0x45, 0x11); // TX Buffer - 12255729 to 12255872
  writeRegister(0x46, 0x13); // TX Buffer - 12255878 to 12256021
  writeRegister(0x04, 0x07); // TX - 12256027 to 12256169
  writeRegister(0x00, 0xFF); // CS0 - 12262808 to 12262949
  writeRegister(0x01, 0xFF); // CS1 - 12262958 to 12263099
  writeRegister(0x16, 0xC0); // FIFO CTRL - 12263112 to 12263246
  writeRegister(0x40, 0x04); // TX Buffer - 12263260 to 12263393
  writeRegister(0x41, 0x0E); // TX Buffer - 12263407 to 12263542
  writeRegister(0x44, 0x23); // TX Buffer - 12263556 to 12263690
  writeRegister(0x45, 0x11); // TX Buffer - 12263704 to 12263840
  writeRegister(0x46, 0x13); // TX Buffer - 12263852 to 12263989
  writeRegister(0x04, 0x07); // TX - 12264001 to 12264137
  writeRegister(0x00, 0xFF); // CS0 - 12270779 to 12270920
  writeRegister(0x01, 0xFF); // CS1 - 12270932 to 12271076
  writeRegister(0x16, 0xC0); // FIFO CTRL - 12271083 to 12271221
  writeRegister(0x40, 0x04); // TX Buffer - 12271231 to 12271364
  writeRegister(0x41, 0x0E); // TX Buffer - 12271378 to 12271513
  writeRegister(0x44, 0x23); // TX Buffer - 12271527 to 12271661
  writeRegister(0x45, 0x11); // TX Buffer - 12271675 to 12271811
  writeRegister(0x46, 0x13); // TX Buffer - 12271823 to 12271960
  writeRegister(0x04, 0x07); // TX - 12271972 to 12272108
  writeRegister(0x00, 0xFF); // CS0 - 12278838 to 12278974
  writeRegister(0x01, 0xFF); // CS1 - 12278988 to 12279128
  writeRegister(0x16, 0xC0); // FIFO CTRL - 12279138 to 12279277
  writeRegister(0x40, 0x04); // TX Buffer - 12279287 to 12279420
  writeRegister(0x41, 0x0E); // TX Buffer - 12279434 to 12279569
  writeRegister(0x44, 0x23); // TX Buffer - 12279582 to 12279717
  writeRegister(0x45, 0x11); // TX Buffer - 12279731 to 12279867
  writeRegister(0x46, 0x13); // TX Buffer - 12279879 to 12280022
  writeRegister(0x04, 0x07); // TX - 12280028 to 12280162
  writeRegister(0x00, 0xFF); // CS0 - 12286809 to 12286950
  writeRegister(0x01, 0xFF); // CS1 - 12286959 to 12287099
  writeRegister(0x16, 0xC0); // FIFO CTRL - 12287113 to 12287248
  writeRegister(0x40, 0x04); // TX Buffer - 12287261 to 12287395
  writeRegister(0x41, 0x0E); // TX Buffer - 12287405 to 12287543
  writeRegister(0x44, 0x23); // TX Buffer - 12287553 to 12287693
  writeRegister(0x45, 0x11); // TX Buffer - 12287702 to 12287841
  writeRegister(0x46, 0x13); // TX Buffer - 12287850 to 12287990
  writeRegister(0x04, 0x07); // TX - 12288003 to 12288138
  writeRegister(0x00, 0xFF); // CS0 - 12294780 to 12294921
  writeRegister(0x01, 0xFF); // CS1 - 12294934 to 12295078
  writeRegister(0x16, 0xC0); // FIFO CTRL - 12295084 to 12295225
  writeRegister(0x40, 0x04); // TX Buffer - 12295232 to 12295366
  writeRegister(0x41, 0x0E); // TX Buffer - 12295379 to 12295514
  writeRegister(0x44, 0x23); // TX Buffer - 12295528 to 12295664
  writeRegister(0x45, 0x11); // TX Buffer - 12295676 to 12295811
  writeRegister(0x46, 0x13); // TX Buffer - 12295825 to 12295961
  writeRegister(0x04, 0x07); // TX - 12295974 to 12296109
  writeRegister(0x00, 0xFF); // CS0 - 12302836 to 12302977
  writeRegister(0x01, 0xFF); // CS1 - 12302989 to 12303132
  writeRegister(0x16, 0xC0); // FIFO CTRL - 12303140 to 12303278
  writeRegister(0x40, 0x04); // TX Buffer - 12303288 to 12303423
  writeRegister(0x41, 0x0E); // TX Buffer - 12303435 to 12303570
  writeRegister(0x44, 0x23); // TX Buffer - 12303584 to 12303718
  writeRegister(0x45, 0x11); // TX Buffer - 12303732 to 12303868
  writeRegister(0x46, 0x13); // TX Buffer - 12303881 to 12304017
  writeRegister(0x04, 0x07); // TX - 12304030 to 12304165
  writeRegister(0x00, 0xFF); // CS0 - 12310811 to 12310954
  writeRegister(0x01, 0xFF); // CS1 - 12310960 to 12311102
  writeRegister(0x16, 0xC0); // FIFO CTRL - 12311114 to 12311249
  writeRegister(0x40, 0x04); // TX Buffer - 12311263 to 12311396
  writeRegister(0x41, 0x0E); // TX Buffer - 12311406 to 12311544
  writeRegister(0x44, 0x23); // TX Buffer - 12311555 to 12311694
  writeRegister(0x45, 0x11); // TX Buffer - 12311703 to 12311841
  writeRegister(0x46, 0x13); // TX Buffer - 12311852 to 12311990
  writeRegister(0x04, 0x07); // TX - 12312001 to 12312138
  writeRegister(0x00, 0xFF); // CS0 - 12318782 to 12318921
  writeRegister(0x01, 0xFF); // CS1 - 12318935 to 12319073
  writeRegister(0x16, 0xC0); // FIFO CTRL - 12319085 to 12319220
  writeRegister(0x40, 0x04); // TX Buffer - 12319234 to 12319367
  writeRegister(0x41, 0x0E); // TX Buffer - 12319381 to 12319515
  writeRegister(0x44, 0x23); // TX Buffer - 12319529 to 12319665
  writeRegister(0x45, 0x11); // TX Buffer - 12319678 to 12319812
  writeRegister(0x46, 0x13); // TX Buffer - 12319826 to 12319961
  writeRegister(0x04, 0x07); // TX - 12319975 to 12320109
  writeRegister(0x00, 0xFF); // CS0 - 12326837 to 12326978
  writeRegister(0x01, 0xFF); // CS1 - 12326991 to 12327135
  writeRegister(0x16, 0xC0); // FIFO CTRL - 12327141 to 12327282
  writeRegister(0x40, 0x04); // TX Buffer - 12327290 to 12327423
  writeRegister(0x41, 0x0E); // TX Buffer - 12327437 to 12327571
  writeRegister(0x44, 0x23); // TX Buffer - 12327585 to 12327721
  writeRegister(0x45, 0x11); // TX Buffer - 12327733 to 12327868
  writeRegister(0x46, 0x13); // TX Buffer - 12327882 to 12328017
  writeRegister(0x04, 0x07); // TX - 12328031 to 12328165
  writeRegister(0x00, 0xFF); // CS0 - 12334812 to 12334948
  writeRegister(0x01, 0xFF); // CS1 - 12334962 to 12335103
  writeRegister(0x16, 0xC0); // FIFO CTRL - 12335116 to 12335250
  writeRegister(0x40, 0x04); // TX Buffer - 12335264 to 12335397
  writeRegister(0x41, 0x0E); // TX Buffer - 12335408 to 12335546
  writeRegister(0x44, 0x23); // TX Buffer - 12335556 to 12335698
  writeRegister(0x45, 0x11); // TX Buffer - 12335705 to 12335847
  writeRegister(0x46, 0x13); // TX Buffer - 12335853 to 12335993
  writeRegister(0x04, 0x07); // TX - 12336002 to 12336144
  writeRegister(0x00, 0xFF); // CS0 - 12342783 to 12342924
  writeRegister(0x01, 0xFF); // CS1 - 12342933 to 12343074
  writeRegister(0x16, 0xC0); // FIFO CTRL - 12343087 to 12343221
  writeRegister(0x40, 0x04); // TX Buffer - 12343235 to 12343368
  writeRegister(0x41, 0x0E); // TX Buffer - 12343382 to 12343517
  writeRegister(0x44, 0x23); // TX Buffer - 12343531 to 12343665
  writeRegister(0x45, 0x11); // TX Buffer - 12343679 to 12343815
  writeRegister(0x46, 0x13); // TX Buffer - 12343827 to 12343964
  writeRegister(0x04, 0x07); // TX - 12343976 to 12344112
  writeRegister(0x00, 0xFF); // CS0 - 12350839 to 12350978
  writeRegister(0x01, 0xFF); // CS1 - 12350992 to 12351130
  writeRegister(0x16, 0xC0); // FIFO CTRL - 12351142 to 12351277
  writeRegister(0x40, 0x04); // TX Buffer - 12351291 to 12351424
  writeRegister(0x41, 0x0E); // TX Buffer - 12351438 to 12351573
  writeRegister(0x44, 0x23); // TX Buffer - 12351586 to 12351721
  writeRegister(0x45, 0x11); // TX Buffer - 12351735 to 12351871
  writeRegister(0x46, 0x13); // TX Buffer - 12351883 to 12352018
  writeRegister(0x04, 0x07); // TX - 12352032 to 12352166
  writeRegister(0x00, 0xFF); // CS0 - 12358813 to 12358949
  writeRegister(0x01, 0xFF); // CS1 - 12358963 to 12359103
  writeRegister(0x16, 0xC0); // FIFO CTRL - 12359114 to 12359252
  writeRegister(0x40, 0x04); // TX Buffer - 12359262 to 12359395
  writeRegister(0x41, 0x0E); // TX Buffer - 12359409 to 12359544
  writeRegister(0x44, 0x23); // TX Buffer - 12359557 to 12359692
  writeRegister(0x45, 0x11); // TX Buffer - 12359706 to 12359842
  writeRegister(0x46, 0x13); // TX Buffer - 12359854 to 12359997
  writeRegister(0x04, 0x07); // TX - 12360003 to 12360137
  writeRegister(0x00, 0xFF); // CS0 - 12366784 to 12366925
  writeRegister(0x01, 0xFF); // CS1 - 12366934 to 12367074
  writeRegister(0x16, 0xC0); // FIFO CTRL - 12367088 to 12367223
  writeRegister(0x40, 0x04); // TX Buffer - 12367236 to 12367370
  writeRegister(0x41, 0x0E); // TX Buffer - 12367380 to 12367518
  writeRegister(0x44, 0x23); // TX Buffer - 12367528 to 12367668
  writeRegister(0x45, 0x11); // TX Buffer - 12367677 to 12367816
  writeRegister(0x46, 0x13); // TX Buffer - 12367825 to 12367965
  writeRegister(0x04, 0x07); // TX - 12367978 to 12368113
  writeRegister(0x00, 0xFF); // CS0 - 12374840 to 12374981
  writeRegister(0x01, 0xFF); // CS1 - 12374990 to 12375130
  writeRegister(0x16, 0xC0); // FIFO CTRL - 12375144 to 12375278
  writeRegister(0x40, 0x04); // TX Buffer - 12375292 to 12375425
  writeRegister(0x41, 0x0E); // TX Buffer - 12375439 to 12375574
  writeRegister(0x44, 0x23); // TX Buffer - 12375588 to 12375722
  writeRegister(0x45, 0x11); // TX Buffer - 12375736 to 12375872
  writeRegister(0x46, 0x13); // TX Buffer - 12375885 to 12376021
  writeRegister(0x04, 0x07); // TX - 12376033 to 12376169
  writeRegister(0x00, 0xFF); // CS0 - 12382815 to 12382952
  writeRegister(0x01, 0xFF); // CS1 - 12382964 to 12383106
  writeRegister(0x16, 0xC0); // FIFO CTRL - 12383115 to 12383253
  writeRegister(0x40, 0x04); // TX Buffer - 12383263 to 12383398
  writeRegister(0x41, 0x0E); // TX Buffer - 12383410 to 12383545
  writeRegister(0x44, 0x23); // TX Buffer - 12383559 to 12383693
  writeRegister(0x45, 0x11); // TX Buffer - 12383707 to 12383843
  writeRegister(0x46, 0x13); // TX Buffer - 12383856 to 12383992
  writeRegister(0x04, 0x07); // TX - 12384005 to 12384140
  writeRegister(0x00, 0xFF); // CS0 - 12390786 to 12390929
  writeRegister(0x01, 0xFF); // CS1 - 12390935 to 12391077
  writeRegister(0x16, 0xC0); // FIFO CTRL - 12391089 to 12391224
  writeRegister(0x40, 0x04); // TX Buffer - 12391238 to 12391371
  writeRegister(0x41, 0x0E); // TX Buffer - 12391381 to 12391519
  writeRegister(0x44, 0x23); // TX Buffer - 12391530 to 12391669
  writeRegister(0x45, 0x11); // TX Buffer - 12391678 to 12391816
  writeRegister(0x46, 0x13); // TX Buffer - 12391827 to 12391965
  writeRegister(0x04, 0x07); // TX - 12391976 to 12392113
  writeRegister(0x00, 0xFF); // CS0 - 12398841 to 12398982
  writeRegister(0x01, 0xFF); // CS1 - 12398991 to 12399131
  writeRegister(0x16, 0xC0); // FIFO CTRL - 12399145 to 12399280
  writeRegister(0x40, 0x04); // TX Buffer - 12399294 to 12399427
  writeRegister(0x41, 0x0E); // TX Buffer - 12399437 to 12399575
  writeRegister(0x44, 0x23); // TX Buffer - 12399586 to 12399725
  writeRegister(0x45, 0x11); // TX Buffer - 12399734 to 12399872
  writeRegister(0x46, 0x13); // TX Buffer - 12399882 to 12400021
  writeRegister(0x04, 0x07); // TX - 12400035 to 12400169
  writeRegister(0x00, 0xFF); // CS0 - 12406812 to 12406953
  writeRegister(0x01, 0xFF); // CS1 - 12406966 to 12407110
  writeRegister(0x16, 0xC0); // FIFO CTRL - 12407116 to 12407254
  writeRegister(0x40, 0x04); // TX Buffer - 12407265 to 12407398
  writeRegister(0x41, 0x0E); // TX Buffer - 12407412 to 12407546
  writeRegister(0x44, 0x23); // TX Buffer - 12407560 to 12407696
  writeRegister(0x45, 0x11); // TX Buffer - 12407708 to 12407843
  writeRegister(0x46, 0x13); // TX Buffer - 12407857 to 12407992
  writeRegister(0x04, 0x07); // TX - 12408006 to 12408140
  writeRegister(0x00, 0xFF); // CS0 - 12414787 to 12414931
  writeRegister(0x01, 0xFF); // CS1 - 12414937 to 12415078
  writeRegister(0x16, 0xC0); // FIFO CTRL - 12415091 to 12415225
  writeRegister(0x40, 0x04); // TX Buffer - 12415239 to 12415372
  writeRegister(0x41, 0x0E); // TX Buffer - 12415383 to 12415521
  writeRegister(0x44, 0x23); // TX Buffer - 12415531 to 12415673
  writeRegister(0x45, 0x11); // TX Buffer - 12415680 to 12415822
  writeRegister(0x46, 0x13); // TX Buffer - 12415828 to 12415968
  writeRegister(0x04, 0x07); // TX - 12415977 to 12416119
  writeRegister(0x00, 0xFF); // CS0 - 12422843 to 12422986
  writeRegister(0x01, 0xFF); // CS1 - 12422993 to 12423134
  writeRegister(0x16, 0xC0); // FIFO CTRL - 12423146 to 12423281
  writeRegister(0x40, 0x04); // TX Buffer - 12423295 to 12423428
  writeRegister(0x41, 0x0E); // TX Buffer - 12423438 to 12423577
  writeRegister(0x44, 0x23); // TX Buffer - 12423587 to 12423726
  writeRegister(0x45, 0x11); // TX Buffer - 12423735 to 12423873
  writeRegister(0x46, 0x13); // TX Buffer - 12423884 to 12424022
  writeRegister(0x04, 0x07); // TX - 12424033 to 12424170
  writeRegister(0x00, 0xFF); // CS0 - 12430814 to 12430953
  writeRegister(0x01, 0xFF); // CS1 - 12430967 to 12431105
  writeRegister(0x16, 0xC0); // FIFO CTRL - 12431117 to 12431252
  writeRegister(0x40, 0x04); // TX Buffer - 12431266 to 12431399
  writeRegister(0x41, 0x0E); // TX Buffer - 12431413 to 12431548
  writeRegister(0x44, 0x23); // TX Buffer - 12431561 to 12431696
  writeRegister(0x45, 0x11); // TX Buffer - 12431710 to 12431846
  writeRegister(0x46, 0x13); // TX Buffer - 12431858 to 12431993
  writeRegister(0x04, 0x07); // TX - 12432007 to 12432141
  writeRegister(0x00, 0xFF); // CS0 - 12438788 to 12438924
  writeRegister(0x01, 0xFF); // CS1 - 12438938 to 12439078
  writeRegister(0x16, 0xC0); // FIFO CTRL - 12439089 to 12439227
  writeRegister(0x40, 0x04); // TX Buffer - 12439237 to 12439378
  writeRegister(0x41, 0x0E); // TX Buffer - 12439384 to 12439525
  writeRegister(0x44, 0x23); // TX Buffer - 12439532 to 12439675
  writeRegister(0x45, 0x11); // TX Buffer - 12439681 to 12439823
  writeRegister(0x46, 0x13); // TX Buffer - 12439829 to 12439972
  writeRegister(0x04, 0x07); // TX - 12439978 to 12440120
  writeRegister(0x00, 0xFF); // CS0 - 12446844 to 12446988
  writeRegister(0x01, 0xFF); // CS1 - 12446994 to 12447135
  writeRegister(0x16, 0xC0); // FIFO CTRL - 12447148 to 12447282
  writeRegister(0x40, 0x04); // TX Buffer - 12447296 to 12447429
  writeRegister(0x41, 0x0E); // TX Buffer - 12447440 to 12447578
  writeRegister(0x44, 0x23); // TX Buffer - 12447588 to 12447730
  writeRegister(0x45, 0x11); // TX Buffer - 12447737 to 12447879
  writeRegister(0x46, 0x13); // TX Buffer - 12447885 to 12448025
  writeRegister(0x04, 0x07); // TX - 12448034 to 12448176
  writeRegister(0x00, 0xFF); // CS0 - 12454815 to 12454956
  writeRegister(0x01, 0xFF); // CS1 - 12454968 to 12455105
  writeRegister(0x16, 0xC0); // FIFO CTRL - 12455119 to 12455255
  writeRegister(0x40, 0x04); // TX Buffer - 12455267 to 12455402
  writeRegister(0x41, 0x0E); // TX Buffer - 12455414 to 12455549
  writeRegister(0x44, 0x23); // TX Buffer - 12455563 to 12455697
  writeRegister(0x45, 0x11); // TX Buffer - 12455711 to 12455847
  writeRegister(0x46, 0x13); // TX Buffer - 12455860 to 12455996
  writeRegister(0x04, 0x07); // TX - 12456009 to 12456144
  writeRegister(0x00, 0xFF); // CS0 - 12462790 to 12462927
  writeRegister(0x01, 0xFF); // CS1 - 12462939 to 12463081
  writeRegister(0x16, 0xC0); // FIFO CTRL - 12463090 to 12463228
  writeRegister(0x40, 0x04); // TX Buffer - 12463238 to 12463372
  writeRegister(0x41, 0x0E); // TX Buffer - 12463385 to 12463520
  writeRegister(0x44, 0x23); // TX Buffer - 12463534 to 12463668
  writeRegister(0x45, 0x11); // TX Buffer - 12463682 to 12463818
  writeRegister(0x46, 0x13); // TX Buffer - 12463831 to 12463973
  writeRegister(0x04, 0x07); // TX - 12463980 to 12464115
  writeRegister(0x00, 0xFF); // CS0 - 12470845 to 12470983
  writeRegister(0x01, 0xFF); // CS1 - 12470995 to 12471135
  writeRegister(0x16, 0xC0); // FIFO CTRL - 12471146 to 12471284
  writeRegister(0x40, 0x04); // TX Buffer - 12471294 to 12471435
  writeRegister(0x41, 0x0E); // TX Buffer - 12471441 to 12471582
  writeRegister(0x44, 0x23); // TX Buffer - 12471590 to 12471732
  writeRegister(0x45, 0x11); // TX Buffer - 12471738 to 12471880
  writeRegister(0x46, 0x13); // TX Buffer - 12471886 to 12472029
  writeRegister(0x04, 0x07); // TX - 12472035 to 12472177
  writeRegister(0x00, 0xFF); // CS0 - 12478816 to 12478957
  writeRegister(0x01, 0xFF); // CS1 - 12478966 to 12479106
  writeRegister(0x16, 0xC0); // FIFO CTRL - 12479120 to 12479255
  writeRegister(0x40, 0x04); // TX Buffer - 12479269 to 12479402
  writeRegister(0x41, 0x0E); // TX Buffer - 12479416 to 12479550
  writeRegister(0x44, 0x23); // TX Buffer - 12479564 to 12479700
  writeRegister(0x45, 0x11); // TX Buffer - 12479712 to 12479847
  writeRegister(0x46, 0x13); // TX Buffer - 12479861 to 12479996
  writeRegister(0x04, 0x07); // TX - 12480010 to 12480144
  writeRegister(0x00, 0xFF); // CS0 - 12486787 to 12486927
  writeRegister(0x01, 0xFF); // CS1 - 12486941 to 12487085
  writeRegister(0x16, 0xC0); // FIFO CTRL - 12487091 to 12487229
  writeRegister(0x40, 0x04); // TX Buffer - 12487240 to 12487373
  writeRegister(0x41, 0x0E); // TX Buffer - 12487387 to 12487521
  writeRegister(0x44, 0x23); // TX Buffer - 12487535 to 12487671
  writeRegister(0x45, 0x11); // TX Buffer - 12487684 to 12487818
  writeRegister(0x46, 0x13); // TX Buffer - 12487832 to 12487967
  writeRegister(0x04, 0x07); // TX - 12487981 to 12488115
  writeRegister(0x00, 0xFF); // CS0 - 12494847 to 12494984
  writeRegister(0x01, 0xFF); // CS1 - 12494997 to 12495138
  writeRegister(0x16, 0xC0); // FIFO CTRL - 12495147 to 12495285
  writeRegister(0x40, 0x04); // TX Buffer - 12495295 to 12495429
  writeRegister(0x41, 0x0E); // TX Buffer - 12495442 to 12495577
  writeRegister(0x44, 0x23); // TX Buffer - 12495591 to 12495727
  writeRegister(0x45, 0x11); // TX Buffer - 12495739 to 12495875
  writeRegister(0x46, 0x13); // TX Buffer - 12495888 to 12496030
  writeRegister(0x04, 0x07); // TX - 12496037 to 12496172
  writeRegister(0x00, 0xFF); // CS0 - 12502818 to 12502957
  writeRegister(0x01, 0xFF); // CS1 - 12502968 to 12503109
  writeRegister(0x16, 0xC0); // FIFO CTRL - 12503121 to 12503256
  writeRegister(0x40, 0x04); // TX Buffer - 12503270 to 12503403
  writeRegister(0x41, 0x0E); // TX Buffer - 12503413 to 12503552
  writeRegister(0x44, 0x23); // TX Buffer - 12503562 to 12503700
  writeRegister(0x45, 0x11); // TX Buffer - 12503710 to 12503850
  writeRegister(0x46, 0x13); // TX Buffer - 12503859 to 12503997
  writeRegister(0x04, 0x07); // TX - 12504011 to 12504145
  writeRegister(0x00, 0xFF); // CS0 - 12510789 to 12510928
  writeRegister(0x01, 0xFF); // CS1 - 12510942 to 12511086
  writeRegister(0x16, 0xC0); // FIFO CTRL - 12511093 to 12511235
  writeRegister(0x40, 0x04); // TX Buffer - 12511241 to 12511374
  writeRegister(0x41, 0x0E); // TX Buffer - 12511388 to 12511523
  writeRegister(0x44, 0x23); // TX Buffer - 12511536 to 12511671
  writeRegister(0x45, 0x11); // TX Buffer - 12511685 to 12511821
  writeRegister(0x46, 0x13); // TX Buffer - 12511833 to 12511968
  writeRegister(0x04, 0x07); // TX - 12511982 to 12512116
  writeRegister(0x00, 0xFF); // CS0 - 12518845 to 12518984
  writeRegister(0x01, 0xFF); // CS1 - 12518998 to 12519142
  writeRegister(0x16, 0xC0); // FIFO CTRL - 12519148 to 12519286
  writeRegister(0x40, 0x04); // TX Buffer - 12519297 to 12519430
  writeRegister(0x41, 0x0E); // TX Buffer - 12519444 to 12519578
  writeRegister(0x44, 0x23); // TX Buffer - 12519592 to 12519728
  writeRegister(0x45, 0x11); // TX Buffer - 12519741 to 12519875
  writeRegister(0x46, 0x13); // TX Buffer - 12519889 to 12520024
  writeRegister(0x04, 0x07); // TX - 12520038 to 12520172
  writeRegister(0x00, 0xFF); // CS0 - 12526819 to 12526963
  writeRegister(0x01, 0xFF); // CS1 - 12526969 to 12527110
  writeRegister(0x16, 0xC0); // FIFO CTRL - 12527123 to 12527257
  writeRegister(0x40, 0x04); // TX Buffer - 12527271 to 12527404
  writeRegister(0x41, 0x0E); // TX Buffer - 12527415 to 12527553
  writeRegister(0x44, 0x23); // TX Buffer - 12527563 to 12527701
  writeRegister(0x45, 0x11); // TX Buffer - 12527712 to 12527851
  writeRegister(0x46, 0x13); // TX Buffer - 12527860 to 12528000
  writeRegister(0x04, 0x07); // TX - 12528009 to 12528148
  writeRegister(0x00, 0xFF); // CS0 - 12534790 to 12534931
  writeRegister(0x01, 0xFF); // CS1 - 12534943 to 12535080
  writeRegister(0x16, 0xC0); // FIFO CTRL - 12535094 to 12535230
  writeRegister(0x40, 0x04); // TX Buffer - 12535242 to 12535377
  writeRegister(0x41, 0x0E); // TX Buffer - 12535389 to 12535524
  writeRegister(0x44, 0x23); // TX Buffer - 12535538 to 12535672
  writeRegister(0x45, 0x11); // TX Buffer - 12535686 to 12535822
  writeRegister(0x46, 0x13); // TX Buffer - 12535835 to 12535971
  writeRegister(0x04, 0x07); // TX - 12535984 to 12536119
  writeRegister(0x00, 0xFF); // CS0 - 12542846 to 12542985
  writeRegister(0x01, 0xFF); // CS1 - 12542999 to 12543143
  writeRegister(0x16, 0xC0); // FIFO CTRL - 12543150 to 12543292
  writeRegister(0x40, 0x04); // TX Buffer - 12543298 to 12543431
  writeRegister(0x41, 0x0E); // TX Buffer - 12543445 to 12543580
  writeRegister(0x44, 0x23); // TX Buffer - 12543594 to 12543728
  writeRegister(0x45, 0x11); // TX Buffer - 12543742 to 12543878
  writeRegister(0x46, 0x13); // TX Buffer - 12543890 to 12544027
  writeRegister(0x04, 0x07); // TX - 12544039 to 12544175
  writeRegister(0x00, 0xFF); // CS0 - 12550820 to 12550958
  writeRegister(0x01, 0xFF); // CS1 - 12550970 to 12551110
  writeRegister(0x16, 0xC0); // FIFO CTRL - 12551124 to 12551259
  writeRegister(0x40, 0x04); // TX Buffer - 12551273 to 12551406
  writeRegister(0x41, 0x0E); // TX Buffer - 12551416 to 12551554
  writeRegister(0x44, 0x23); // TX Buffer - 12551565 to 12551707
  writeRegister(0x45, 0x11); // TX Buffer - 12551713 to 12551855
  writeRegister(0x46, 0x13); // TX Buffer - 12551861 to 12552000
  writeRegister(0x04, 0x07); // TX - 12552010 to 12552152
  writeRegister(0x00, 0xFF); // CS0 - 12558876 to 12559020
  writeRegister(0x01, 0xFF); // CS1 - 12559026 to 12559166
  writeRegister(0x16, 0xC0); // FIFO CTRL - 12559180 to 12559315
  writeRegister(0x40, 0x04); // TX Buffer - 12559328 to 12559462
  writeRegister(0x41, 0x0E); // TX Buffer - 12559472 to 12559610
  writeRegister(0x44, 0x23); // TX Buffer - 12559620 to 12559758
  writeRegister(0x45, 0x11); // TX Buffer - 12559769 to 12559908
  writeRegister(0x46, 0x13); // TX Buffer - 12559917 to 12560057
  writeRegister(0x04, 0x07); // TX - 12560066 to 12560205
  writeRegister(0x00, 0xFF); // CS0 - 12566847 to 12566988
  writeRegister(0x01, 0xFF); // CS1 - 12567001 to 12567137
  writeRegister(0x16, 0xC0); // FIFO CTRL - 12567151 to 12567286
  writeRegister(0x40, 0x04); // TX Buffer - 12567299 to 12567433
  writeRegister(0x41, 0x0E); // TX Buffer - 12567446 to 12567581
  writeRegister(0x44, 0x23); // TX Buffer - 12567595 to 12567731
  writeRegister(0x45, 0x11); // TX Buffer - 12567743 to 12567879
  writeRegister(0x46, 0x13); // TX Buffer - 12567892 to 12568028
  writeRegister(0x04, 0x07); // TX - 12568041 to 12568176
  writeRegister(0x00, 0xFF); // CS0 - 12574822 to 12574959
  writeRegister(0x01, 0xFF); // CS1 - 12574972 to 12575113
  writeRegister(0x16, 0xC0); // FIFO CTRL - 12575122 to 12575260
  writeRegister(0x40, 0x04); // TX Buffer - 12575270 to 12575404
  writeRegister(0x41, 0x0E); // TX Buffer - 12575417 to 12575552
  writeRegister(0x44, 0x23); // TX Buffer - 12575566 to 12575702
  writeRegister(0x45, 0x11); // TX Buffer - 12575714 to 12575849
  writeRegister(0x46, 0x13); // TX Buffer - 12575863 to 12576005
  writeRegister(0x04, 0x07); // TX - 12576012 to 12576147
  writeRegister(0x00, 0xFF); // CS0 - 12582877 to 12583015
  writeRegister(0x01, 0xFF); // CS1 - 12583027 to 12583167
  writeRegister(0x16, 0xC0); // FIFO CTRL - 12583181 to 12583316
  writeRegister(0x40, 0x04); // TX Buffer - 12583330 to 12583463
  writeRegister(0x41, 0x0E); // TX Buffer - 12583473 to 12583611
  writeRegister(0x44, 0x23); // TX Buffer - 12583622 to 12583764
  writeRegister(0x45, 0x11); // TX Buffer - 12583770 to 12583912
  writeRegister(0x46, 0x13); // TX Buffer - 12583919 to 12584057
  writeRegister(0x04, 0x07); // TX - 12584068 to 12584209
  writeRegister(0x00, 0xFF); // CS0 - 12590849 to 12590988
  writeRegister(0x01, 0xFF); // CS1 - 12590998 to 12591140
  writeRegister(0x16, 0xC0); // FIFO CTRL - 12591152 to 12591287
  writeRegister(0x40, 0x04); // TX Buffer - 12591301 to 12591434
  writeRegister(0x41, 0x0E); // TX Buffer - 12591448 to 12591582
  writeRegister(0x44, 0x23); // TX Buffer - 12591596 to 12591732
  writeRegister(0x45, 0x11); // TX Buffer - 12591745 to 12591879
  writeRegister(0x46, 0x13); // TX Buffer - 12591893 to 12592028
  writeRegister(0x04, 0x07); // TX - 12592042 to 12592176
  writeRegister(0x00, 0xFF); // CS0 - 12598823 to 12598959
  writeRegister(0x01, 0xFF); // CS1 - 12598973 to 12599114
  writeRegister(0x16, 0xC0); // FIFO CTRL - 12599123 to 12599261
  writeRegister(0x40, 0x04); // TX Buffer - 12599272 to 12599405
  writeRegister(0x41, 0x0E); // TX Buffer - 12599419 to 12599553
  writeRegister(0x44, 0x23); // TX Buffer - 12599567 to 12599703
  writeRegister(0x45, 0x11); // TX Buffer - 12599716 to 12599850
  writeRegister(0x46, 0x13); // TX Buffer - 12599864 to 12599999
  writeRegister(0x04, 0x07); // TX - 12600013 to 12600147
  writeRegister(0x00, 0xFF); // CS0 - 12606871 to 12607008
  writeRegister(0x01, 0xFF); // CS1 - 12607021 to 12607162
  writeRegister(0x16, 0xC0); // FIFO CTRL - 12607171 to 12607309
  writeRegister(0x40, 0x04); // TX Buffer - 12607320 to 12607453
  writeRegister(0x41, 0x0E); // TX Buffer - 12607466 to 12607601
  writeRegister(0x44, 0x23); // TX Buffer - 12607615 to 12607751
  writeRegister(0x45, 0x11); // TX Buffer - 12607763 to 12607898
  writeRegister(0x46, 0x13); // TX Buffer - 12607912 to 12608054
  writeRegister(0x04, 0x07); // TX - 12608061 to 12608196
  writeRegister(0x00, 0xFF); // CS0 - 12614842 to 12614981
  writeRegister(0x01, 0xFF); // CS1 - 12614992 to 12615133
  writeRegister(0x16, 0xC0); // FIFO CTRL - 12615146 to 12615280
  writeRegister(0x40, 0x04); // TX Buffer - 12615294 to 12615427
  writeRegister(0x41, 0x0E); // TX Buffer - 12615438 to 12615576
  writeRegister(0x44, 0x23); // TX Buffer - 12615586 to 12615724
  writeRegister(0x45, 0x11); // TX Buffer - 12615734 to 12615874
  writeRegister(0x46, 0x13); // TX Buffer - 12615883 to 12616023
  writeRegister(0x04, 0x07); // TX - 12616035 to 12616169
  writeRegister(0x00, 0xFF); // CS0 - 12622813 to 12622952
  writeRegister(0x01, 0xFF); // CS1 - 12622966 to 12623110
  writeRegister(0x16, 0xC0); // FIFO CTRL - 12623117 to 12623259
  writeRegister(0x40, 0x04); // TX Buffer - 12623265 to 12623398
  writeRegister(0x41, 0x0E); // TX Buffer - 12623412 to 12623547
  writeRegister(0x44, 0x23); // TX Buffer - 12623560 to 12623695
  writeRegister(0x45, 0x11); // TX Buffer - 12623709 to 12623845
  writeRegister(0x46, 0x13); // TX Buffer - 12623857 to 12623994
  writeRegister(0x04, 0x07); // TX - 12624006 to 12624142
  writeRegister(0x00, 0xFF); // CS0 - 12630869 to 12631008
  writeRegister(0x01, 0xFF); // CS1 - 12631022 to 12631166
  writeRegister(0x16, 0xC0); // FIFO CTRL - 12631172 to 12631312
  writeRegister(0x40, 0x04); // TX Buffer - 12631321 to 12631454
  writeRegister(0x41, 0x0E); // TX Buffer - 12631468 to 12631604
  writeRegister(0x44, 0x23); // TX Buffer - 12631616 to 12631752
  writeRegister(0x45, 0x11); // TX Buffer - 12631765 to 12631899
  writeRegister(0x46, 0x13); // TX Buffer - 12631913 to 12632048
  writeRegister(0x04, 0x07); // TX - 12632062 to 12632196
  writeRegister(0x00, 0xFF); // CS0 - 12638843 to 12638987
  writeRegister(0x01, 0xFF); // CS1 - 12638993 to 12639133
  writeRegister(0x16, 0xC0); // FIFO CTRL - 12639147 to 12639282
  writeRegister(0x40, 0x04); // TX Buffer - 12639295 to 12639430
  writeRegister(0x41, 0x0E); // TX Buffer - 12639439 to 12639577
  writeRegister(0x44, 0x23); // TX Buffer - 12639587 to 12639725
  writeRegister(0x45, 0x11); // TX Buffer - 12639736 to 12639875
  writeRegister(0x46, 0x13); // TX Buffer - 12639884 to 12640024
  writeRegister(0x04, 0x07); // TX - 12640033 to 12640172
  writeRegister(0x00, 0xFF); // CS0 - 12646814 to 12646955
  writeRegister(0x01, 0xFF); // CS1 - 12646968 to 12647104
  writeRegister(0x16, 0xC0); // FIFO CTRL - 12647118 to 12647253
  writeRegister(0x40, 0x04); // TX Buffer - 12647266 to 12647400
  writeRegister(0x41, 0x0E); // TX Buffer - 12647413 to 12647548
  writeRegister(0x44, 0x23); // TX Buffer - 12647562 to 12647698
  writeRegister(0x45, 0x11); // TX Buffer - 12647710 to 12647846
  writeRegister(0x46, 0x13); // TX Buffer - 12647859 to 12647995
  writeRegister(0x04, 0x07); // TX - 12648008 to 12648143
  writeRegister(0x00, 0xFF); // CS0 - 12654870 to 12655011
  writeRegister(0x01, 0xFF); // CS1 - 12655023 to 12655167
  writeRegister(0x16, 0xC0); // FIFO CTRL - 12655174 to 12655316
  writeRegister(0x40, 0x04); // TX Buffer - 12655322 to 12655455
  writeRegister(0x41, 0x0E); // TX Buffer - 12655469 to 12655604
  writeRegister(0x44, 0x23); // TX Buffer - 12655618 to 12655752
  writeRegister(0x45, 0x11); // TX Buffer - 12655766 to 12655902
  writeRegister(0x46, 0x13); // TX Buffer - 12655914 to 12656051
  writeRegister(0x04, 0x07); // TX - 12656063 to 12656199
  writeRegister(0x00, 0xFF); // CS0 - 12662844 to 12662982
  writeRegister(0x01, 0xFF); // CS1 - 12662994 to 12663134
  writeRegister(0x16, 0xC0); // FIFO CTRL - 12663148 to 12663283
  writeRegister(0x40, 0x04); // TX Buffer - 12663297 to 12663430
  writeRegister(0x41, 0x0E); // TX Buffer - 12663440 to 12663578
  writeRegister(0x44, 0x23); // TX Buffer - 12663589 to 12663731
  writeRegister(0x45, 0x11); // TX Buffer - 12663737 to 12663879
  writeRegister(0x46, 0x13); // TX Buffer - 12663886 to 12664024
  writeRegister(0x04, 0x07); // TX - 12664034 to 12664176
  writeRegister(0x00, 0xFF); // CS0 - 12670816 to 12670955
  writeRegister(0x01, 0xFF); // CS1 - 12670965 to 12671107
  writeRegister(0x16, 0xC0); // FIFO CTRL - 12671119 to 12671254
  writeRegister(0x40, 0x04); // TX Buffer - 12671268 to 12671401
  writeRegister(0x41, 0x0E); // TX Buffer - 12671415 to 12671549
  writeRegister(0x44, 0x23); // TX Buffer - 12671563 to 12671699
  writeRegister(0x45, 0x11); // TX Buffer - 12671712 to 12671846
  writeRegister(0x46, 0x13); // TX Buffer - 12671860 to 12671995
  writeRegister(0x04, 0x07); // TX - 12672009 to 12672143
  writeRegister(0x00, 0xFF); // CS0 - 12678871 to 12679012
  writeRegister(0x01, 0xFF); // CS1 - 12679025 to 12679161
  writeRegister(0x16, 0xC0); // FIFO CTRL - 12679175 to 12679310
  writeRegister(0x40, 0x04); // TX Buffer - 12679323 to 12679457
  writeRegister(0x41, 0x0E); // TX Buffer - 12679470 to 12679605
  writeRegister(0x44, 0x23); // TX Buffer - 12679619 to 12679755
  writeRegister(0x45, 0x11); // TX Buffer - 12679767 to 12679902
  writeRegister(0x46, 0x13); // TX Buffer - 12679916 to 12680052
  writeRegister(0x04, 0x07); // TX - 12680065 to 12680200
  writeRegister(0x00, 0xFF); // CS0 - 12686846 to 12686983
  writeRegister(0x01, 0xFF); // CS1 - 12686996 to 12687137
  writeRegister(0x16, 0xC0); // FIFO CTRL - 12687146 to 12687284
  writeRegister(0x40, 0x04); // TX Buffer - 12687295 to 12687428
  writeRegister(0x41, 0x0E); // TX Buffer - 12687442 to 12687576
  writeRegister(0x44, 0x23); // TX Buffer - 12687590 to 12687726
  writeRegister(0x45, 0x11); // TX Buffer - 12687738 to 12687873
  writeRegister(0x46, 0x13); // TX Buffer - 12687887 to 12688028
  writeRegister(0x04, 0x07); // TX - 12688036 to 12688171
  writeRegister(0x00, 0xFF); // CS0 - 12694817 to 12694956
  writeRegister(0x01, 0xFF); // CS1 - 12694967 to 12695108
  writeRegister(0x16, 0xC0); // FIFO CTRL - 12695121 to 12695255
  writeRegister(0x40, 0x04); // TX Buffer - 12695269 to 12695402
  writeRegister(0x41, 0x0E); // TX Buffer - 12695413 to 12695551
  writeRegister(0x44, 0x23); // TX Buffer - 12695561 to 12695699
  writeRegister(0x45, 0x11); // TX Buffer - 12695709 to 12695849
  writeRegister(0x46, 0x13); // TX Buffer - 12695858 to 12695998
  writeRegister(0x04, 0x07); // TX - 12696010 to 12696146
  writeRegister(0x00, 0xFF); // CS0 - 12702873 to 12703012
  writeRegister(0x01, 0xFF); // CS1 - 12703023 to 12703164
  writeRegister(0x16, 0xC0); // FIFO CTRL - 12703176 to 12703311
  writeRegister(0x40, 0x04); // TX Buffer - 12703325 to 12703458
  writeRegister(0x41, 0x0E); // TX Buffer - 12703472 to 12703606
  writeRegister(0x44, 0x23); // TX Buffer - 12703620 to 12703756
  writeRegister(0x45, 0x11); // TX Buffer - 12703769 to 12703903
  writeRegister(0x46, 0x13); // TX Buffer - 12703917 to 12704052
  writeRegister(0x04, 0x07); // TX - 12704066 to 12704200
  writeRegister(0x00, 0xFF); // CS0 - 12710847 to 12710983
  writeRegister(0x01, 0xFF); // CS1 - 12710997 to 12711137
  writeRegister(0x16, 0xC0); // FIFO CTRL - 12711147 to 12711287
  writeRegister(0x40, 0x04); // TX Buffer - 12711296 to 12711429
  writeRegister(0x41, 0x0E); // TX Buffer - 12711443 to 12711579
  writeRegister(0x44, 0x23); // TX Buffer - 12711591 to 12711727
  writeRegister(0x45, 0x11); // TX Buffer - 12711740 to 12711874
  writeRegister(0x46, 0x13); // TX Buffer - 12711888 to 12712023
  writeRegister(0x04, 0x07); // TX - 12712037 to 12712171
  writeRegister(0x00, 0xFF); // CS0 - 12718818 to 12718962
  writeRegister(0x01, 0xFF); // CS1 - 12718968 to 12719108
  writeRegister(0x16, 0xC0); // FIFO CTRL - 12719122 to 12719257
  writeRegister(0x40, 0x04); // TX Buffer - 12719270 to 12719404
  writeRegister(0x41, 0x0E); // TX Buffer - 12719414 to 12719552
  writeRegister(0x44, 0x23); // TX Buffer - 12719562 to 12719700
  writeRegister(0x45, 0x11); // TX Buffer - 12719711 to 12719850
  writeRegister(0x46, 0x13); // TX Buffer - 12719859 to 12719999
  writeRegister(0x04, 0x07); // TX - 12720008 to 12720147
  writeRegister(0x00, 0xFF); // CS0 - 12726874 to 12727015
  writeRegister(0x01, 0xFF); // CS1 - 12727024 to 12727165
  writeRegister(0x16, 0xC0); // FIFO CTRL - 12727178 to 12727312
  writeRegister(0x40, 0x04); // TX Buffer - 12727326 to 12727459
  writeRegister(0x41, 0x0E); // TX Buffer - 12727470 to 12727608
  writeRegister(0x44, 0x23); // TX Buffer - 12727618 to 12727756
  writeRegister(0x45, 0x11); // TX Buffer - 12727767 to 12727906
  writeRegister(0x46, 0x13); // TX Buffer - 12727915 to 12728055
  writeRegister(0x04, 0x07); // TX - 12728067 to 12728203
  writeRegister(0x00, 0xFF); // CS0 - 12734845 to 12734986
  writeRegister(0x01, 0xFF); // CS1 - 12734998 to 12735142
  writeRegister(0x16, 0xC0); // FIFO CTRL - 12735149 to 12735287
  writeRegister(0x40, 0x04); // TX Buffer - 12735297 to 12735430
  writeRegister(0x41, 0x0E); // TX Buffer - 12735444 to 12735579
  writeRegister(0x44, 0x23); // TX Buffer - 12735593 to 12735727
  writeRegister(0x45, 0x11); // TX Buffer - 12735741 to 12735877
  writeRegister(0x46, 0x13); // TX Buffer - 12735890 to 12736026
  writeRegister(0x04, 0x07); // TX - 12736038 to 12736174
  writeRegister(0x00, 0xFF); // CS0 - 12742819 to 12742963
  writeRegister(0x01, 0xFF); // CS1 - 12742969 to 12743109
  writeRegister(0x16, 0xC0); // FIFO CTRL - 12743123 to 12743258
  writeRegister(0x40, 0x04); // TX Buffer - 12743272 to 12743405
  writeRegister(0x41, 0x0E); // TX Buffer - 12743415 to 12743553
  writeRegister(0x44, 0x23); // TX Buffer - 12743564 to 12743706
  writeRegister(0x45, 0x11); // TX Buffer - 12743712 to 12743854
  writeRegister(0x46, 0x13); // TX Buffer - 12743861 to 12743999
  writeRegister(0x04, 0x07); // TX - 12744010 to 12744151
  writeRegister(0x00, 0xFF); // CS0 - 12750875 to 12751019
  writeRegister(0x01, 0xFF); // CS1 - 12751025 to 12751165
  writeRegister(0x16, 0xC0); // FIFO CTRL - 12751179 to 12751314
  writeRegister(0x40, 0x04); // TX Buffer - 12751327 to 12751461
  writeRegister(0x41, 0x0E); // TX Buffer - 12751471 to 12751609
  writeRegister(0x44, 0x23); // TX Buffer - 12751619 to 12751759
  writeRegister(0x45, 0x11); // TX Buffer - 12751768 to 12751907
  writeRegister(0x46, 0x13); // TX Buffer - 12751916 to 12752056
  writeRegister(0x04, 0x07); // TX - 12752065 to 12752204
  writeRegister(0x00, 0xFF); // CS0 - 12758846 to 12758987
  writeRegister(0x01, 0xFF); // CS1 - 12759000 to 12759136
  writeRegister(0x16, 0xC0); // FIFO CTRL - 12759150 to 12759285
  writeRegister(0x40, 0x04); // TX Buffer - 12759298 to 12759432
  writeRegister(0x41, 0x0E); // TX Buffer - 12759445 to 12759580
  writeRegister(0x44, 0x23); // TX Buffer - 12759594 to 12759730
  writeRegister(0x45, 0x11); // TX Buffer - 12759742 to 12759877
  writeRegister(0x46, 0x13); // TX Buffer - 12759891 to 12760027
  writeRegister(0x04, 0x07); // TX - 12760040 to 12760175
  writeRegister(0x00, 0xFF); // CS0 - 12766821 to 12766958
  writeRegister(0x01, 0xFF); // CS1 - 12766971 to 12767112
  writeRegister(0x16, 0xC0); // FIFO CTRL - 12767121 to 12767259
  writeRegister(0x40, 0x04); // TX Buffer - 12767270 to 12767409
  writeRegister(0x41, 0x0E); // TX Buffer - 12767417 to 12767559
  writeRegister(0x44, 0x23); // TX Buffer - 12767565 to 12767707
  writeRegister(0x45, 0x11); // TX Buffer - 12767713 to 12767856
  writeRegister(0x46, 0x13); // TX Buffer - 12767862 to 12768005
  writeRegister(0x04, 0x07); // TX - 12768011 to 12768151
  writeRegister(0x00, 0xFF); // CS0 - 12774877 to 12775020
  writeRegister(0x01, 0xFF); // CS1 - 12775026 to 12775168
  writeRegister(0x16, 0xC0); // FIFO CTRL - 12775180 to 12775315
  writeRegister(0x40, 0x04); // TX Buffer - 12775329 to 12775462
  writeRegister(0x41, 0x0E); // TX Buffer - 12775472 to 12775610
  writeRegister(0x44, 0x23); // TX Buffer - 12775621 to 12775763
  writeRegister(0x45, 0x11); // TX Buffer - 12775769 to 12775911
  writeRegister(0x46, 0x13); // TX Buffer - 12775918 to 12776056
  writeRegister(0x04, 0x07); // TX - 12776067 to 12776208
  writeRegister(0x00, 0xFF); // CS0 - 12782848 to 12782987
  writeRegister(0x01, 0xFF); // CS1 - 12783001 to 12783139
  writeRegister(0x16, 0xC0); // FIFO CTRL - 12783151 to 12783286
  writeRegister(0x40, 0x04); // TX Buffer - 12783300 to 12783433
  writeRegister(0x41, 0x0E); // TX Buffer - 12783447 to 12783583
  writeRegister(0x44, 0x23); // TX Buffer - 12783595 to 12783731
  writeRegister(0x45, 0x11); // TX Buffer - 12783744 to 12783878
  writeRegister(0x46, 0x13); // TX Buffer - 12783892 to 12784027
  writeRegister(0x04, 0x07); // TX - 12784041 to 12784175
  writeRegister(0x00, 0xFF); // CS0 - 12790822 to 12790958
  writeRegister(0x01, 0xFF); // CS1 - 12790972 to 12791112
  writeRegister(0x16, 0xC0); // FIFO CTRL - 12791122 to 12791261
  writeRegister(0x40, 0x04); // TX Buffer - 12791271 to 12791404
  writeRegister(0x41, 0x0E); // TX Buffer - 12791418 to 12791553
  writeRegister(0x44, 0x23); // TX Buffer - 12791566 to 12791702
  writeRegister(0x45, 0x11); // TX Buffer - 12791715 to 12791849
  writeRegister(0x46, 0x13); // TX Buffer - 12791863 to 12792006
  writeRegister(0x04, 0x07); // TX - 12792012 to 12792146
  writeRegister(0x00, 0xFF); // CS0 - 12798878 to 12799014
  writeRegister(0x01, 0xFF); // CS1 - 12799028 to 12799169
  writeRegister(0x16, 0xC0); // FIFO CTRL - 12799178 to 12799316
  writeRegister(0x40, 0x04); // TX Buffer - 12799327 to 12799466
  writeRegister(0x41, 0x0E); // TX Buffer - 12799474 to 12799616
  writeRegister(0x44, 0x23); // TX Buffer - 12799622 to 12799764
  writeRegister(0x45, 0x11); // TX Buffer - 12799771 to 12799913
  writeRegister(0x46, 0x13); // TX Buffer - 12799919 to 12800062
  writeRegister(0x04, 0x07); // TX - 12800068 to 12800210
  writeRegister(0x00, 0xFF); // CS0 - 12806849 to 12806990
  writeRegister(0x01, 0xFF); // CS1 - 12806999 to 12807140
  writeRegister(0x16, 0xC0); // FIFO CTRL - 12807153 to 12807287
  writeRegister(0x40, 0x04); // TX Buffer - 12807301 to 12807434
  writeRegister(0x41, 0x0E); // TX Buffer - 12807448 to 12807583
  writeRegister(0x44, 0x23); // TX Buffer - 12807597 to 12807731
  writeRegister(0x45, 0x11); // TX Buffer - 12807745 to 12807881
  writeRegister(0x46, 0x13); // TX Buffer - 12807893 to 12808030
  writeRegister(0x04, 0x07); // TX - 12808042 to 12808178
  writeRegister(0x00, 0xFF); // CS0 - 12814820 to 12814961
  writeRegister(0x01, 0xFF); // CS1 - 12814973 to 12815117
  writeRegister(0x16, 0xC0); // FIFO CTRL - 12815124 to 12815262
  writeRegister(0x40, 0x04); // TX Buffer - 12815272 to 12815405
  writeRegister(0x41, 0x0E); // TX Buffer - 12815419 to 12815554
  writeRegister(0x44, 0x23); // TX Buffer - 12815568 to 12815702
  writeRegister(0x45, 0x11); // TX Buffer - 12815716 to 12815852
  writeRegister(0x46, 0x13); // TX Buffer - 12815865 to 12816001
  writeRegister(0x04, 0x07); // TX - 12816013 to 12816149
  writeRegister(0x00, 0xFF); // CS0 - 12822879 to 12823015
  writeRegister(0x01, 0xFF); // CS1 - 12823029 to 12823169
  writeRegister(0x16, 0xC0); // FIFO CTRL - 12823180 to 12823318
  writeRegister(0x40, 0x04); // TX Buffer - 12823328 to 12823461
  writeRegister(0x41, 0x0E); // TX Buffer - 12823475 to 12823610
  writeRegister(0x44, 0x23); // TX Buffer - 12823623 to 12823758
  writeRegister(0x45, 0x11); // TX Buffer - 12823772 to 12823908
  writeRegister(0x46, 0x13); // TX Buffer - 12823920 to 12824063
  writeRegister(0x04, 0x07); // TX - 12824069 to 12824203
  writeRegister(0x00, 0xFF); // CS0 - 12830850 to 12830991
  writeRegister(0x01, 0xFF); // CS1 - 12831000 to 12831140
  writeRegister(0x16, 0xC0); // FIFO CTRL - 12831154 to 12831289
  writeRegister(0x40, 0x04); // TX Buffer - 12831302 to 12831436
  writeRegister(0x41, 0x0E); // TX Buffer - 12831446 to 12831584
  writeRegister(0x44, 0x23); // TX Buffer - 12831594 to 12831734
  writeRegister(0x45, 0x11); // TX Buffer - 12831743 to 12831881
  writeRegister(0x46, 0x13); // TX Buffer - 12831891 to 12832031
  writeRegister(0x04, 0x07); // TX - 12832044 to 12832179
  writeRegister(0x00, 0xFF); // CS0 - 12838821 to 12838962
  writeRegister(0x01, 0xFF); // CS1 - 12838975 to 12839119
  writeRegister(0x16, 0xC0); // FIFO CTRL - 12839125 to 12839266
  writeRegister(0x40, 0x04); // TX Buffer - 12839274 to 12839407
  writeRegister(0x41, 0x0E); // TX Buffer - 12839421 to 12839555
  writeRegister(0x44, 0x23); // TX Buffer - 12839569 to 12839705
  writeRegister(0x45, 0x11); // TX Buffer - 12839717 to 12839852
  writeRegister(0x46, 0x13); // TX Buffer - 12839866 to 12840001
  writeRegister(0x04, 0x07); // TX - 12840015 to 12840150
  writeRegister(0x00, 0xFF); // CS0 - 12846877 to 12847018
  writeRegister(0x01, 0xFF); // CS1 - 12847030 to 12847175
  writeRegister(0x16, 0xC0); // FIFO CTRL - 12847181 to 12847319
  writeRegister(0x40, 0x04); // TX Buffer - 12847329 to 12847463
  writeRegister(0x41, 0x0E); // TX Buffer - 12847476 to 12847611
  writeRegister(0x44, 0x23); // TX Buffer - 12847625 to 12847759
  writeRegister(0x45, 0x11); // TX Buffer - 12847773 to 12847909
  writeRegister(0x46, 0x13); // TX Buffer - 12847922 to 12848058
  writeRegister(0x04, 0x07); // TX - 12848071 to 12848206
  writeRegister(0x00, 0xFF); // CS0 - 12854852 to 12854995
  writeRegister(0x01, 0xFF); // CS1 - 12855002 to 12855143
  writeRegister(0x16, 0xC0); // FIFO CTRL - 12855155 to 12855290
  writeRegister(0x40, 0x04); // TX Buffer - 12855304 to 12855437
  writeRegister(0x41, 0x0E); // TX Buffer - 12855447 to 12855585
  writeRegister(0x44, 0x23); // TX Buffer - 12855596 to 12855735
  writeRegister(0x45, 0x11); // TX Buffer - 12855744 to 12855882
  writeRegister(0x46, 0x13); // TX Buffer - 12855893 to 12856031
  writeRegister(0x04, 0x07); // TX - 12856042 to 12856179
  writeRegister(0x00, 0xFF); // CS0 - 12862823 to 12862962
  writeRegister(0x01, 0xFF); // CS1 - 12862976 to 12863114
  writeRegister(0x16, 0xC0); // FIFO CTRL - 12863126 to 12863261
  writeRegister(0x40, 0x04); // TX Buffer - 12863275 to 12863408
  writeRegister(0x41, 0x0E); // TX Buffer - 12863422 to 12863558
  writeRegister(0x44, 0x23); // TX Buffer - 12863570 to 12863706
  writeRegister(0x45, 0x11); // TX Buffer - 12863719 to 12863853
  writeRegister(0x46, 0x13); // TX Buffer - 12863867 to 12864002
  writeRegister(0x04, 0x07); // TX - 12864016 to 12864150
  writeRegister(0x00, 0xFF); // CS0 - 12870878 to 12871018
  writeRegister(0x01, 0xFF); // CS1 - 12871032 to 12871176
  writeRegister(0x16, 0xC0); // FIFO CTRL - 12871182 to 12871323
  writeRegister(0x40, 0x04); // TX Buffer - 12871331 to 12871464
  writeRegister(0x41, 0x0E); // TX Buffer - 12871478 to 12871612
  writeRegister(0x44, 0x23); // TX Buffer - 12871626 to 12871762
  writeRegister(0x45, 0x11); // TX Buffer - 12871775 to 12871909
  writeRegister(0x46, 0x13); // TX Buffer - 12871923 to 12872058
  writeRegister(0x04, 0x07); // TX - 12872072 to 12872206
  writeRegister(0x00, 0xFF); // CS0 - 12878853 to 12878989
  writeRegister(0x01, 0xFF); // CS1 - 12879003 to 12879144
  writeRegister(0x16, 0xC0); // FIFO CTRL - 12879157 to 12879291
  writeRegister(0x40, 0x04); // TX Buffer - 12879305 to 12879438
  writeRegister(0x41, 0x0E); // TX Buffer - 12879449 to 12879587
  writeRegister(0x44, 0x23); // TX Buffer - 12879597 to 12879739
  writeRegister(0x45, 0x11); // TX Buffer - 12879746 to 12879888
  writeRegister(0x46, 0x13); // TX Buffer - 12879894 to 12880034
  writeRegister(0x04, 0x07); // TX - 12880043 to 12880185
  writeRegister(0x00, 0xFF); // CS0 - 12886824 to 12886965
  writeRegister(0x01, 0xFF); // CS1 - 12886974 to 12887115
  writeRegister(0x16, 0xC0); // FIFO CTRL - 12887128 to 12887262
  writeRegister(0x40, 0x04); // TX Buffer - 12887276 to 12887409
  writeRegister(0x41, 0x0E); // TX Buffer - 12887423 to 12887558
  writeRegister(0x44, 0x23); // TX Buffer - 12887572 to 12887706
  writeRegister(0x45, 0x11); // TX Buffer - 12887720 to 12887856
  writeRegister(0x46, 0x13); // TX Buffer - 12887869 to 12888005
  writeRegister(0x04, 0x07); // TX - 12888017 to 12888153
  writeRegister(0x00, 0xFF); // CS0 - 12894880 to 12895019
  writeRegister(0x01, 0xFF); // CS1 - 12895033 to 12895171
  writeRegister(0x16, 0xC0); // FIFO CTRL - 12895184 to 12895318
  writeRegister(0x40, 0x04); // TX Buffer - 12895332 to 12895465
  writeRegister(0x41, 0x0E); // TX Buffer - 12895479 to 12895614
  writeRegister(0x44, 0x23); // TX Buffer - 12895627 to 12895762
  writeRegister(0x45, 0x11); // TX Buffer - 12895776 to 12895912
  writeRegister(0x46, 0x13); // TX Buffer - 12895924 to 12896059
  writeRegister(0x04, 0x07); // TX - 12896073 to 12896207
  writeRegister(0x00, 0xFF); // CS0 - 12902854 to 12902990
  writeRegister(0x01, 0xFF); // CS1 - 12903004 to 12903144
  writeRegister(0x16, 0xC0); // FIFO CTRL - 12903155 to 12903293
  writeRegister(0x40, 0x04); // TX Buffer - 12903303 to 12903436
  writeRegister(0x41, 0x0E); // TX Buffer - 12903450 to 12903585
  writeRegister(0x44, 0x23); // TX Buffer - 12903598 to 12903733
  writeRegister(0x45, 0x11); // TX Buffer - 12903747 to 12903883
  writeRegister(0x46, 0x13); // TX Buffer - 12903895 to 12904038
  writeRegister(0x04, 0x07); // TX - 12904044 to 12904180
  writeRegister(0x00, 0xFF); // CS0 - 12910825 to 12910966
  writeRegister(0x01, 0xFF); // CS1 - 12910975 to 12911115
  writeRegister(0x16, 0xC0); // FIFO CTRL - 12911129 to 12911264
  writeRegister(0x40, 0x04); // TX Buffer - 12911277 to 12911411
  writeRegister(0x41, 0x0E); // TX Buffer - 12911421 to 12911559
  writeRegister(0x44, 0x23); // TX Buffer - 12911570 to 12911709
  writeRegister(0x45, 0x11); // TX Buffer - 12911718 to 12911856
  writeRegister(0x46, 0x13); // TX Buffer - 12911866 to 12912006
  writeRegister(0x04, 0x07); // TX - 12912019 to 12912154
  writeRegister(0x00, 0xFF); // CS0 - 12918881 to 12919022
  writeRegister(0x01, 0xFF); // CS1 - 12919031 to 12919171
  writeRegister(0x16, 0xC0); // FIFO CTRL - 12919185 to 12919321
  writeRegister(0x40, 0x04); // TX Buffer - 12919333 to 12919468
  writeRegister(0x41, 0x0E); // TX Buffer - 12919480 to 12919615
  writeRegister(0x44, 0x23); // TX Buffer - 12919629 to 12919763
  writeRegister(0x45, 0x11); // TX Buffer - 12919777 to 12919913
  writeRegister(0x46, 0x13); // TX Buffer - 12919926 to 12920062
  writeRegister(0x04, 0x07); // TX - 12920075 to 12920210
  writeRegister(0x00, 0xFF); // CS0 - 12926856 to 12926993
  writeRegister(0x01, 0xFF); // CS1 - 12927005 to 12927147
  writeRegister(0x16, 0xC0); // FIFO CTRL - 12927156 to 12927294
  writeRegister(0x40, 0x04); // TX Buffer - 12927304 to 12927438
  writeRegister(0x41, 0x0E); // TX Buffer - 12927451 to 12927586
  writeRegister(0x44, 0x23); // TX Buffer - 12927600 to 12927734
  writeRegister(0x45, 0x11); // TX Buffer - 12927748 to 12927884
  writeRegister(0x46, 0x13); // TX Buffer - 12927897 to 12928033
  writeRegister(0x04, 0x07); // TX - 12928046 to 12928181
  writeRegister(0x00, 0xFF); // CS0 - 12934827 to 12934970
  writeRegister(0x01, 0xFF); // CS1 - 12934977 to 12935118
  writeRegister(0x16, 0xC0); // FIFO CTRL - 12935130 to 12935265
  writeRegister(0x40, 0x04); // TX Buffer - 12935279 to 12935412
  writeRegister(0x41, 0x0E); // TX Buffer - 12935422 to 12935562
  writeRegister(0x44, 0x23); // TX Buffer - 12935571 to 12935710
  writeRegister(0x45, 0x11); // TX Buffer - 12935719 to 12935857
  writeRegister(0x46, 0x13); // TX Buffer - 12935868 to 12936006
  writeRegister(0x04, 0x07); // TX - 12936017 to 12936154
  writeRegister(0x00, 0xFF); // CS0 - 12942882 to 12943023
  writeRegister(0x01, 0xFF); // CS1 - 12943032 to 12943172
  writeRegister(0x16, 0xC0); // FIFO CTRL - 12943186 to 12943321
  writeRegister(0x40, 0x04); // TX Buffer - 12943335 to 12943468
  writeRegister(0x41, 0x0E); // TX Buffer - 12943478 to 12943616
  writeRegister(0x44, 0x23); // TX Buffer - 12943627 to 12943766
  writeRegister(0x45, 0x11); // TX Buffer - 12943775 to 12943913
  writeRegister(0x46, 0x13); // TX Buffer - 12943924 to 12944062
  writeRegister(0x04, 0x07); // TX - 12944076 to 12944210
  writeRegister(0x00, 0xFF); // CS0 - 12950853 to 12950993
  writeRegister(0x01, 0xFF); // CS1 - 12951007 to 12951151
  writeRegister(0x16, 0xC0); // FIFO CTRL - 12951157 to 12951295
  writeRegister(0x40, 0x04); // TX Buffer - 12951306 to 12951439
  writeRegister(0x41, 0x0E); // TX Buffer - 12951453 to 12951587
  writeRegister(0x44, 0x23); // TX Buffer - 12951601 to 12951737
  writeRegister(0x45, 0x11); // TX Buffer - 12951750 to 12951884
  writeRegister(0x46, 0x13); // TX Buffer - 12951898 to 12952033
  writeRegister(0x04, 0x07); // TX - 12952047 to 12952181
  writeRegister(0x00, 0xFF); // CS0 - 12958828 to 12958972
  writeRegister(0x01, 0xFF); // CS1 - 12958978 to 12959119
  writeRegister(0x16, 0xC0); // FIFO CTRL - 12959132 to 12959266
  writeRegister(0x40, 0x04); // TX Buffer - 12959280 to 12959413
  writeRegister(0x41, 0x0E); // TX Buffer - 12959424 to 12959562
  writeRegister(0x44, 0x23); // TX Buffer - 12959572 to 12959714
  writeRegister(0x45, 0x11); // TX Buffer - 12959721 to 12959863
  writeRegister(0x46, 0x13); // TX Buffer - 12959869 to 12960009
  writeRegister(0x04, 0x07); // TX - 12960018 to 12960160
  writeRegister(0x00, 0xFF); // CS0 - 12966884 to 12967027
  writeRegister(0x01, 0xFF); // CS1 - 12967034 to 12967175
  writeRegister(0x16, 0xC0); // FIFO CTRL - 12967187 to 12967322
  writeRegister(0x40, 0x04); // TX Buffer - 12967336 to 12967469
  writeRegister(0x41, 0x0E); // TX Buffer - 12967479 to 12967618
  writeRegister(0x44, 0x23); // TX Buffer - 12967628 to 12967766
  writeRegister(0x45, 0x11); // TX Buffer - 12967776 to 12967916
  writeRegister(0x46, 0x13); // TX Buffer - 12967925 to 12968063
  writeRegister(0x04, 0x07); // TX - 12968074 to 12968211
  writeRegister(0x00, 0xFF); // CS0 - 12974855 to 12974994
  writeRegister(0x01, 0xFF); // CS1 - 12975008 to 12975146
  writeRegister(0x16, 0xC0); // FIFO CTRL - 12975159 to 12975293
  writeRegister(0x40, 0x04); // TX Buffer - 12975307 to 12975440
  writeRegister(0x41, 0x0E); // TX Buffer - 12975454 to 12975589
  writeRegister(0x44, 0x23); // TX Buffer - 12975602 to 12975737
  writeRegister(0x45, 0x11); // TX Buffer - 12975751 to 12975887
  writeRegister(0x46, 0x13); // TX Buffer - 12975899 to 12976036
  writeRegister(0x04, 0x07); // TX - 12976048 to 12976182
  writeRegister(0x00, 0xFF); // CS0 - 12982829 to 12982965
  writeRegister(0x01, 0xFF); // CS1 - 12982979 to 12983119
  writeRegister(0x16, 0xC0); // FIFO CTRL - 12983130 to 12983268
  writeRegister(0x40, 0x04); // TX Buffer - 12983278 to 12983419
  writeRegister(0x41, 0x0E); // TX Buffer - 12983425 to 12983566
  writeRegister(0x44, 0x23); // TX Buffer - 12983573 to 12983716
  writeRegister(0x45, 0x11); // TX Buffer - 12983722 to 12983864
  writeRegister(0x46, 0x13); // TX Buffer - 12983870 to 12984013
  writeRegister(0x04, 0x07); // TX - 12984019 to 12984161
  writeRegister(0x00, 0xFF); // CS0 - 12990885 to 12991029
  writeRegister(0x01, 0xFF); // CS1 - 12991035 to 12991175
  writeRegister(0x16, 0xC0); // FIFO CTRL - 12991189 to 12991325
  writeRegister(0x40, 0x04); // TX Buffer - 12991337 to 12991472
  writeRegister(0x41, 0x0E); // TX Buffer - 12991481 to 12991619
  writeRegister(0x44, 0x23); // TX Buffer - 12991629 to 12991771
  writeRegister(0x45, 0x11); // TX Buffer - 12991778 to 12991920
  writeRegister(0x46, 0x13); // TX Buffer - 12991926 to 12992066
  writeRegister(0x04, 0x07); // TX - 12992075 to 12992217
  writeRegister(0x00, 0xFF); // CS0 - 12998856 to 12998997
  writeRegister(0x01, 0xFF); // CS1 - 12999009 to 12999146
  writeRegister(0x16, 0xC0); // FIFO CTRL - 12999160 to 12999295
  writeRegister(0x40, 0x04); // TX Buffer - 12999308 to 12999442
  writeRegister(0x41, 0x0E); // TX Buffer - 12999455 to 12999590
  writeRegister(0x44, 0x23); // TX Buffer - 12999604 to 12999738
  writeRegister(0x45, 0x11); // TX Buffer - 12999752 to 12999888
  writeRegister(0x46, 0x13); // TX Buffer - 12999901 to 13000037
  writeRegister(0x04, 0x07); // TX - 13000050 to 13000185
  writeRegister(0x00, 0xFF); // CS0 - 13006831 to 13006968
  writeRegister(0x01, 0xFF); // CS1 - 13006981 to 13007122
  writeRegister(0x16, 0xC0); // FIFO CTRL - 13007131 to 13007269
  writeRegister(0x40, 0x04); // TX Buffer - 13007279 to 13007413
  writeRegister(0x41, 0x0E); // TX Buffer - 13007426 to 13007561
  writeRegister(0x44, 0x23); // TX Buffer - 13007575 to 13007711
  writeRegister(0x45, 0x11); // TX Buffer - 13007723 to 13007859
  writeRegister(0x46, 0x13); // TX Buffer - 13007872 to 13008014
  writeRegister(0x04, 0x07); // TX - 13008021 to 13008156
  writeRegister(0x00, 0xFF); // CS0 - 13014886 to 13015024
  writeRegister(0x01, 0xFF); // CS1 - 13015036 to 13015176
  writeRegister(0x16, 0xC0); // FIFO CTRL - 13015187 to 13015325
  writeRegister(0x40, 0x04); // TX Buffer - 13015335 to 13015476
  writeRegister(0x41, 0x0E); // TX Buffer - 13015482 to 13015623
  writeRegister(0x44, 0x23); // TX Buffer - 13015631 to 13015773
  writeRegister(0x45, 0x11); // TX Buffer - 13015779 to 13015921
  writeRegister(0x46, 0x13); // TX Buffer - 13015927 to 13016070
  writeRegister(0x04, 0x07); // TX - 13016076 to 13016218
  writeRegister(0x00, 0xFF); // CS0 - 13022857 to 13022997
  writeRegister(0x01, 0xFF); // CS1 - 13023007 to 13023147
  writeRegister(0x16, 0xC0); // FIFO CTRL - 13023161 to 13023296
  writeRegister(0x40, 0x04); // TX Buffer - 13023310 to 13023443
  writeRegister(0x41, 0x0E); // TX Buffer - 13023457 to 13023591
  writeRegister(0x44, 0x23); // TX Buffer - 13023605 to 13023741
  writeRegister(0x45, 0x11); // TX Buffer - 13023754 to 13023888
  writeRegister(0x46, 0x13); // TX Buffer - 13023902 to 13024037
  writeRegister(0x04, 0x07); // TX - 13024051 to 13024185
  writeRegister(0x00, 0xFF); // CS0 - 13030829 to 13030968
  writeRegister(0x01, 0xFF); // CS1 - 13030982 to 13031126
  writeRegister(0x16, 0xC0); // FIFO CTRL - 13031132 to 13031270
  writeRegister(0x40, 0x04); // TX Buffer - 13031281 to 13031414
  writeRegister(0x41, 0x0E); // TX Buffer - 13031428 to 13031562
  writeRegister(0x44, 0x23); // TX Buffer - 13031576 to 13031712
  writeRegister(0x45, 0x11); // TX Buffer - 13031725 to 13031859
  writeRegister(0x46, 0x13); // TX Buffer - 13031873 to 13032008
  writeRegister(0x04, 0x07); // TX - 13032022 to 13032156
  writeRegister(0x00, 0xFF); // CS0 - 13038888 to 13039025
  writeRegister(0x01, 0xFF); // CS1 - 13039038 to 13039179
  writeRegister(0x16, 0xC0); // FIFO CTRL - 13039188 to 13039326
  writeRegister(0x40, 0x04); // TX Buffer - 13039336 to 13039470
  writeRegister(0x41, 0x0E); // TX Buffer - 13039483 to 13039618
  writeRegister(0x44, 0x23); // TX Buffer - 13039632 to 13039768
  writeRegister(0x45, 0x11); // TX Buffer - 13039780 to 13039915
  writeRegister(0x46, 0x13); // TX Buffer - 13039929 to 13040071
  writeRegister(0x04, 0x07); // TX - 13040078 to 13040213
  writeRegister(0x00, 0xFF); // CS0 - 13046859 to 13046998
  writeRegister(0x01, 0xFF); // CS1 - 13047009 to 13047150
  writeRegister(0x16, 0xC0); // FIFO CTRL - 13047163 to 13047297
  writeRegister(0x40, 0x04); // TX Buffer - 13047311 to 13047444
  writeRegister(0x41, 0x0E); // TX Buffer - 13047455 to 13047593
  writeRegister(0x44, 0x23); // TX Buffer - 13047603 to 13047741
  writeRegister(0x45, 0x11); // TX Buffer - 13047751 to 13047891
  writeRegister(0x46, 0x13); // TX Buffer - 13047900 to 13048038
  writeRegister(0x04, 0x07); // TX - 13048052 to 13048186
  writeRegister(0x00, 0xFF); // CS0 - 13054830 to 13054969
  writeRegister(0x01, 0xFF); // CS1 - 13054983 to 13055127
  writeRegister(0x16, 0xC0); // FIFO CTRL - 13055134 to 13055276
  writeRegister(0x40, 0x04); // TX Buffer - 13055282 to 13055415
  writeRegister(0x41, 0x0E); // TX Buffer - 13055429 to 13055564
  writeRegister(0x44, 0x23); // TX Buffer - 13055577 to 13055712
  writeRegister(0x45, 0x11); // TX Buffer - 13055726 to 13055862
  writeRegister(0x46, 0x13); // TX Buffer - 13055874 to 13056011
  writeRegister(0x04, 0x07); // TX - 13056023 to 13056159
  writeRegister(0x00, 0xFF); // CS0 - 13062886 to 13063025
  writeRegister(0x01, 0xFF); // CS1 - 13063039 to 13063183
  writeRegister(0x16, 0xC0); // FIFO CTRL - 13063189 to 13063327
  writeRegister(0x40, 0x04); // TX Buffer - 13063338 to 13063471
  writeRegister(0x41, 0x0E); // TX Buffer - 13063485 to 13063621
  writeRegister(0x44, 0x23); // TX Buffer - 13063633 to 13063769
  writeRegister(0x45, 0x11); // TX Buffer - 13063782 to 13063916
  writeRegister(0x46, 0x13); // TX Buffer - 13063930 to 13064065
  writeRegister(0x04, 0x07); // TX - 13064079 to 13064213
  writeRegister(0x00, 0xFF); // CS0 - 13070860 to 13071004
  writeRegister(0x01, 0xFF); // CS1 - 13071010 to 13071150
  writeRegister(0x16, 0xC0); // FIFO CTRL - 13071164 to 13071300
  writeRegister(0x40, 0x04); // TX Buffer - 13071312 to 13071447
  writeRegister(0x41, 0x0E); // TX Buffer - 13071456 to 13071594
  writeRegister(0x44, 0x23); // TX Buffer - 13071604 to 13071742
  writeRegister(0x45, 0x11); // TX Buffer - 13071753 to 13071892
  writeRegister(0x46, 0x13); // TX Buffer - 13071901 to 13072041
  writeRegister(0x04, 0x07); // TX - 13072050 to 13072189
  writeRegister(0x00, 0xFF); // CS0 - 13078831 to 13078972
  writeRegister(0x01, 0xFF); // CS1 - 13078984 to 13079121
  writeRegister(0x16, 0xC0); // FIFO CTRL - 13079135 to 13079270
  writeRegister(0x40, 0x04); // TX Buffer - 13079283 to 13079417
  writeRegister(0x41, 0x0E); // TX Buffer - 13079430 to 13079565
  writeRegister(0x44, 0x23); // TX Buffer - 13079579 to 13079713
  writeRegister(0x45, 0x11); // TX Buffer - 13079727 to 13079863
  writeRegister(0x46, 0x13); // TX Buffer - 13079876 to 13080012
  writeRegister(0x04, 0x07); // TX - 13080025 to 13080160
  writeRegister(0x00, 0xFF); // CS0 - 13086887 to 13087028
  writeRegister(0x01, 0xFF); // CS1 - 13087040 to 13087184
  writeRegister(0x16, 0xC0); // FIFO CTRL - 13087191 to 13087333
  writeRegister(0x40, 0x04); // TX Buffer - 13087339 to 13087472
  writeRegister(0x41, 0x0E); // TX Buffer - 13087486 to 13087621
  writeRegister(0x44, 0x23); // TX Buffer - 13087635 to 13087769
  writeRegister(0x45, 0x11); // TX Buffer - 13087783 to 13087919
  writeRegister(0x46, 0x13); // TX Buffer - 13087931 to 13088068
  writeRegister(0x04, 0x07); // TX - 13088080 to 13088216
  writeRegister(0x00, 0xFF); // CS0 - 13094861 to 13094999
  writeRegister(0x01, 0xFF); // CS1 - 13095011 to 13095151
  writeRegister(0x16, 0xC0); // FIFO CTRL - 13095165 to 13095300
  writeRegister(0x40, 0x04); // TX Buffer - 13095314 to 13095447
  writeRegister(0x41, 0x0E); // TX Buffer - 13095457 to 13095595
  writeRegister(0x44, 0x23); // TX Buffer - 13095606 to 13095748
  writeRegister(0x45, 0x11); // TX Buffer - 13095754 to 13095896
  writeRegister(0x46, 0x13); // TX Buffer - 13095903 to 13096041
  writeRegister(0x04, 0x07); // TX - 13096051 to 13096193
  writeRegister(0x00, 0xFF); // CS0 - 13102917 to 13103061
  writeRegister(0x01, 0xFF); // CS1 - 13103067 to 13103207
  writeRegister(0x16, 0xC0); // FIFO CTRL - 13103221 to 13103356
  writeRegister(0x40, 0x04); // TX Buffer - 13103369 to 13103503
  writeRegister(0x41, 0x0E); // TX Buffer - 13103513 to 13103651
  writeRegister(0x44, 0x23); // TX Buffer - 13103661 to 13103801
  writeRegister(0x45, 0x11); // TX Buffer - 13103810 to 13103949
  writeRegister(0x46, 0x13); // TX Buffer - 13103958 to 13104098
  writeRegister(0x04, 0x07); // TX - 13104107 to 13104246
  writeRegister(0x00, 0xFF); // CS0 - 13110888 to 13111029
  writeRegister(0x01, 0xFF); // CS1 - 13111042 to 13111178
  writeRegister(0x16, 0xC0); // FIFO CTRL - 13111192 to 13111327
  writeRegister(0x40, 0x04); // TX Buffer - 13111340 to 13111474
  writeRegister(0x41, 0x0E); // TX Buffer - 13111487 to 13111622
  writeRegister(0x44, 0x23); // TX Buffer - 13111636 to 13111772
  writeRegister(0x45, 0x11); // TX Buffer - 13111784 to 13111920
  writeRegister(0x46, 0x13); // TX Buffer - 13111933 to 13112069
  writeRegister(0x04, 0x07); // TX - 13112082 to 13112217
  writeRegister(0x00, 0xFF); // CS0 - 13118863 to 13119000
  writeRegister(0x01, 0xFF); // CS1 - 13119013 to 13119154
  writeRegister(0x16, 0xC0); // FIFO CTRL - 13119163 to 13119301
  writeRegister(0x40, 0x04); // TX Buffer - 13119312 to 13119445
  writeRegister(0x41, 0x0E); // TX Buffer - 13119458 to 13119593
  writeRegister(0x44, 0x23); // TX Buffer - 13119607 to 13119743
  writeRegister(0x45, 0x11); // TX Buffer - 13119755 to 13119890
  writeRegister(0x46, 0x13); // TX Buffer - 13119904 to 13120046
  writeRegister(0x04, 0x07); // TX - 13120053 to 13120188
  writeRegister(0x00, 0xFF); // CS0 - 13126919 to 13127056
  writeRegister(0x01, 0xFF); // CS1 - 13127068 to 13127210
  writeRegister(0x16, 0xC0); // FIFO CTRL - 13127222 to 13127357
  writeRegister(0x40, 0x04); // TX Buffer - 13127371 to 13127504
  writeRegister(0x41, 0x0E); // TX Buffer - 13127514 to 13127652
  writeRegister(0x44, 0x23); // TX Buffer - 13127663 to 13127805
  writeRegister(0x45, 0x11); // TX Buffer - 13127811 to 13127953
  writeRegister(0x46, 0x13); // TX Buffer - 13127960 to 13128098
  writeRegister(0x04, 0x07); // TX - 13128109 to 13128250
  writeRegister(0x00, 0xFF); // CS0 - 13134890 to 13135029
  writeRegister(0x01, 0xFF); // CS1 - 13135039 to 13135181
  writeRegister(0x16, 0xC0); // FIFO CTRL - 13135193 to 13135328
  writeRegister(0x40, 0x04); // TX Buffer - 13135342 to 13135475
  writeRegister(0x41, 0x0E); // TX Buffer - 13135489 to 13135623
  writeRegister(0x44, 0x23); // TX Buffer - 13135637 to 13135773
  writeRegister(0x45, 0x11); // TX Buffer - 13135786 to 13135920
  writeRegister(0x46, 0x13); // TX Buffer - 13135934 to 13136069
  writeRegister(0x04, 0x07); // TX - 13136083 to 13136217
  writeRegister(0x00, 0xFF); // CS0 - 13142864 to 13143000
  writeRegister(0x01, 0xFF); // CS1 - 13143014 to 13143154
  writeRegister(0x16, 0xC0); // FIFO CTRL - 13143164 to 13143304
  writeRegister(0x40, 0x04); // TX Buffer - 13143313 to 13143446
  writeRegister(0x41, 0x0E); // TX Buffer - 13143460 to 13143596
  writeRegister(0x44, 0x23); // TX Buffer - 13143608 to 13143744
  writeRegister(0x45, 0x11); // TX Buffer - 13143757 to 13143891
  writeRegister(0x46, 0x13); // TX Buffer - 13143905 to 13144040
  writeRegister(0x04, 0x07); // TX - 13144054 to 13144188
  writeRegister(0x00, 0xFF); // CS0 - 13150920 to 13151057
  writeRegister(0x01, 0xFF); // CS1 - 13151070 to 13151211
  writeRegister(0x16, 0xC0); // FIFO CTRL - 13151220 to 13151358
  writeRegister(0x40, 0x04); // TX Buffer - 13151369 to 13151502
  writeRegister(0x41, 0x0E); // TX Buffer - 13151516 to 13151650
  writeRegister(0x44, 0x23); // TX Buffer - 13151664 to 13151800
  writeRegister(0x45, 0x11); // TX Buffer - 13151812 to 13151947
  writeRegister(0x46, 0x13); // TX Buffer - 13151961 to 13152104
  writeRegister(0x04, 0x07); // TX - 13152110 to 13152244
  writeRegister(0x00, 0xFF); // CS0 - 13158891 to 13159032
  writeRegister(0x01, 0xFF); // CS1 - 13159041 to 13159182
  writeRegister(0x16, 0xC0); // FIFO CTRL - 13159195 to 13159329
  writeRegister(0x40, 0x04); // TX Buffer - 13159343 to 13159476
  writeRegister(0x41, 0x0E); // TX Buffer - 13159487 to 13159625
  writeRegister(0x44, 0x23); // TX Buffer - 13159635 to 13159773
  writeRegister(0x45, 0x11); // TX Buffer - 13159784 to 13159923
  writeRegister(0x46, 0x13); // TX Buffer - 13159932 to 13160072
  writeRegister(0x04, 0x07); // TX - 13160084 to 13160220
  writeRegister(0x00, 0xFF); // CS0 - 13166862 to 13167003
  writeRegister(0x01, 0xFF); // CS1 - 13167015 to 13167159
  writeRegister(0x16, 0xC0); // FIFO CTRL - 13167166 to 13167304
  writeRegister(0x40, 0x04); // TX Buffer - 13167314 to 13167447
  writeRegister(0x41, 0x0E); // TX Buffer - 13167461 to 13167596
  writeRegister(0x44, 0x23); // TX Buffer - 13167610 to 13167744
  writeRegister(0x45, 0x11); // TX Buffer - 13167758 to 13167894
  writeRegister(0x46, 0x13); // TX Buffer - 13167906 to 13168043
  writeRegister(0x04, 0x07); // TX - 13168055 to 13168191
  writeRegister(0x00, 0xFF); // CS0 - 13174921 to 13175057
  writeRegister(0x01, 0xFF); // CS1 - 13175071 to 13175211
  writeRegister(0x16, 0xC0); // FIFO CTRL - 13175221 to 13175360
  writeRegister(0x40, 0x04); // TX Buffer - 13175370 to 13175503
  writeRegister(0x41, 0x0E); // TX Buffer - 13175517 to 13175652
  writeRegister(0x44, 0x23); // TX Buffer - 13175665 to 13175800
  writeRegister(0x45, 0x11); // TX Buffer - 13175814 to 13175950
  writeRegister(0x46, 0x13); // TX Buffer - 13175962 to 13176097
  writeRegister(0x04, 0x07); // TX - 13176111 to 13176245
  writeRegister(0x00, 0xFF); // CS0 - 13182892 to 13183036
  writeRegister(0x01, 0xFF); // CS1 - 13183042 to 13183182
  writeRegister(0x16, 0xC0); // FIFO CTRL - 13183196 to 13183331
  writeRegister(0x40, 0x04); // TX Buffer - 13183344 to 13183478
  writeRegister(0x41, 0x0E); // TX Buffer - 13183488 to 13183626
  writeRegister(0x44, 0x23); // TX Buffer - 13183636 to 13183776
  writeRegister(0x45, 0x11); // TX Buffer - 13183785 to 13183924
  writeRegister(0x46, 0x13); // TX Buffer - 13183933 to 13184073
  writeRegister(0x04, 0x07); // TX - 13184082 to 13184221
  writeRegister(0x00, 0xFF); // CS0 - 13190863 to 13191004
  writeRegister(0x01, 0xFF); // CS1 - 13191017 to 13191153
  writeRegister(0x16, 0xC0); // FIFO CTRL - 13191167 to 13191302
  writeRegister(0x40, 0x04); // TX Buffer - 13191315 to 13191449
  writeRegister(0x41, 0x0E); // TX Buffer - 13191462 to 13191597
  writeRegister(0x44, 0x23); // TX Buffer - 13191611 to 13191747
  writeRegister(0x45, 0x11); // TX Buffer - 13191759 to 13191894
  writeRegister(0x46, 0x13); // TX Buffer - 13191908 to 13192044
  writeRegister(0x04, 0x07); // TX - 13192057 to 13192192
  writeRegister(0x00, 0xFF); // CS0 - 13198919 to 13199060
  writeRegister(0x01, 0xFF); // CS1 - 13199072 to 13199215
  writeRegister(0x16, 0xC0); // FIFO CTRL - 13199223 to 13199361
  writeRegister(0x40, 0x04); // TX Buffer - 13199371 to 13199506
  writeRegister(0x41, 0x0E); // TX Buffer - 13199518 to 13199653
  writeRegister(0x44, 0x23); // TX Buffer - 13199667 to 13199801
  writeRegister(0x45, 0x11); // TX Buffer - 13199815 to 13199951
  writeRegister(0x46, 0x13); // TX Buffer - 13199964 to 13200100
  writeRegister(0x04, 0x07); // TX - 13200113 to 13200248
  writeRegister(0x00, 0xFF); // CS0 - 13206894 to 13207037
  writeRegister(0x01, 0xFF); // CS1 - 13207043 to 13207185
  writeRegister(0x16, 0xC0); // FIFO CTRL - 13207197 to 13207332
  writeRegister(0x40, 0x04); // TX Buffer - 13207346 to 13207479
  writeRegister(0x41, 0x0E); // TX Buffer - 13207489 to 13207627
  writeRegister(0x44, 0x23); // TX Buffer - 13207638 to 13207780
  writeRegister(0x45, 0x11); // TX Buffer - 13207786 to 13207928
  writeRegister(0x46, 0x13); // TX Buffer - 13207935 to 13208073
  writeRegister(0x04, 0x07); // TX - 13208084 to 13208225
  writeRegister(0x00, 0xFF); // CS0 - 13214865 to 13215004
  writeRegister(0x01, 0xFF); // CS1 - 13215018 to 13215156
  writeRegister(0x16, 0xC0); // FIFO CTRL - 13215168 to 13215303
  writeRegister(0x40, 0x04); // TX Buffer - 13215317 to 13215450
  writeRegister(0x41, 0x0E); // TX Buffer - 13215464 to 13215598
  writeRegister(0x44, 0x23); // TX Buffer - 13215612 to 13215748
  writeRegister(0x45, 0x11); // TX Buffer - 13215761 to 13215895
  writeRegister(0x46, 0x13); // TX Buffer - 13215909 to 13216044
  writeRegister(0x04, 0x07); // TX - 13216058 to 13216192
  writeRegister(0x00, 0xFF); // CS0 - 13222920 to 13223061
  writeRegister(0x01, 0xFF); // CS1 - 13223074 to 13223210
  writeRegister(0x16, 0xC0); // FIFO CTRL - 13223224 to 13223359
  writeRegister(0x40, 0x04); // TX Buffer - 13223373 to 13223506
  writeRegister(0x41, 0x0E); // TX Buffer - 13223520 to 13223654
  writeRegister(0x44, 0x23); // TX Buffer - 13223668 to 13223804
  writeRegister(0x45, 0x11); // TX Buffer - 13223816 to 13223951
  writeRegister(0x46, 0x13); // TX Buffer - 13223965 to 13224100
  writeRegister(0x04, 0x07); // TX - 13224114 to 13224248
  writeRegister(0x00, 0xFF); // CS0 - 13230895 to 13231031
  writeRegister(0x01, 0xFF); // CS1 - 13231045 to 13231186
  writeRegister(0x16, 0xC0); // FIFO CTRL - 13231195 to 13231333
  writeRegister(0x40, 0x04); // TX Buffer - 13231344 to 13231483
  writeRegister(0x41, 0x0E); // TX Buffer - 13231491 to 13231633
  writeRegister(0x44, 0x23); // TX Buffer - 13231639 to 13231781
  writeRegister(0x45, 0x11); // TX Buffer - 13231788 to 13231930
  writeRegister(0x46, 0x13); // TX Buffer - 13231936 to 13232079
  writeRegister(0x04, 0x07); // TX - 13232085 to 13232227
  writeRegister(0x00, 0xFF); // CS0 - 13238866 to 13239007
  writeRegister(0x01, 0xFF); // CS1 - 13239016 to 13239157
  writeRegister(0x16, 0xC0); // FIFO CTRL - 13239170 to 13239304
  writeRegister(0x40, 0x04); // TX Buffer - 13239318 to 13239451
  writeRegister(0x41, 0x0E); // TX Buffer - 13239465 to 13239600
  writeRegister(0x44, 0x23); // TX Buffer - 13239614 to 13239748
  writeRegister(0x45, 0x11); // TX Buffer - 13239762 to 13239898
  writeRegister(0x46, 0x13); // TX Buffer - 13239910 to 13240047
  writeRegister(0x04, 0x07); // TX - 13240059 to 13240195
  writeRegister(0x00, 0xFF); // CS0 - 13246922 to 13247061
  writeRegister(0x01, 0xFF); // CS1 - 13247075 to 13247213
  writeRegister(0x16, 0xC0); // FIFO CTRL - 13247225 to 13247360
  writeRegister(0x40, 0x04); // TX Buffer - 13247374 to 13247507
  writeRegister(0x41, 0x0E); // TX Buffer - 13247521 to 13247656
  writeRegister(0x44, 0x23); // TX Buffer - 13247669 to 13247804
  writeRegister(0x45, 0x11); // TX Buffer - 13247818 to 13247954
  writeRegister(0x46, 0x13); // TX Buffer - 13247966 to 13248101
  writeRegister(0x04, 0x07); // TX - 13248115 to 13248249
  writeRegister(0x00, 0xFF); // CS0 - 13254896 to 13255032
  writeRegister(0x01, 0xFF); // CS1 - 13255046 to 13255186
  writeRegister(0x16, 0xC0); // FIFO CTRL - 13255197 to 13255335
  writeRegister(0x40, 0x04); // TX Buffer - 13255345 to 13255478
  writeRegister(0x41, 0x0E); // TX Buffer - 13255492 to 13255627
  writeRegister(0x44, 0x23); // TX Buffer - 13255640 to 13255775
  writeRegister(0x45, 0x11); // TX Buffer - 13255789 to 13255925
  writeRegister(0x46, 0x13); // TX Buffer - 13255937 to 13256080
  writeRegister(0x04, 0x07); // TX - 13256086 to 13256220
  writeRegister(0x00, 0xFF); // CS0 - 13262867 to 13263008
  writeRegister(0x01, 0xFF); // CS1 - 13263017 to 13263157
  writeRegister(0x16, 0xC0); // FIFO CTRL - 13263171 to 13263306
  writeRegister(0x40, 0x04); // TX Buffer - 13263319 to 13263453
  writeRegister(0x41, 0x0E); // TX Buffer - 13263463 to 13263601
  writeRegister(0x44, 0x23); // TX Buffer - 13263611 to 13263751
  writeRegister(0x45, 0x11); // TX Buffer - 13263760 to 13263899
  writeRegister(0x46, 0x13); // TX Buffer - 13263908 to 13264048
  writeRegister(0x04, 0x07); // TX - 13264061 to 13264196
  writeRegister(0x00, 0xFF); // CS0 - 13270923 to 13271064
  writeRegister(0x01, 0xFF); // CS1 - 13271073 to 13271213
  writeRegister(0x16, 0xC0); // FIFO CTRL - 13271227 to 13271361
  writeRegister(0x40, 0x04); // TX Buffer - 13271375 to 13271508
  writeRegister(0x41, 0x0E); // TX Buffer - 13271522 to 13271657
  writeRegister(0x44, 0x23); // TX Buffer - 13271671 to 13271805
  writeRegister(0x45, 0x11); // TX Buffer - 13271819 to 13271955
  writeRegister(0x46, 0x13); // TX Buffer - 13271968 to 13272104
  writeRegister(0x04, 0x07); // TX - 13272116 to 13272252
  writeRegister(0x00, 0xFF); // CS0 - 13278894 to 13279035
  writeRegister(0x01, 0xFF); // CS1 - 13279047 to 13279192
  writeRegister(0x16, 0xC0); // FIFO CTRL - 13279198 to 13279336
  writeRegister(0x40, 0x04); // TX Buffer - 13279346 to 13279481
  writeRegister(0x41, 0x0E); // TX Buffer - 13279493 to 13279628
  writeRegister(0x44, 0x23); // TX Buffer - 13279642 to 13279776
  writeRegister(0x45, 0x11); // TX Buffer - 13279790 to 13279926
  writeRegister(0x46, 0x13); // TX Buffer - 13279939 to 13280075
  writeRegister(0x04, 0x07); // TX - 13280088 to 13280223
  writeRegister(0x00, 0xFF); // CS0 - 13286869 to 13287012
  writeRegister(0x01, 0xFF); // CS1 - 13287018 to 13287160
  writeRegister(0x16, 0xC0); // FIFO CTRL - 13287172 to 13287307
  writeRegister(0x40, 0x04); // TX Buffer - 13287321 to 13287454
  writeRegister(0x41, 0x0E); // TX Buffer - 13287464 to 13287602
  writeRegister(0x44, 0x23); // TX Buffer - 13287613 to 13287752
  writeRegister(0x45, 0x11); // TX Buffer - 13287761 to 13287899
  writeRegister(0x46, 0x13); // TX Buffer - 13287910 to 13288048
  writeRegister(0x04, 0x07); // TX - 13288059 to 13288196
  writeRegister(0x00, 0xFF); // CS0 - 13294924 to 13295065
  writeRegister(0x01, 0xFF); // CS1 - 13295074 to 13295214
  writeRegister(0x16, 0xC0); // FIFO CTRL - 13295228 to 13295363
  writeRegister(0x40, 0x04); // TX Buffer - 13295377 to 13295510
  writeRegister(0x41, 0x0E); // TX Buffer - 13295520 to 13295658
  writeRegister(0x44, 0x23); // TX Buffer - 13295669 to 13295808
  writeRegister(0x45, 0x11); // TX Buffer - 13295817 to 13295955
  writeRegister(0x46, 0x13); // TX Buffer - 13295965 to 13296104
  writeRegister(0x04, 0x07); // TX - 13296118 to 13296253
  writeRegister(0x00, 0xFF); // CS0 - 13302895 to 13303036
  writeRegister(0x01, 0xFF); // CS1 - 13303049 to 13303193
  writeRegister(0x16, 0xC0); // FIFO CTRL - 13303199 to 13303340
  writeRegister(0x40, 0x04); // TX Buffer - 13303348 to 13303481
  writeRegister(0x41, 0x0E); // TX Buffer - 13303495 to 13303629
  writeRegister(0x44, 0x23); // TX Buffer - 13303643 to 13303779
  writeRegister(0x45, 0x11); // TX Buffer - 13303791 to 13303926
  writeRegister(0x46, 0x13); // TX Buffer - 13303940 to 13304075
  writeRegister(0x04, 0x07); // TX - 13304089 to 13304223
  writeRegister(0x00, 0xFF); // CS0 - 13310862 to 13310999
  writeRegister(0x01, 0xFF); // CS1 - 13311012 to 13311153
  writeRegister(0x16, 0xC0); // FIFO CTRL - 13311162 to 13311300
  writeRegister(0x40, 0x04); // TX Buffer - 13311311 to 13311450
  writeRegister(0x41, 0x0E); // TX Buffer - 13311458 to 13311600
  writeRegister(0x44, 0x23); // TX Buffer - 13311606 to 13311748
  writeRegister(0x45, 0x11); // TX Buffer - 13311754 to 13311897
  writeRegister(0x46, 0x13); // TX Buffer - 13311903 to 13312046
  writeRegister(0x04, 0x07); // TX - 13312052 to 13312194
  writeRegister(0x00, 0xFF); // CS0 - 13318918 to 13319061
  writeRegister(0x01, 0xFF); // CS1 - 13319068 to 13319209
  writeRegister(0x16, 0xC0); // FIFO CTRL - 13319221 to 13319356
  writeRegister(0x40, 0x04); // TX Buffer - 13319370 to 13319503
  writeRegister(0x41, 0x0E); // TX Buffer - 13319513 to 13319653
  writeRegister(0x44, 0x23); // TX Buffer - 13319662 to 13319804
  writeRegister(0x45, 0x11); // TX Buffer - 13319810 to 13319952
  writeRegister(0x46, 0x13); // TX Buffer - 13319959 to 13320097
  writeRegister(0x04, 0x07); // TX - 13320108 to 13320249
  writeRegister(0x00, 0xFF); // CS0 - 13326889 to 13327028
  writeRegister(0x01, 0xFF); // CS1 - 13327042 to 13327180
  writeRegister(0x16, 0xC0); // FIFO CTRL - 13327192 to 13327327
  writeRegister(0x40, 0x04); // TX Buffer - 13327341 to 13327474
  writeRegister(0x41, 0x0E); // TX Buffer - 13327488 to 13327623
  writeRegister(0x44, 0x23); // TX Buffer - 13327636 to 13327772
  writeRegister(0x45, 0x11); // TX Buffer - 13327785 to 13327919
  writeRegister(0x46, 0x13); // TX Buffer - 13327933 to 13328068
  writeRegister(0x04, 0x07); // TX - 13328082 to 13328216
  writeRegister(0x00, 0xFF); // CS0 - 13334863 to 13334999
  writeRegister(0x01, 0xFF); // CS1 - 13335013 to 13335153
  writeRegister(0x16, 0xC0); // FIFO CTRL - 13335163 to 13335302
  writeRegister(0x40, 0x04); // TX Buffer - 13335312 to 13335445
  writeRegister(0x41, 0x0E); // TX Buffer - 13335459 to 13335594
  writeRegister(0x44, 0x23); // TX Buffer - 13335607 to 13335742
  writeRegister(0x45, 0x11); // TX Buffer - 13335756 to 13335892
  writeRegister(0x46, 0x13); // TX Buffer - 13335904 to 13336047
  writeRegister(0x04, 0x07); // TX - 13336053 to 13336187
  writeRegister(0x00, 0xFF); // CS0 - 13342919 to 13343055
  writeRegister(0x01, 0xFF); // CS1 - 13343069 to 13343210
  writeRegister(0x16, 0xC0); // FIFO CTRL - 13343219 to 13343357
  writeRegister(0x40, 0x04); // TX Buffer - 13343368 to 13343507
  writeRegister(0x41, 0x0E); // TX Buffer - 13343515 to 13343657
  writeRegister(0x44, 0x23); // TX Buffer - 13343663 to 13343805
  writeRegister(0x45, 0x11); // TX Buffer - 13343812 to 13343954
  writeRegister(0x46, 0x13); // TX Buffer - 13343960 to 13344103
  writeRegister(0x04, 0x07); // TX - 13344109 to 13344251
  writeRegister(0x00, 0xFF); // CS0 - 13350890 to 13351031
  writeRegister(0x01, 0xFF); // CS1 - 13351040 to 13351181
  writeRegister(0x16, 0xC0); // FIFO CTRL - 13351194 to 13351328
  writeRegister(0x40, 0x04); // TX Buffer - 13351342 to 13351475
  writeRegister(0x41, 0x0E); // TX Buffer - 13351489 to 13351624
  writeRegister(0x44, 0x23); // TX Buffer - 13351638 to 13351772
  writeRegister(0x45, 0x11); // TX Buffer - 13351786 to 13351922
  writeRegister(0x46, 0x13); // TX Buffer - 13351935 to 13352071
  writeRegister(0x04, 0x07); // TX - 13352083 to 13352219
  writeRegister(0x00, 0xFF); // CS0 - 13358861 to 13359002
  writeRegister(0x01, 0xFF); // CS1 - 13359014 to 13359157
  writeRegister(0x16, 0xC0); // FIFO CTRL - 13359165 to 13359303
  writeRegister(0x40, 0x04); // TX Buffer - 13359313 to 13359448
  writeRegister(0x41, 0x0E); // TX Buffer - 13359460 to 13359595
  writeRegister(0x44, 0x23); // TX Buffer - 13359609 to 13359743
  writeRegister(0x45, 0x11); // TX Buffer - 13359757 to 13359893
  writeRegister(0x46, 0x13); // TX Buffer - 13359906 to 13360042
  writeRegister(0x04, 0x07); // TX - 13360055 to 13360190
  writeRegister(0x00, 0xFF); // CS0 - 13366920 to 13367056
  writeRegister(0x01, 0xFF); // CS1 - 13367070 to 13367210
  writeRegister(0x16, 0xC0); // FIFO CTRL - 13367221 to 13367359
  writeRegister(0x40, 0x04); // TX Buffer - 13367369 to 13367502
  writeRegister(0x41, 0x0E); // TX Buffer - 13367516 to 13367651
  writeRegister(0x44, 0x23); // TX Buffer - 13367664 to 13367799
  writeRegister(0x45, 0x11); // TX Buffer - 13367813 to 13367949
  writeRegister(0x46, 0x13); // TX Buffer - 13367961 to 13368104
  writeRegister(0x04, 0x07); // TX - 13368110 to 13368246
  writeRegister(0x00, 0xFF); // CS0 - 13374891 to 13375032
  writeRegister(0x01, 0xFF); // CS1 - 13375041 to 13375181
  writeRegister(0x16, 0xC0); // FIFO CTRL - 13375195 to 13375330
  writeRegister(0x40, 0x04); // TX Buffer - 13375344 to 13375477
  writeRegister(0x41, 0x0E); // TX Buffer - 13375487 to 13375625
  writeRegister(0x44, 0x23); // TX Buffer - 13375636 to 13375775
  writeRegister(0x45, 0x11); // TX Buffer - 13375784 to 13375922
  writeRegister(0x46, 0x13); // TX Buffer - 13375932 to 13376071
  writeRegister(0x04, 0x07); // TX - 13376085 to 13376220
  writeRegister(0x00, 0xFF); // CS0 - 13382862 to 13383003
  writeRegister(0x01, 0xFF); // CS1 - 13383016 to 13383160
  writeRegister(0x16, 0xC0); // FIFO CTRL - 13383166 to 13383307
  writeRegister(0x40, 0x04); // TX Buffer - 13383315 to 13383448
  writeRegister(0x41, 0x0E); // TX Buffer - 13383462 to 13383596
  writeRegister(0x44, 0x23); // TX Buffer - 13383610 to 13383746
  writeRegister(0x45, 0x11); // TX Buffer - 13383758 to 13383893
  writeRegister(0x46, 0x13); // TX Buffer - 13383907 to 13384042
  writeRegister(0x04, 0x07); // TX - 13384056 to 13384190
  writeRegister(0x00, 0xFF); // CS0 - 13390918 to 13391059
  writeRegister(0x01, 0xFF); // CS1 - 13391072 to 13391216
  writeRegister(0x16, 0xC0); // FIFO CTRL - 13391222 to 13391360
  writeRegister(0x40, 0x04); // TX Buffer - 13391370 to 13391504
  writeRegister(0x41, 0x0E); // TX Buffer - 13391517 to 13391652
  writeRegister(0x44, 0x23); // TX Buffer - 13391666 to 13391802
  writeRegister(0x45, 0x11); // TX Buffer - 13391814 to 13391950
  writeRegister(0x46, 0x13); // TX Buffer - 13391963 to 13392099
  writeRegister(0x04, 0x07); // TX - 13392112 to 13392247
  writeRegister(0x00, 0xFF); // CS0 - 13398893 to 13399036
  writeRegister(0x01, 0xFF); // CS1 - 13399043 to 13399184
  writeRegister(0x16, 0xC0); // FIFO CTRL - 13399196 to 13399331
  writeRegister(0x40, 0x04); // TX Buffer - 13399345 to 13399478
  writeRegister(0x41, 0x0E); // TX Buffer - 13399488 to 13399628
  writeRegister(0x44, 0x23); // TX Buffer - 13399637 to 13399776
  writeRegister(0x45, 0x11); // TX Buffer - 13399785 to 13399923
  writeRegister(0x46, 0x13); // TX Buffer - 13399934 to 13400072
  writeRegister(0x04, 0x07); // TX - 13400083 to 13400220
  writeRegister(0x00, 0xFF); // CS0 - 13406864 to 13407003
  writeRegister(0x01, 0xFF); // CS1 - 13407017 to 13407155
  writeRegister(0x16, 0xC0); // FIFO CTRL - 13407167 to 13407302
  writeRegister(0x40, 0x04); // TX Buffer - 13407316 to 13407449
  writeRegister(0x41, 0x0E); // TX Buffer - 13407463 to 13407598
  writeRegister(0x44, 0x23); // TX Buffer - 13407611 to 13407746
  writeRegister(0x45, 0x11); // TX Buffer - 13407760 to 13407896
  writeRegister(0x46, 0x13); // TX Buffer - 13407908 to 13408043
  writeRegister(0x04, 0x07); // TX - 13408057 to 13408191
  writeRegister(0x00, 0xFF); // CS0 - 13414920 to 13415059
  writeRegister(0x01, 0xFF); // CS1 - 13415073 to 13415217
  writeRegister(0x16, 0xC0); // FIFO CTRL - 13415223 to 13415364
  writeRegister(0x40, 0x04); // TX Buffer - 13415372 to 13415505
  writeRegister(0x41, 0x0E); // TX Buffer - 13415519 to 13415653
  writeRegister(0x44, 0x23); // TX Buffer - 13415667 to 13415803
  writeRegister(0x45, 0x11); // TX Buffer - 13415816 to 13415950
  writeRegister(0x46, 0x13); // TX Buffer - 13415964 to 13416099
  writeRegister(0x04, 0x07); // TX - 13416113 to 13416247
  writeRegister(0x00, 0xFF); // CS0 - 13422894 to 13423030
  writeRegister(0x01, 0xFF); // CS1 - 13423044 to 13423185
  writeRegister(0x16, 0xC0); // FIFO CTRL - 13423198 to 13423332
  writeRegister(0x40, 0x04); // TX Buffer - 13423346 to 13423479
  writeRegister(0x41, 0x0E); // TX Buffer - 13423490 to 13423628
  writeRegister(0x44, 0x23); // TX Buffer - 13423638 to 13423780
  writeRegister(0x45, 0x11); // TX Buffer - 13423787 to 13423929
  writeRegister(0x46, 0x13); // TX Buffer - 13423935 to 13424075
  writeRegister(0x04, 0x07); // TX - 13424084 to 13424226
  writeRegister(0x00, 0xFF); // CS0 - 13430865 to 13431006
  writeRegister(0x01, 0xFF); // CS1 - 13431015 to 13431155
  writeRegister(0x16, 0xC0); // FIFO CTRL - 13431169 to 13431303
  writeRegister(0x40, 0x04); // TX Buffer - 13431317 to 13431450
  writeRegister(0x41, 0x0E); // TX Buffer - 13431464 to 13431599
  writeRegister(0x44, 0x23); // TX Buffer - 13431613 to 13431747
  writeRegister(0x45, 0x11); // TX Buffer - 13431761 to 13431897
  writeRegister(0x46, 0x13); // TX Buffer - 13431910 to 13432046
  writeRegister(0x04, 0x07); // TX - 13432058 to 13432194
  writeRegister(0x00, 0xFF); // CS0 - 13438921 to 13439060
  writeRegister(0x01, 0xFF); // CS1 - 13439074 to 13439212
  writeRegister(0x16, 0xC0); // FIFO CTRL - 13439225 to 13439359
  writeRegister(0x40, 0x04); // TX Buffer - 13439373 to 13439506
  writeRegister(0x41, 0x0E); // TX Buffer - 13439520 to 13439655
  writeRegister(0x44, 0x23); // TX Buffer - 13439668 to 13439803
  writeRegister(0x45, 0x11); // TX Buffer - 13439817 to 13439953
  writeRegister(0x46, 0x13); // TX Buffer - 13439965 to 13440102
  writeRegister(0x04, 0x07); // TX - 13440114 to 13440250
  writeRegister(0x00, 0xFF); // CS0 - 13446895 to 13447031
  writeRegister(0x01, 0xFF); // CS1 - 13447045 to 13447185
  writeRegister(0x16, 0xC0); // FIFO CTRL - 13447196 to 13447334
  writeRegister(0x40, 0x04); // TX Buffer - 13447344 to 13447477
  writeRegister(0x41, 0x0E); // TX Buffer - 13447491 to 13447626
  writeRegister(0x44, 0x23); // TX Buffer - 13447640 to 13447774
  writeRegister(0x45, 0x11); // TX Buffer - 13447788 to 13447924
  writeRegister(0x46, 0x13); // TX Buffer - 13447936 to 13448079
  writeRegister(0x04, 0x07); // TX - 13448085 to 13448221
  writeRegister(0x00, 0xFF); // CS0 - 13454866 to 13455007
  writeRegister(0x01, 0xFF); // CS1 - 13455016 to 13455156
  writeRegister(0x16, 0xC0); // FIFO CTRL - 13455170 to 13455305
  writeRegister(0x40, 0x04); // TX Buffer - 13455319 to 13455452
  writeRegister(0x41, 0x0E); // TX Buffer - 13455462 to 13455600
  writeRegister(0x44, 0x23); // TX Buffer - 13455611 to 13455750
  writeRegister(0x45, 0x11); // TX Buffer - 13455759 to 13455897
  writeRegister(0x46, 0x13); // TX Buffer - 13455907 to 13456046
  writeRegister(0x04, 0x07); // TX - 13456060 to 13456195
  writeRegister(0x00, 0xFF); // CS0 - 13462922 to 13463063
  writeRegister(0x01, 0xFF); // CS1 - 13463072 to 13463212
  writeRegister(0x16, 0xC0); // FIFO CTRL - 13463226 to 13463361
  writeRegister(0x40, 0x04); // TX Buffer - 13463374 to 13463508
  writeRegister(0x41, 0x0E); // TX Buffer - 13463521 to 13463656
  writeRegister(0x44, 0x23); // TX Buffer - 13463670 to 13463804
  writeRegister(0x45, 0x11); // TX Buffer - 13463818 to 13463954
  writeRegister(0x46, 0x13); // TX Buffer - 13463967 to 13464103
  writeRegister(0x04, 0x07); // TX - 13464116 to 13464251
  writeRegister(0x00, 0xFF); // CS0 - 13470897 to 13471034
  writeRegister(0x01, 0xFF); // CS1 - 13471047 to 13471188
  writeRegister(0x16, 0xC0); // FIFO CTRL - 13471197 to 13471335
  writeRegister(0x40, 0x04); // TX Buffer - 13471345 to 13471479
  writeRegister(0x41, 0x0E); // TX Buffer - 13471492 to 13471627
  writeRegister(0x44, 0x23); // TX Buffer - 13471641 to 13471777
  writeRegister(0x45, 0x11); // TX Buffer - 13471789 to 13471925
  writeRegister(0x46, 0x13); // TX Buffer - 13471938 to 13472074
  writeRegister(0x04, 0x07); // TX - 13472087 to 13472222
  writeRegister(0x00, 0xFF); // CS0 - 13478868 to 13479011
  writeRegister(0x01, 0xFF); // CS1 - 13479018 to 13479159
  writeRegister(0x16, 0xC0); // FIFO CTRL - 13479171 to 13479306
  writeRegister(0x40, 0x04); // TX Buffer - 13479320 to 13479453
  writeRegister(0x41, 0x0E); // TX Buffer - 13479463 to 13479602
  writeRegister(0x44, 0x23); // TX Buffer - 13479612 to 13479751
  writeRegister(0x45, 0x11); // TX Buffer - 13479760 to 13479898
  writeRegister(0x46, 0x13); // TX Buffer - 13479909 to 13480047
  writeRegister(0x04, 0x07); // TX - 13480058 to 13480195
  writeRegister(0x00, 0xFF); // CS0 - 13486923 to 13487063
  writeRegister(0x01, 0xFF); // CS1 - 13487073 to 13487213
  writeRegister(0x16, 0xC0); // FIFO CTRL - 13487227 to 13487362
  writeRegister(0x40, 0x04); // TX Buffer - 13487376 to 13487509
  writeRegister(0x41, 0x0E); // TX Buffer - 13487519 to 13487657
  writeRegister(0x44, 0x23); // TX Buffer - 13487668 to 13487807
  writeRegister(0x45, 0x11); // TX Buffer - 13487816 to 13487954
  writeRegister(0x46, 0x13); // TX Buffer - 13487965 to 13488103
  writeRegister(0x04, 0x07); // TX - 13488117 to 13488251
  writeRegister(0x00, 0xFF); // CS0 - 13494895 to 13495034
  writeRegister(0x01, 0xFF); // CS1 - 13495048 to 13495192
  writeRegister(0x16, 0xC0); // FIFO CTRL - 13495198 to 13495336
  writeRegister(0x40, 0x04); // TX Buffer - 13495347 to 13495480
  writeRegister(0x41, 0x0E); // TX Buffer - 13495494 to 13495628
  writeRegister(0x44, 0x23); // TX Buffer - 13495642 to 13495778
  writeRegister(0x45, 0x11); // TX Buffer - 13495791 to 13495925
  writeRegister(0x46, 0x13); // TX Buffer - 13495939 to 13496074
  writeRegister(0x04, 0x07); // TX - 13496088 to 13496222
  writeRegister(0x00, 0xFF); // CS0 - 13502869 to 13503013
  writeRegister(0x01, 0xFF); // CS1 - 13503019 to 13503160
  writeRegister(0x16, 0xC0); // FIFO CTRL - 13503173 to 13503307
  writeRegister(0x40, 0x04); // TX Buffer - 13503321 to 13503454
  writeRegister(0x41, 0x0E); // TX Buffer - 13503465 to 13503603
  writeRegister(0x44, 0x23); // TX Buffer - 13503613 to 13503755
  writeRegister(0x45, 0x11); // TX Buffer - 13503762 to 13503904
  writeRegister(0x46, 0x13); // TX Buffer - 13503910 to 13504050
  writeRegister(0x04, 0x07); // TX - 13504059 to 13504201
  writeRegister(0x00, 0xFF); // CS0 - 13510925 to 13511068
  writeRegister(0x01, 0xFF); // CS1 - 13511075 to 13511216
  writeRegister(0x16, 0xC0); // FIFO CTRL - 13511229 to 13511363
  writeRegister(0x40, 0x04); // TX Buffer - 13511377 to 13511510
  writeRegister(0x41, 0x0E); // TX Buffer - 13511521 to 13511659
  writeRegister(0x44, 0x23); // TX Buffer - 13511669 to 13511807
  writeRegister(0x45, 0x11); // TX Buffer - 13511817 to 13511957
  writeRegister(0x46, 0x13); // TX Buffer - 13511966 to 13512106
  writeRegister(0x04, 0x07); // TX - 13512115 to 13512252
  writeRegister(0x00, 0xFF); // CS0 - 13518896 to 13519035
  writeRegister(0x01, 0xFF); // CS1 - 13519049 to 13519187
  writeRegister(0x16, 0xC0); // FIFO CTRL - 13519200 to 13519334
  writeRegister(0x40, 0x04); // TX Buffer - 13519348 to 13519481
  writeRegister(0x41, 0x0E); // TX Buffer - 13519495 to 13519630
  writeRegister(0x44, 0x23); // TX Buffer - 13519643 to 13519778
  writeRegister(0x45, 0x11); // TX Buffer - 13519792 to 13519928
  writeRegister(0x46, 0x13); // TX Buffer - 13519940 to 13520077
  writeRegister(0x04, 0x07); // TX - 13520089 to 13520225
  writeRegister(0x00, 0xFF); // CS0 - 13526870 to 13527008
  writeRegister(0x01, 0xFF); // CS1 - 13527020 to 13527160
  writeRegister(0x16, 0xC0); // FIFO CTRL - 13527171 to 13527309
  writeRegister(0x40, 0x04); // TX Buffer - 13527319 to 13527460
  writeRegister(0x41, 0x0E); // TX Buffer - 13527466 to 13527607
  writeRegister(0x44, 0x23); // TX Buffer - 13527615 to 13527757
  writeRegister(0x45, 0x11); // TX Buffer - 13527763 to 13527905
  writeRegister(0x46, 0x13); // TX Buffer - 13527911 to 13528054
  writeRegister(0x04, 0x07); // TX - 13528060 to 13528202
  writeRegister(0x00, 0xFF); // CS0 - 13534926 to 13535070
  writeRegister(0x01, 0xFF); // CS1 - 13535076 to 13535216
  writeRegister(0x16, 0xC0); // FIFO CTRL - 13535230 to 13535365
  writeRegister(0x40, 0x04); // TX Buffer - 13535378 to 13535513
  writeRegister(0x41, 0x0E); // TX Buffer - 13535522 to 13535660
  writeRegister(0x44, 0x23); // TX Buffer - 13535670 to 13535812
  writeRegister(0x45, 0x11); // TX Buffer - 13535819 to 13535961
  writeRegister(0x46, 0x13); // TX Buffer - 13535967 to 13536107
  writeRegister(0x04, 0x07); // TX - 13536116 to 13536258
  writeRegister(0x00, 0xFF); // CS0 - 13542897 to 13543038
  writeRegister(0x01, 0xFF); // CS1 - 13543051 to 13543187
  writeRegister(0x16, 0xC0); // FIFO CTRL - 13543201 to 13543336
  writeRegister(0x40, 0x04); // TX Buffer - 13543349 to 13543483
  writeRegister(0x41, 0x0E); // TX Buffer - 13543496 to 13543631
  writeRegister(0x44, 0x23); // TX Buffer - 13543645 to 13543781
  writeRegister(0x45, 0x11); // TX Buffer - 13543793 to 13543929
  writeRegister(0x46, 0x13); // TX Buffer - 13543942 to 13544078
  writeRegister(0x04, 0x07); // TX - 13544091 to 13544226
  writeRegister(0x00, 0xFF); // CS0 - 13550872 to 13551009
  writeRegister(0x01, 0xFF); // CS1 - 13551022 to 13551163
  writeRegister(0x16, 0xC0); // FIFO CTRL - 13551172 to 13551310
  writeRegister(0x40, 0x04); // TX Buffer - 13551320 to 13551454
  writeRegister(0x41, 0x0E); // TX Buffer - 13551467 to 13551602
  writeRegister(0x44, 0x23); // TX Buffer - 13551616 to 13551752
  writeRegister(0x45, 0x11); // TX Buffer - 13551764 to 13551900
  writeRegister(0x46, 0x13); // TX Buffer - 13551913 to 13552055
  writeRegister(0x04, 0x07); // TX - 13552062 to 13552197
  writeRegister(0x00, 0xFF); // CS0 - 13558927 to 13559065
  writeRegister(0x01, 0xFF); // CS1 - 13559077 to 13559217
  writeRegister(0x16, 0xC0); // FIFO CTRL - 13559228 to 13559366
  writeRegister(0x40, 0x04); // TX Buffer - 13559376 to 13559517
  writeRegister(0x41, 0x0E); // TX Buffer - 13559523 to 13559664
  writeRegister(0x44, 0x23); // TX Buffer - 13559672 to 13559814
  writeRegister(0x45, 0x11); // TX Buffer - 13559820 to 13559962
  writeRegister(0x46, 0x13); // TX Buffer - 13559969 to 13560111
  writeRegister(0x04, 0x07); // TX - 13560117 to 13560259
  writeRegister(0x00, 0xFF); // CS0 - 13566899 to 13567038
  writeRegister(0x01, 0xFF); // CS1 - 13567048 to 13567190
  writeRegister(0x16, 0xC0); // FIFO CTRL - 13567202 to 13567337
  writeRegister(0x40, 0x04); // TX Buffer - 13567351 to 13567484
  writeRegister(0x41, 0x0E); // TX Buffer - 13567498 to 13567632
  writeRegister(0x44, 0x23); // TX Buffer - 13567646 to 13567782
  writeRegister(0x45, 0x11); // TX Buffer - 13567795 to 13567929
  writeRegister(0x46, 0x13); // TX Buffer - 13567943 to 13568078
  writeRegister(0x04, 0x07); // TX - 13568092 to 13568226
  writeRegister(0x00, 0xFF); // CS0 - 13574870 to 13575009
  writeRegister(0x01, 0xFF); // CS1 - 13575023 to 13575167
  writeRegister(0x16, 0xC0); // FIFO CTRL - 13575173 to 13575311
  writeRegister(0x40, 0x04); // TX Buffer - 13575322 to 13575455
  writeRegister(0x41, 0x0E); // TX Buffer - 13575469 to 13575603
  writeRegister(0x44, 0x23); // TX Buffer - 13575617 to 13575753
  writeRegister(0x45, 0x11); // TX Buffer - 13575766 to 13575900
  writeRegister(0x46, 0x13); // TX Buffer - 13575914 to 13576049
  writeRegister(0x04, 0x07); // TX - 13576063 to 13576197
  writeRegister(0x00, 0xFF); // CS0 - 13582929 to 13583066
  writeRegister(0x01, 0xFF); // CS1 - 13583079 to 13583220
  writeRegister(0x16, 0xC0); // FIFO CTRL - 13583229 to 13583367
  writeRegister(0x40, 0x04); // TX Buffer - 13583378 to 13583511
  writeRegister(0x41, 0x0E); // TX Buffer - 13583525 to 13583659
  writeRegister(0x44, 0x23); // TX Buffer - 13583673 to 13583809
  writeRegister(0x45, 0x11); // TX Buffer - 13583821 to 13583956
  writeRegister(0x46, 0x13); // TX Buffer - 13583970 to 13584111
  writeRegister(0x04, 0x07); // TX - 13584119 to 13584254
  writeRegister(0x00, 0xFF); // CS0 - 13590900 to 13591039
  writeRegister(0x01, 0xFF); // CS1 - 13591050 to 13591191
  writeRegister(0x16, 0xC0); // FIFO CTRL - 13591204 to 13591338
  writeRegister(0x40, 0x04); // TX Buffer - 13591352 to 13591485
  writeRegister(0x41, 0x0E); // TX Buffer - 13591496 to 13591634
  writeRegister(0x44, 0x23); // TX Buffer - 13591644 to 13591782
  writeRegister(0x45, 0x11); // TX Buffer - 13591792 to 13591932
  writeRegister(0x46, 0x13); // TX Buffer - 13591941 to 13592081
  writeRegister(0x04, 0x07); // TX - 13592093 to 13592229
  writeRegister(0x00, 0xFF); // CS0 - 13598871 to 13599010
  writeRegister(0x01, 0xFF); // CS1 - 13599024 to 13599168
  writeRegister(0x16, 0xC0); // FIFO CTRL - 13599175 to 13599317
  writeRegister(0x40, 0x04); // TX Buffer - 13599323 to 13599456
  writeRegister(0x41, 0x0E); // TX Buffer - 13599470 to 13599605
  writeRegister(0x44, 0x23); // TX Buffer - 13599618 to 13599753
  writeRegister(0x45, 0x11); // TX Buffer - 13599767 to 13599903
  writeRegister(0x46, 0x13); // TX Buffer - 13599915 to 13600052
  writeRegister(0x04, 0x07); // TX - 13600064 to 13600200
  writeRegister(0x00, 0xFF); // CS0 - 13606927 to 13607066
  writeRegister(0x01, 0xFF); // CS1 - 13607080 to 13607224
  writeRegister(0x16, 0xC0); // FIFO CTRL - 13607230 to 13607370
  writeRegister(0x40, 0x04); // TX Buffer - 13607379 to 13607512
  writeRegister(0x41, 0x0E); // TX Buffer - 13607526 to 13607662
  writeRegister(0x44, 0x23); // TX Buffer - 13607674 to 13607810
  writeRegister(0x45, 0x11); // TX Buffer - 13607823 to 13607957
  writeRegister(0x46, 0x13); // TX Buffer - 13607971 to 13608106
  writeRegister(0x04, 0x07); // TX - 13608120 to 13608254
  writeRegister(0x00, 0xFF); // CS0 - 13614901 to 13615045
  writeRegister(0x01, 0xFF); // CS1 - 13615051 to 13615191
  writeRegister(0x16, 0xC0); // FIFO CTRL - 13615205 to 13615340
  writeRegister(0x40, 0x04); // TX Buffer - 13615353 to 13615487
  writeRegister(0x41, 0x0E); // TX Buffer - 13615497 to 13615635
  writeRegister(0x44, 0x23); // TX Buffer - 13615645 to 13615783
  writeRegister(0x45, 0x11); // TX Buffer - 13615794 to 13615933
  writeRegister(0x46, 0x13); // TX Buffer - 13615942 to 13616082
  writeRegister(0x04, 0x07); // TX - 13616091 to 13616230
  writeRegister(0x00, 0xFF); // CS0 - 13622872 to 13623013
  writeRegister(0x01, 0xFF); // CS1 - 13623026 to 13623162
  writeRegister(0x16, 0xC0); // FIFO CTRL - 13623176 to 13623311
  writeRegister(0x40, 0x04); // TX Buffer - 13623324 to 13623458
  writeRegister(0x41, 0x0E); // TX Buffer - 13623471 to 13623606
  writeRegister(0x44, 0x23); // TX Buffer - 13623620 to 13623756
  writeRegister(0x45, 0x11); // TX Buffer - 13623768 to 13623904
  writeRegister(0x46, 0x13); // TX Buffer - 13623917 to 13624053
  writeRegister(0x04, 0x07); // TX - 13624066 to 13624201
  writeRegister(0x00, 0xFF); // CS0 - 13630928 to 13631069
  writeRegister(0x01, 0xFF); // CS1 - 13631081 to 13631225
  writeRegister(0x16, 0xC0); // FIFO CTRL - 13631232 to 13631374
  writeRegister(0x40, 0x04); // TX Buffer - 13631380 to 13631513
  writeRegister(0x41, 0x0E); // TX Buffer - 13631527 to 13631662
  writeRegister(0x44, 0x23); // TX Buffer - 13631676 to 13631810
  writeRegister(0x45, 0x11); // TX Buffer - 13631824 to 13631960
  writeRegister(0x46, 0x13); // TX Buffer - 13631973 to 13632109
  writeRegister(0x04, 0x07); // TX - 13632121 to 13632257
  writeRegister(0x00, 0xFF); // CS0 - 13638902 to 13639040
  writeRegister(0x01, 0xFF); // CS1 - 13639052 to 13639192
  writeRegister(0x16, 0xC0); // FIFO CTRL - 13639206 to 13639341
  writeRegister(0x40, 0x04); // TX Buffer - 13639355 to 13639488
  writeRegister(0x41, 0x0E); // TX Buffer - 13639498 to 13639636
  writeRegister(0x44, 0x23); // TX Buffer - 13639647 to 13639789
  writeRegister(0x45, 0x11); // TX Buffer - 13639795 to 13639937
  writeRegister(0x46, 0x13); // TX Buffer - 13639944 to 13640082
  writeRegister(0x04, 0x07); // TX - 13640093 to 13640234
  writeRegister(0x00, 0xFF); // CS0 - 13646958 to 13647102
  writeRegister(0x01, 0xFF); // CS1 - 13647108 to 13647248
  writeRegister(0x16, 0xC0); // FIFO CTRL - 13647262 to 13647397
  writeRegister(0x40, 0x04); // TX Buffer - 13647410 to 13647544
  writeRegister(0x41, 0x0E); // TX Buffer - 13647554 to 13647692
  writeRegister(0x44, 0x23); // TX Buffer - 13647702 to 13647842
  writeRegister(0x45, 0x11); // TX Buffer - 13647851 to 13647990
  writeRegister(0x46, 0x13); // TX Buffer - 13647999 to 13648139
  writeRegister(0x04, 0x07); // TX - 13648148 to 13648287
  writeRegister(0x00, 0xFF); // CS0 - 13654929 to 13655070
  writeRegister(0x01, 0xFF); // CS1 - 13655083 to 13655219
  writeRegister(0x16, 0xC0); // FIFO CTRL - 13655233 to 13655368
  writeRegister(0x40, 0x04); // TX Buffer - 13655381 to 13655515
  writeRegister(0x41, 0x0E); // TX Buffer - 13655528 to 13655663
  writeRegister(0x44, 0x23); // TX Buffer - 13655677 to 13655813
  writeRegister(0x45, 0x11); // TX Buffer - 13655825 to 13655960
  writeRegister(0x46, 0x13); // TX Buffer - 13655974 to 13656110
  writeRegister(0x04, 0x07); // TX - 13656123 to 13656258
  writeRegister(0x00, 0xFF); // CS0 - 13662904 to 13663041
  writeRegister(0x01, 0xFF); // CS1 - 13663054 to 13663195
  writeRegister(0x16, 0xC0); // FIFO CTRL - 13663204 to 13663342
  writeRegister(0x40, 0x04); // TX Buffer - 13663353 to 13663486
  writeRegister(0x41, 0x0E); // TX Buffer - 13663500 to 13663634
  writeRegister(0x44, 0x23); // TX Buffer - 13663648 to 13663784
  writeRegister(0x45, 0x11); // TX Buffer - 13663796 to 13663931
  writeRegister(0x46, 0x13); // TX Buffer - 13663945 to 13664088
  writeRegister(0x04, 0x07); // TX - 13664094 to 13664228
  writeRegister(0x00, 0xFF); // CS0 - 13670960 to 13671097
  writeRegister(0x01, 0xFF); // CS1 - 13671109 to 13671251
  writeRegister(0x16, 0xC0); // FIFO CTRL - 13671263 to 13671398
  writeRegister(0x40, 0x04); // TX Buffer - 13671412 to 13671545
  writeRegister(0x41, 0x0E); // TX Buffer - 13671555 to 13671693
  writeRegister(0x44, 0x23); // TX Buffer - 13671704 to 13671846
  writeRegister(0x45, 0x11); // TX Buffer - 13671852 to 13671994
  writeRegister(0x46, 0x13); // TX Buffer - 13672001 to 13672139
  writeRegister(0x04, 0x07); // TX - 13672150 to 13672291
  writeRegister(0x00, 0xFF); // CS0 - 13678931 to 13679070
  writeRegister(0x01, 0xFF); // CS1 - 13679081 to 13679222
  writeRegister(0x16, 0xC0); // FIFO CTRL - 13679234 to 13679369
  writeRegister(0x40, 0x04); // TX Buffer - 13679383 to 13679516
  writeRegister(0x41, 0x0E); // TX Buffer - 13679530 to 13679666
  writeRegister(0x44, 0x23); // TX Buffer - 13679678 to 13679814
  writeRegister(0x45, 0x11); // TX Buffer - 13679827 to 13679961
  writeRegister(0x46, 0x13); // TX Buffer - 13679975 to 13680110
  writeRegister(0x04, 0x07); // TX - 13680124 to 13680258
  writeRegister(0x00, 0xFF); // CS0 - 13686905 to 13687041
  writeRegister(0x01, 0xFF); // CS1 - 13687055 to 13687195
  writeRegister(0x16, 0xC0); // FIFO CTRL - 13687205 to 13687344
  writeRegister(0x40, 0x04); // TX Buffer - 13687354 to 13687487
  writeRegister(0x41, 0x0E); // TX Buffer - 13687501 to 13687636
  writeRegister(0x44, 0x23); // TX Buffer - 13687649 to 13687785
  writeRegister(0x45, 0x11); // TX Buffer - 13687798 to 13687932
  writeRegister(0x46, 0x13); // TX Buffer - 13687946 to 13688081
  writeRegister(0x04, 0x07); // TX - 13688095 to 13688229
  writeRegister(0x00, 0xFF); // CS0 - 13694961 to 13695097
  writeRegister(0x01, 0xFF); // CS1 - 13695111 to 13695251
  writeRegister(0x16, 0xC0); // FIFO CTRL - 13695261 to 13695400
  writeRegister(0x40, 0x04); // TX Buffer - 13695410 to 13695551
  writeRegister(0x41, 0x0E); // TX Buffer - 13695557 to 13695698
  writeRegister(0x44, 0x23); // TX Buffer - 13695705 to 13695846
  writeRegister(0x45, 0x11); // TX Buffer - 13695854 to 13695996
  writeRegister(0x46, 0x13); // TX Buffer - 13696002 to 13696145
  writeRegister(0x04, 0x07); // TX - 13696151 to 13696293
  writeRegister(0x00, 0xFF); // CS0 - 13702956 to 13703095
  writeRegister(0x01, 0xFF); // CS1 - 13703106 to 13703247
  writeRegister(0x16, 0xC0); // FIFO CTRL - 13703260 to 13703394
  writeRegister(0x40, 0x05); // TX Buffer - 13703408 to 13703543
  writeRegister(0x41, 0x0E); // TX Buffer - 13703556 to 13703690
  writeRegister(0x44, 0x23); // TX Buffer - 13703704 to 13703840
  writeRegister(0x45, 0x11); // TX Buffer - 13703852 to 13703987
  writeRegister(0x46, 0x13); // TX Buffer - 13704001 to 13704136
  writeRegister(0x04, 0x07); // TX - 13704150 to 13704284
  writeRegister(0x00, 0xFF); // CS0 - 13710923 to 13711060
  writeRegister(0x01, 0xFF); // CS1 - 13711073 to 13711214
  writeRegister(0x16, 0xC0); // FIFO CTRL - 13711223 to 13711361
  writeRegister(0x40, 0x05); // TX Buffer - 13711372 to 13711513
  writeRegister(0x41, 0x0E); // TX Buffer - 13711519 to 13711660
  writeRegister(0x44, 0x23); // TX Buffer - 13711667 to 13711810
  writeRegister(0x45, 0x11); // TX Buffer - 13711816 to 13711958
  writeRegister(0x46, 0x13); // TX Buffer - 13711964 to 13712107
  writeRegister(0x04, 0x07); // TX - 13712113 to 13712255
  writeRegister(0x00, 0xFF); // CS0 - 13718894 to 13719035
  writeRegister(0x01, 0xFF); // CS1 - 13719044 to 13719184
  writeRegister(0x16, 0xC0); // FIFO CTRL - 13719198 to 13719333
  writeRegister(0x40, 0x05); // TX Buffer - 13719347 to 13719480
  writeRegister(0x41, 0x0E); // TX Buffer - 13719494 to 13719629
  writeRegister(0x44, 0x23); // TX Buffer - 13719642 to 13719777
  writeRegister(0x45, 0x11); // TX Buffer - 13719791 to 13719927
  writeRegister(0x46, 0x13); // TX Buffer - 13719939 to 13720076
  writeRegister(0x04, 0x07); // TX - 13720088 to 13720224
  writeRegister(0x00, 0xFF); // CS0 - 13726951 to 13727090
  writeRegister(0x01, 0xFF); // CS1 - 13727104 to 13727242
  writeRegister(0x16, 0xC0); // FIFO CTRL - 13727254 to 13727389
  writeRegister(0x40, 0x05); // TX Buffer - 13727403 to 13727538
  writeRegister(0x41, 0x0E); // TX Buffer - 13727550 to 13727685
  writeRegister(0x44, 0x23); // TX Buffer - 13727699 to 13727833
  writeRegister(0x45, 0x11); // TX Buffer - 13727847 to 13727983
  writeRegister(0x46, 0x13); // TX Buffer - 13727996 to 13728132
  writeRegister(0x04, 0x07); // TX - 13728145 to 13728280
  writeRegister(0x00, 0xFF); // CS0 - 13734926 to 13735069
  writeRegister(0x01, 0xFF); // CS1 - 13735075 to 13735217
  writeRegister(0x16, 0xC0); // FIFO CTRL - 13735229 to 13735364
  writeRegister(0x40, 0x05); // TX Buffer - 13735378 to 13735513
  writeRegister(0x41, 0x0E); // TX Buffer - 13735522 to 13735660
  writeRegister(0x44, 0x23); // TX Buffer - 13735670 to 13735808
  writeRegister(0x45, 0x11); // TX Buffer - 13735819 to 13735958
  writeRegister(0x46, 0x13); // TX Buffer - 13735967 to 13736107
  writeRegister(0x04, 0x07); // TX - 13736116 to 13736255
  writeRegister(0x00, 0xFF); // CS0 - 13742897 to 13743038
  writeRegister(0x01, 0xFF); // CS1 - 13743050 to 13743187
  writeRegister(0x16, 0xC0); // FIFO CTRL - 13743201 to 13743336
  writeRegister(0x40, 0x05); // TX Buffer - 13743349 to 13743483
  writeRegister(0x41, 0x0E); // TX Buffer - 13743497 to 13743633
  writeRegister(0x44, 0x23); // TX Buffer - 13743645 to 13743781
  writeRegister(0x45, 0x11); // TX Buffer - 13743794 to 13743928
  writeRegister(0x46, 0x13); // TX Buffer - 13743942 to 13744077
  writeRegister(0x04, 0x07); // TX - 13744091 to 13744225
  writeRegister(0x00, 0xFF); // CS0 - 13750957 to 13751094
  writeRegister(0x01, 0xFF); // CS1 - 13751107 to 13751248
  writeRegister(0x16, 0xC0); // FIFO CTRL - 13751257 to 13751395
  writeRegister(0x40, 0x05); // TX Buffer - 13751406 to 13751539
  writeRegister(0x41, 0x0E); // TX Buffer - 13751553 to 13751688
  writeRegister(0x44, 0x23); // TX Buffer - 13751702 to 13751836
  writeRegister(0x45, 0x11); // TX Buffer - 13751850 to 13751986
  writeRegister(0x46, 0x13); // TX Buffer - 13751998 to 13752141
  writeRegister(0x04, 0x07); // TX - 13752147 to 13752283
  writeRegister(0x00, 0xFF); // CS0 - 13758928 to 13759069
  writeRegister(0x01, 0xFF); // CS1 - 13759078 to 13759218
  writeRegister(0x16, 0xC0); // FIFO CTRL - 13759232 to 13759367
  writeRegister(0x40, 0x05); // TX Buffer - 13759381 to 13759514
  writeRegister(0x41, 0x0E); // TX Buffer - 13759528 to 13759663
  writeRegister(0x44, 0x23); // TX Buffer - 13759676 to 13759811
  writeRegister(0x45, 0x11); // TX Buffer - 13759825 to 13759961
  writeRegister(0x46, 0x13); // TX Buffer - 13759973 to 13760110
  writeRegister(0x04, 0x07); // TX - 13760122 to 13760258
  writeRegister(0x00, 0xFF); // CS0 - 13766903 to 13767041
  writeRegister(0x01, 0xFF); // CS1 - 13767053 to 13767193
  writeRegister(0x16, 0xC0); // FIFO CTRL - 13767204 to 13767342
  writeRegister(0x40, 0x05); // TX Buffer - 13767352 to 13767487
  writeRegister(0x41, 0x0E); // TX Buffer - 13767500 to 13767634
  writeRegister(0x44, 0x23); // TX Buffer - 13767648 to 13767784
  writeRegister(0x45, 0x11); // TX Buffer - 13767796 to 13767931
  writeRegister(0x46, 0x13); // TX Buffer - 13767945 to 13768088
  writeRegister(0x04, 0x07); // TX - 13768094 to 13768228
  writeRegister(0x00, 0xFF); // CS0 - 13774960 to 13775097
  writeRegister(0x01, 0xFF); // CS1 - 13775110 to 13775251
  writeRegister(0x16, 0xC0); // FIFO CTRL - 13775263 to 13775398
  writeRegister(0x40, 0x05); // TX Buffer - 13775412 to 13775547
  writeRegister(0x41, 0x0E); // TX Buffer - 13775556 to 13775694
  writeRegister(0x44, 0x23); // TX Buffer - 13775704 to 13775842
  writeRegister(0x45, 0x11); // TX Buffer - 13775853 to 13775992
  writeRegister(0x46, 0x13); // TX Buffer - 13776001 to 13776141
  writeRegister(0x04, 0x07); // TX - 13776150 to 13776289
  writeRegister(0x00, 0xFF); // CS0 - 13782931 to 13783072
  writeRegister(0x01, 0xFF); // CS1 - 13783084 to 13783221
  writeRegister(0x16, 0xC0); // FIFO CTRL - 13783235 to 13783370
  writeRegister(0x40, 0x05); // TX Buffer - 13783383 to 13783517
  writeRegister(0x41, 0x0E); // TX Buffer - 13783531 to 13783667
  writeRegister(0x44, 0x23); // TX Buffer - 13783679 to 13783815
  writeRegister(0x45, 0x11); // TX Buffer - 13783828 to 13783962
  writeRegister(0x46, 0x13); // TX Buffer - 13783976 to 13784111
  writeRegister(0x04, 0x07); // TX - 13784125 to 13784259
  writeRegister(0x00, 0xFF); // CS0 - 13790906 to 13791042
  writeRegister(0x01, 0xFF); // CS1 - 13791056 to 13791196
  writeRegister(0x16, 0xC0); // FIFO CTRL - 13791210 to 13791345
  writeRegister(0x40, 0x05); // TX Buffer - 13791358 to 13791492
  writeRegister(0x41, 0x0E); // TX Buffer - 13791502 to 13791642
  writeRegister(0x44, 0x23); // TX Buffer - 13791651 to 13791790
  writeRegister(0x45, 0x11); // TX Buffer - 13791799 to 13791937
  writeRegister(0x46, 0x13); // TX Buffer - 13791948 to 13792086
  writeRegister(0x04, 0x07); // TX - 13792097 to 13792234
  writeRegister(0x00, 0xFF); // CS0 - 13798962 to 13799103
  writeRegister(0x01, 0xFF); // CS1 - 13799112 to 13799252
  writeRegister(0x16, 0xC0); // FIFO CTRL - 13799266 to 13799401
  writeRegister(0x40, 0x05); // TX Buffer - 13799415 to 13799548
  writeRegister(0x41, 0x0E); // TX Buffer - 13799562 to 13799697
  writeRegister(0x44, 0x23); // TX Buffer - 13799711 to 13799845
  writeRegister(0x45, 0x11); // TX Buffer - 13799859 to 13799995
  writeRegister(0x46, 0x13); // TX Buffer - 13800007 to 13800144
  writeRegister(0x04, 0x07); // TX - 13800156 to 13800292
  writeRegister(0x00, 0xFF); // CS0 - 13806934 to 13807075
  writeRegister(0x01, 0xFF); // CS1 - 13807087 to 13807231
  writeRegister(0x16, 0xC0); // FIFO CTRL - 13807238 to 13807376
  writeRegister(0x40, 0x05); // TX Buffer - 13807386 to 13807521
  writeRegister(0x41, 0x0E); // TX Buffer - 13807534 to 13807668
  writeRegister(0x44, 0x23); // TX Buffer - 13807682 to 13807818
  writeRegister(0x45, 0x11); // TX Buffer - 13807831 to 13807965
  writeRegister(0x46, 0x13); // TX Buffer - 13807979 to 13808122
  writeRegister(0x04, 0x07); // TX - 13808128 to 13808262
  writeRegister(0x00, 0xFF); // CS0 - 13814909 to 13815050
  writeRegister(0x01, 0xFF); // CS1 - 13815059 to 13815200
  writeRegister(0x16, 0xC0); // FIFO CTRL - 13815213 to 13815347
  writeRegister(0x40, 0x05); // TX Buffer - 13815361 to 13815496
  writeRegister(0x41, 0x0E); // TX Buffer - 13815509 to 13815643
  writeRegister(0x44, 0x23); // TX Buffer - 13815657 to 13815793
  writeRegister(0x45, 0x11); // TX Buffer - 13815805 to 13815940
  writeRegister(0x46, 0x13); // TX Buffer - 13815954 to 13816089
  writeRegister(0x04, 0x07); // TX - 13816103 to 13816237
  writeRegister(0x00, 0xFF); // CS0 - 13822965 to 13823106
  writeRegister(0x01, 0xFF); // CS1 - 13823119 to 13823255
  writeRegister(0x16, 0xC0); // FIFO CTRL - 13823269 to 13823404
  writeRegister(0x40, 0x05); // TX Buffer - 13823417 to 13823551
  writeRegister(0x41, 0x0E); // TX Buffer - 13823565 to 13823700
  writeRegister(0x44, 0x23); // TX Buffer - 13823713 to 13823849
  writeRegister(0x45, 0x11); // TX Buffer - 13823862 to 13823996
  writeRegister(0x46, 0x13); // TX Buffer - 13824010 to 13824145
  writeRegister(0x04, 0x07); // TX - 13824159 to 13824293
  writeRegister(0x00, 0xFF); // CS0 - 13830940 to 13831076
  writeRegister(0x01, 0xFF); // CS1 - 13831090 to 13831230
  writeRegister(0x16, 0xC0); // FIFO CTRL - 13831240 to 13831379
  writeRegister(0x40, 0x05); // TX Buffer - 13831389 to 13831530
  writeRegister(0x41, 0x0E); // TX Buffer - 13831536 to 13831676
  writeRegister(0x44, 0x23); // TX Buffer - 13831685 to 13831827
  writeRegister(0x45, 0x11); // TX Buffer - 13831833 to 13831975
  writeRegister(0x46, 0x13); // TX Buffer - 13831982 to 13832120
  writeRegister(0x04, 0x07); // TX - 13832131 to 13832272
  writeRegister(0x00, 0xFF); // CS0 - 13838912 to 13839051
  writeRegister(0x01, 0xFF); // CS1 - 13839065 to 13839203
  writeRegister(0x16, 0xC0); // FIFO CTRL - 13839215 to 13839350
  writeRegister(0x40, 0x05); // TX Buffer - 13839364 to 13839499
  writeRegister(0x41, 0x0E); // TX Buffer - 13839511 to 13839646
  writeRegister(0x44, 0x23); // TX Buffer - 13839660 to 13839796
  writeRegister(0x45, 0x11); // TX Buffer - 13839808 to 13839944
  writeRegister(0x46, 0x13); // TX Buffer - 13839957 to 13840093
  writeRegister(0x04, 0x07); // TX - 13840106 to 13840241
  writeRegister(0x00, 0xFF); // CS0 - 13846968 to 13847109
  writeRegister(0x01, 0xFF); // CS1 - 13847121 to 13847265
  writeRegister(0x16, 0xC0); // FIFO CTRL - 13847272 to 13847410
  writeRegister(0x40, 0x05); // TX Buffer - 13847420 to 13847555
  writeRegister(0x41, 0x0E); // TX Buffer - 13847568 to 13847702
  writeRegister(0x44, 0x23); // TX Buffer - 13847716 to 13847852
  writeRegister(0x45, 0x11); // TX Buffer - 13847865 to 13847999
  writeRegister(0x46, 0x13); // TX Buffer - 13848013 to 13848148
  writeRegister(0x04, 0x07); // TX - 13848162 to 13848296
  writeRegister(0x00, 0xFF); // CS0 - 13854943 to 13855087
  writeRegister(0x01, 0xFF); // CS1 - 13855093 to 13855234
  writeRegister(0x16, 0xC0); // FIFO CTRL - 13855247 to 13855381
  writeRegister(0x40, 0x05); // TX Buffer - 13855395 to 13855530
  writeRegister(0x41, 0x0E); // TX Buffer - 13855539 to 13855677
  writeRegister(0x44, 0x23); // TX Buffer - 13855688 to 13855827
  writeRegister(0x45, 0x11); // TX Buffer - 13855836 to 13855974
  writeRegister(0x46, 0x13); // TX Buffer - 13855985 to 13856123
  writeRegister(0x04, 0x07); // TX - 13856137 to 13856271
  writeRegister(0x00, 0xFF); // CS0 - 13862914 to 13863054
  writeRegister(0x01, 0xFF); // CS1 - 13863068 to 13863212
  writeRegister(0x16, 0xC0); // FIFO CTRL - 13863218 to 13863356
  writeRegister(0x40, 0x05); // TX Buffer - 13863367 to 13863500
  writeRegister(0x41, 0x0E); // TX Buffer - 13863514 to 13863649
  writeRegister(0x44, 0x23); // TX Buffer - 13863663 to 13863797
  writeRegister(0x45, 0x11); // TX Buffer - 13863811 to 13863947
  writeRegister(0x46, 0x13); // TX Buffer - 13863959 to 13864096
  writeRegister(0x04, 0x07); // TX - 13864108 to 13864244
  writeRegister(0x00, 0xFF); // CS0 - 13870974 to 13871110
  writeRegister(0x01, 0xFF); // CS1 - 13871124 to 13871264
  writeRegister(0x16, 0xC0); // FIFO CTRL - 13871274 to 13871413
  writeRegister(0x40, 0x05); // TX Buffer - 13871423 to 13871564
  writeRegister(0x41, 0x0E); // TX Buffer - 13871570 to 13871710
  writeRegister(0x44, 0x23); // TX Buffer - 13871719 to 13871861
  writeRegister(0x45, 0x11); // TX Buffer - 13871867 to 13872009
  writeRegister(0x46, 0x13); // TX Buffer - 13872016 to 13872154
  writeRegister(0x04, 0x07); // TX - 13872165 to 13872306
  writeRegister(0x00, 0xFF); // CS0 - 13878946 to 13879085
  writeRegister(0x01, 0xFF); // CS1 - 13879096 to 13879237
  writeRegister(0x16, 0xC0); // FIFO CTRL - 13879249 to 13879384
  writeRegister(0x40, 0x05); // TX Buffer - 13879398 to 13879533
  writeRegister(0x41, 0x0E); // TX Buffer - 13879545 to 13879680
  writeRegister(0x44, 0x23); // TX Buffer - 13879694 to 13879830
  writeRegister(0x45, 0x11); // TX Buffer - 13879842 to 13879978
  writeRegister(0x46, 0x13); // TX Buffer - 13879991 to 13880127
  writeRegister(0x04, 0x07); // TX - 13880140 to 13880275
  writeRegister(0x00, 0xFF); // CS0 - 13886921 to 13887058
  writeRegister(0x01, 0xFF); // CS1 - 13887071 to 13887212
  writeRegister(0x16, 0xC0); // FIFO CTRL - 13887221 to 13887359
  writeRegister(0x40, 0x05); // TX Buffer - 13887369 to 13887511
  writeRegister(0x41, 0x0E); // TX Buffer - 13887517 to 13887655
  writeRegister(0x44, 0x23); // TX Buffer - 13887665 to 13887808
  writeRegister(0x45, 0x11); // TX Buffer - 13887814 to 13887956
  writeRegister(0x46, 0x13); // TX Buffer - 13887962 to 13888102
  writeRegister(0x04, 0x07); // TX - 13888111 to 13888253
  writeRegister(0x00, 0xFF); // CS0 - 13894977 to 13895121
  writeRegister(0x01, 0xFF); // CS1 - 13895127 to 13895268
  writeRegister(0x16, 0xC0); // FIFO CTRL - 13895281 to 13895415
  writeRegister(0x40, 0x05); // TX Buffer - 13895429 to 13895564
  writeRegister(0x41, 0x0E); // TX Buffer - 13895573 to 13895711
  writeRegister(0x44, 0x23); // TX Buffer - 13895722 to 13895861
  writeRegister(0x45, 0x11); // TX Buffer - 13895870 to 13896008
  writeRegister(0x46, 0x13); // TX Buffer - 13896019 to 13896157
  writeRegister(0x04, 0x07); // TX - 13896171 to 13896305
  writeRegister(0x00, 0xFF); // CS0 - 13902949 to 13903088
  writeRegister(0x01, 0xFF); // CS1 - 13903102 to 13903246
  writeRegister(0x16, 0xC0); // FIFO CTRL - 13903252 to 13903393
  writeRegister(0x40, 0x05); // TX Buffer - 13903401 to 13903534
  writeRegister(0x41, 0x0E); // TX Buffer - 13903548 to 13903683
  writeRegister(0x44, 0x23); // TX Buffer - 13903697 to 13903831
  writeRegister(0x45, 0x11); // TX Buffer - 13903845 to 13903981
  writeRegister(0x46, 0x13); // TX Buffer - 13903994 to 13904130
  writeRegister(0x04, 0x07); // TX - 13904142 to 13904278
  writeRegister(0x00, 0xFF); // CS0 - 13910923 to 13911067
  writeRegister(0x01, 0xFF); // CS1 - 13911073 to 13911213
  writeRegister(0x16, 0xC0); // FIFO CTRL - 13911227 to 13911362
  writeRegister(0x40, 0x05); // TX Buffer - 13911376 to 13911509
  writeRegister(0x41, 0x0E); // TX Buffer - 13911520 to 13911658
  writeRegister(0x44, 0x23); // TX Buffer - 13911668 to 13911806
  writeRegister(0x45, 0x11); // TX Buffer - 13911817 to 13911956
  writeRegister(0x46, 0x13); // TX Buffer - 13911965 to 13912105
  writeRegister(0x04, 0x07); // TX - 13912117 to 13912253
  writeRegister(0x00, 0xFF); // CS0 - 13918895 to 13919036
  writeRegister(0x01, 0xFF); // CS1 - 13919048 to 13919192
  writeRegister(0x16, 0xC0); // FIFO CTRL - 13919199 to 13919341
  writeRegister(0x40, 0x05); // TX Buffer - 13919347 to 13919482
  writeRegister(0x41, 0x0E); // TX Buffer - 13919495 to 13919629
  writeRegister(0x44, 0x23); // TX Buffer - 13919643 to 13919779
  writeRegister(0x45, 0x11); // TX Buffer - 13919792 to 13919926
  writeRegister(0x46, 0x13); // TX Buffer - 13919940 to 13920075
  writeRegister(0x04, 0x07); // TX - 13920089 to 13920223
  writeRegister(0x00, 0xFF); // CS0 - 13926955 to 13927092
  writeRegister(0x01, 0xFF); // CS1 - 13927105 to 13927246
  writeRegister(0x16, 0xC0); // FIFO CTRL - 13927255 to 13927393
  writeRegister(0x40, 0x05); // TX Buffer - 13927403 to 13927545
  writeRegister(0x41, 0x0E); // TX Buffer - 13927551 to 13927692
  writeRegister(0x44, 0x23); // TX Buffer - 13927699 to 13927842
  writeRegister(0x45, 0x11); // TX Buffer - 13927848 to 13927990
  writeRegister(0x46, 0x13); // TX Buffer - 13927996 to 13928139
  writeRegister(0x04, 0x07); // TX - 13928145 to 13928287
  writeRegister(0x00, 0xFF); // CS0 - 13934926 to 13935067
  writeRegister(0x01, 0xFF); // CS1 - 13935076 to 13935216
  writeRegister(0x16, 0xC0); // FIFO CTRL - 13935230 to 13935365
  writeRegister(0x40, 0x05); // TX Buffer - 13935378 to 13935512
  writeRegister(0x41, 0x0E); // TX Buffer - 13935526 to 13935661
  writeRegister(0x44, 0x23); // TX Buffer - 13935674 to 13935809
  writeRegister(0x45, 0x11); // TX Buffer - 13935823 to 13935959
  writeRegister(0x46, 0x13); // TX Buffer - 13935971 to 13936106
  writeRegister(0x04, 0x07); // TX - 13936120 to 13936254
  writeRegister(0x00, 0xFF); // CS0 - 13942901 to 13943037
  writeRegister(0x01, 0xFF); // CS1 - 13943051 to 13943191
  writeRegister(0x16, 0xC0); // FIFO CTRL - 13943202 to 13943340
  writeRegister(0x40, 0x05); // TX Buffer - 13943350 to 13943491
  writeRegister(0x41, 0x0E); // TX Buffer - 13943497 to 13943640
  writeRegister(0x44, 0x23); // TX Buffer - 13943646 to 13943788
  writeRegister(0x45, 0x11); // TX Buffer - 13943794 to 13943937
  writeRegister(0x46, 0x13); // TX Buffer - 13943943 to 13944085
  writeRegister(0x04, 0x07); // TX - 13944092 to 13944233
  writeRegister(0x00, 0xFF); // CS0 - 13950958 to 13951101
  writeRegister(0x01, 0xFF); // CS1 - 13951108 to 13951249
  writeRegister(0x16, 0xC0); // FIFO CTRL - 13951261 to 13951396
  writeRegister(0x40, 0x05); // TX Buffer - 13951410 to 13951545
  writeRegister(0x41, 0x0E); // TX Buffer - 13951554 to 13951692
  writeRegister(0x44, 0x23); // TX Buffer - 13951702 to 13951842
  writeRegister(0x45, 0x11); // TX Buffer - 13951851 to 13951990
  writeRegister(0x46, 0x13); // TX Buffer - 13951999 to 13952139
  writeRegister(0x04, 0x07); // TX - 13952152 to 13952287



  writeRegister(0x04, 0x00); // RDO-OFF - 13952538 to 13952671
  writeRegister(0x00, 0xFF); // CS0 - 13952685 to 13952826
  writeRegister(0x0B, 0x1D); // RC Ack Config - 13952835 to 13952975
  writeRegister(0x07, 0x1A); // Channel Selection - 13952990 to 13953125
  writeRegister(0x16, 0x10); // FIFO CTRL - 13953147 to 13953281
  writeRegister(0x00, 0xFF); // CS0 - 13953295 to 13953434
  writeRegister(0x01, 0xFF); // CS1 - 13953445 to 13953586
  
  
  writeRegister(0x04, 0x02); // RX Enable - 13954490 to 13954623
  writeRegister(0x02, 0x80); // Int1Msk - 13954637 to 13954770
  writeRegister(0x03, 0x00); // Int2Msk - 13954780 to 13954913
  writeRegister(0x00, 0xFF); // CS0 - 13954927 to 13955071
  writeRegister(0x01, 0xFF); // CS1 - 13955077 to 13955217
  delay(1000); // Delay 4692364 cycles
  writeRegister(0x04, 0x00); // RDO-OFF - 18647444 to 18647581
  writeRegister(0x00, 0xFF); // CS0 - 18647587 to 18647728
  writeRegister(0x06, 0x17); // PWR-CFG - 18655190 to 18655330
  delay(1907); // Delay 1907522 cycles
  writeRegister(0x1A, 0xB3); // RST Phase 1 - 20562773 to 20562852
  writeRegister(0x1A, 0x5E); // RST Phase 2 - 20562858 to 20562937
  writeRegister(0x06, 0x37); // PWR-CFG - 20562952 to 20563030
  result = readRegister(0x01); // CS1 - Expect 0x02 - 20563040 to 20563188
  result = readRegister(0x01); // CS1 - Expect 0x02 - 20563203 to 20563352
  result = readRegister(0x01); // CS1 - Expect 0x02 - 20563367 to 20563514
  result = readRegister(0x01); // CS1 - Expect 0x03 - 20563531 to 20563679
  writeRegister(0x0B, 0x1D); // RC Ack Config - 20563693 to 20563771
  writeRegister(0x16, 0x10); // FIFO CTRL - 20563777 to 20563854
  writeRegister(0x00, 0xFF); // CS0 - 20563860 to 20563939
  writeRegister(0x01, 0xFF); // CS1 - 20563945 to 20564024
  writeRegister(0x07, 0x1A); // Channel Selection - 20564033 to 20564109

  writeRegister(0x0E, 0x5A); // ADDR - 513491 to 513569
  writeRegister(0x0F, 0x00); // ADDR - 513575 to 513652
  writeRegister(0x10, 0x5A); // ADDR - 513658 to 513734
  writeRegister(0x11, 0x5A); // PEER - 513742 to 513818
  writeRegister(0x12, 0x00); // PEER - 513826 to 513900
  writeRegister(0x13, 0x5A); // PEER - 513908 to 513986
  
  writeRegister(0x04, 0x02); // RX Enable - 20564619 to 20564695
  writeRegister(0x02, 0x80); // Int1Msk - 20564701 to 20564777
  writeRegister(0x03, 0x00); // Int2Msk - 20564783 to 20564859
  writeRegister(0x00, 0xFF); // CS0 - 20564865 to 20564945
  writeRegister(0x01, 0xFF); // CS1 - 20564950 to 20565029
  delay(10); // Delay 10254 cycles
  writeRegister(0x04, 0x00); // RDO-OFF - 20575208 to 20575283
  writeRegister(0x00, 0xFF); // CS0 - 20575289 to 20575368
  writeRegister(0x05, 0x02); // Unknown - 20575374 to 20575449
  delay(839); // Delay 839244 cycles
  
  writeRegister(0x1A, 0xB3); // RST Phase 1 - 21414552 to 21414693
  writeRegister(0x1A, 0x5E); // RST Phase 2 - 21414702 to 21414842
  writeRegister(0x06, 0x37); // PWR-CFG - 21415592 to 21415732
  result = readRegister(0x01); // CS1 - Expect 0x02 - 21415748 to 21416013
  result = readRegister(0x01); // CS1 - Expect 0x02 - 21416038 to 21416302
  result = readRegister(0x01); // CS1 - Expect 0x03 - 21416332 to 21416592
  writeRegister(0x08, 0x31); // Unknown - 21416616 to 21416755
  writeRegister(0x0C, 0x02); // Unknown - 21416764 to 21416898
  writeRegister(0x00, 0xFF); // CS0 - 21416952 to 21417091
  writeRegister(0x01, 0xFF); // CS1 - 21417105 to 21417243
  writeRegister(0x07, 0x1A); // Channel Selection - 21417257 to 21417396
  
  writeRegister(0x0E, 0x5A); // ADDR - 513491 to 513569
  writeRegister(0x0F, 0x00); // ADDR - 513575 to 513652
  writeRegister(0x10, 0x5A); // ADDR - 513658 to 513734
  writeRegister(0x11, 0x5A); // PEER - 513742 to 513818
  writeRegister(0x12, 0x00); // PEER - 513826 to 513900
  writeRegister(0x13, 0x5A); // PEER - 513908 to 513986
  
  writeRegister(0x14, 0x1F); // TX Length - 21418301 to 21418437
  writeRegister(0x02, 0x40); // Int1Msk - 21418451 to 21418584
  writeRegister(0x03, 0x00); // Int2Msk - 21418598 to 21418731
  writeRegister(0x00, 0xFF); // CS0 - 21418741 to 21418882
  writeRegister(0x01, 0xFF); // CS1 - 21418895 to 21419039
  writeRegister(0x16, 0xC0); // FIFO CTRL - 21419046 to 21419184
  writeRegister(0x40, 0x02); // TX Buffer - 21419195 to 21419328
  writeRegister(0x41, 0x09); // TX Buffer - 21419342 to 21419477
  writeRegister(0x42, 0x76); // TX Buffer - 21419490 to 21419629
  writeRegister(0x43, 0x01); // TX Buffer - 21419639 to 21419773
  writeRegister(0x44, 0x23); // TX Buffer - 21419787 to 21419923
  writeRegister(0x45, 0x01); // TX Buffer - 21419935 to 21420071
  writeRegister(0x46, 0x13); // TX Buffer - 21420083 to 21420220
  writeRegister(0x04, 0x07); // TX - 21420232 to 21420368
  writeRegister(0x00, 0xFF); // CS0 - 21421394 to 21421530
  writeRegister(0x01, 0xFF); // CS1 - 21421544 to 21421685
  writeRegister(0x07, 0x1A); // Channel Selection - 21421700 to 21421835
  

}

void loop() {
}

byte readRegister(byte thisRegister ) {
  byte inByte = 0;           // incoming byte from the SPI
  unsigned int result = 0;   // result to return
  Serial.print(thisRegister, HEX);
  Serial.print("\t");

  //High bit being set indicates a read
  //thisRegister = 0x80 | thisRegister;
  // now combine the address and the command into one byte

  digitalWrite(chipSelectPin, LOW);

  // gain control of the SPI port
  // and configure settings
  SPI.beginTransaction(SPISettings(100000, MSBFIRST, SPI_MODE0));
  // send the device the register you want to read:
  SPI.transfer(thisRegister);
  // send a value of 0 to read the first byte returned:
  result = SPI.transfer(0x00);

  // release control of the SPI port
  SPI.endTransaction();
  // return the result:

  digitalWrite(chipSelectPin, HIGH);

  Serial.println(result, HEX);

  return (result);
}

void writeRegister(byte thisRegister, byte thisValue) {

  // gain control of the SPI port
  // and configure settings
  SPI.beginTransaction(SPISettings(100000, MSBFIRST, SPI_MODE0));

  digitalWrite(chipSelectPin, LOW);

  SPI.transfer(thisRegister); //Send register location
  SPI.transfer(thisValue);  //Send value to record into register

  // release control of the SPI port
  SPI.endTransaction();

  digitalWrite(chipSelectPin, HIGH);
}



