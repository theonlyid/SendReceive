/* SharedProtocol for AFE4490
 * Direct encoding for MSP430Eval
 *
 * Created: 18 Aug 2017
 * Author: Ali Zaidi
 */

#ifndef SHAREDPROTOCOL_H
#define SHAREDPROTOCOL_H

#define SYNCBYTE                                0x5A

#define PID_SPO2                                0x01
#define     CID_SPO2_CONFIGURE_ACQUISITION      0x01
#define     CID_SPO2_START_ACQUISITION          0x02
#define     CID_SPO2_STOP_ACQUISITION           0x03
#define         CID_ACK                         0x01
#define         CID_NACK                        0x02

#define     EVENT_SPO2_RAW_DATA                 0xFD

#define PID_ERROR                               0x00

#endif // SHAREDPROTOCOL_H
