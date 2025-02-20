/* These are sample test vectors which are shared across multiple test tools */

#include <stdint.h>
#include <stdlib.h>

/* Mouse:
   Out of network:
   <SCTE35 command="5" command_str="insert" pts_adjustment="67521" event_id="692" cancel="0"
      out_of_network="1" program_splice="1" splice_time="immediate" unique_program_id="1">
*/
static const uint8_t mouse_oon[] = {
	0xfc, 0x30, 0x1b, 0x00, 0x00, 0x00, 0x01, 0x07,
	0xc1, 0x00, 0xff, 0xf0, 0x0a, 0x05, 0x00, 0x00,
	0x02, 0xb4, 0x7f, 0xdf, 0x00, 0x01, 0x01, 0x01,
	0x00, 0x00, 0x7c, 0x18, 0x5d, 0x61
};

/*
   Mouse:
   Back to network:
   <SCTE35 command="5" command_str="insert" pts_adjustment="67521" event_id="693" cancel="0"
      out_of_network="0" program_splice="1" splice_time="2241430756" unique_program_id="1">
*/
static const uint8_t mouse_btn[] = {
	0xfc, 0x30, 0x20, 0x00, 0x00, 0x00, 0x01, 0x07,
	0xc1, 0x00, 0xff, 0xf0, 0x0f, 0x05, 0x00, 0x00,
	0x02, 0xb5, 0x7f, 0x4f, 0xfe, 0x85, 0x99, 0x84,
	0xe4, 0x00, 0x01, 0x01, 0x01, 0x00, 0x00, 0x3e,
	0x17, 0xd8, 0x2e
};

static const uint8_t multi_descriptor_test1[] = {
	0xfc, 0x30, 0x3a, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0xff, 0xf0, 0x0f, 0x05, 0x40, 0x00,
	0x00, 0x52, 0x7f, 0xff, 0x7e, 0x00, 0x36, 0xee,
	0x80, 0x00, 0x64, 0x03, 0x01, 0x00, 0x1a, 0x01,
	0x07, 0x43, 0x55, 0x45, 0x49, 0x00, 0x3f, 0x30,
	0x02, 0x0f, 0x43, 0x55, 0x45, 0x49, 0x00, 0x00,
	0x00, 0x00, 0x7f, 0xbf, 0x00, 0x00, 0x40, 0x00,
	0x00, 0x5f, 0x33, 0xe8, 0xf6,
};

/* These were copied from the test cases for the Comcast GOTS project (BSD licensed).  The
   original
   sources can be found here:
   https://github.com/Comcast/gots/blob/master/scte35/scte35_test.go

   Note:  I changed the arrays to strip off the leading byte, and apparently the
   test vectors had incorrect checksums (the GoTS library itself doesn't ever attempt
   to validate the checksums).  Hence I've modified the sections to have valid checksums
*/
static const uint8_t comcast_gots_test1 [] = {
	0xfc, 0x00, 0x2c, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0xff, 0xff, 0xf0, 0x05, 0x06, 0xfe, 0x86,
	0xdf, 0x75, 0x50, 0x00, 0x11, 0x02, 0x0f, 0x43,
	0x55, 0x45, 0x49, 0x41, 0x42, 0x43, 0x44, 0x7f,
	0x8f, 0x00, 0x00, 0x10, 0x01, 0x01, 0xce, 0x6d,
	0x6a, 0x49,
};

static const uint8_t comcast_gots_test2 [] = {
	0xfc, 0x00, 0x53, 0x00, 0x00, 0x00, 0x02, 0xdd,
	0x20, 0x00, 0xff, 0xf0, 0x05, 0x06, 0xfe, 0x00,
	0x08, 0x95, 0x44, 0x00, 0x3d, 0x02, 0x3b, 0x43,
	0x55, 0x45, 0x49, 0x00, 0x00, 0x00, 0x02, 0x7f,
	0x1f, 0x02, 0x01, 0xfe, 0x00, 0x2d, 0xd2, 0x00,
	0x02, 0xfe, 0x00, 0x00, 0x01, 0xe8, 0x09, 0x1f,
	0x53, 0x49, 0x47, 0x4e, 0x41, 0x4c, 0x3a, 0x59,
	0x38, 0x6f, 0x30, 0x44, 0x33, 0x7a, 0x70, 0x54,
	0x78, 0x53, 0x30, 0x4c, 0x54, 0x31, 0x65, 0x77,
	0x2b, 0x77, 0x75, 0x69, 0x77, 0x3d, 0x3d, 0x36,
	0x00, 0x00, 0xbf, 0x68, 0xb8, 0xc0,
};

static const uint8_t comcast_gots_test3 [] = {
	0xfc, 0x30, 0x55, 0x00, 0x00, 0x00, 0x02, 0xd5,
	0xa0, 0x00, 0xff, 0xf0, 0x05, 0x06, 0xfe, 0x00,
	0x04, 0x2b, 0x79, 0x00, 0x3f, 0x02, 0x1b, 0x43,
	0x55, 0x45, 0x49, 0x00, 0x00, 0x00, 0x01, 0x7f,
	0x87, 0x09, 0x0c, 0x53, 0x49, 0x47, 0x4e, 0x41,
	0x4c, 0x3a, 0x33, 0x2e, 0x30, 0x35, 0x30, 0x35,
	0x01, 0x01, 0x02, 0x20, 0x43, 0x55, 0x45, 0x49,
	0x00, 0x00, 0x00, 0x01, 0x7f, 0xff, 0x00, 0x00,
	0x23, 0x13, 0xac, 0x09, 0x0c, 0x53, 0x49, 0x47,
	0x4e, 0x41, 0x4c, 0x3a, 0x33, 0x2e, 0x30, 0x35,
	0x30, 0x34, 0x01, 0x01, 0x70, 0x51, 0x15, 0x6c,
};

static const uint8_t bw_reservation [] = {
	0xfc, 0x30, 0x63, /* GC....0c */
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe3, 0xff, /* ........ */
	0xff, 0xff, 0x07, 0x00, 0x52, 0xba, 0x50, 0xba, /* ....R.P. */
	0x71, 0xe3, 0x2a, 0xdd, 0x38, 0xf1, 0x95, 0xee, /* q.*.8... */
	0x9c, 0x78, 0xca, 0x77, 0x4e, 0x3c, 0x65, 0xbb, /* .x.wN<e. */
	0xa7, 0x1e, 0x32, 0xdd, 0xd3, 0x8f, 0x19, 0x6e, /* ..2....n */
	0xe9, 0xc7, 0x8c, 0xb7, 0x74, 0xe3, 0xc6, 0xdb, /* ....t... */
	0xba, 0x71, 0xe3, 0x6d, 0xdd, 0x38, 0xf1, 0xb6, /* .q.m.8.. */
	0xee, 0x9c, 0x78, 0x5b, 0x77, 0x4e, 0x3c, 0xad, /* ..x[wN<. */
	0xbb, 0xa7, 0x1e, 0xd6, 0xdd, 0xd3, 0x8f, 0xeb, /* ........ */
	0x6e, 0xe9, 0xc7, 0x75, 0xb7, 0x74, 0xe3, 0xba, /* n..u.t.. */
	0xdb, 0xba, 0x71, 0x5d, 0x6d, 0xdd, 0x38, 0xae, /* ..q]m.8. */
	0xb6, 0xee, 0x9c, 0x57, 0x5b, 0x77, 0x4e, 0xe8, /* ...W[wN. */
	0x68, 0x26, 0x68
};

/* Segmentation descriptor with identifier other than CUEI */
static const uint8_t seg_invalid_id [] = {
	0xfc, 0x30, 0x27, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x85, 0xff, 0xff, 0xff, 0x07, 0x00, 0x16,
	0x02, 0x14, 0x02, 0x7e, 0x85, 0xd2, 0x01, 0x3f,
	0x42, 0xe9, 0x00, 0x9f, 0xa1, 0x74, 0x00, 0x4f,
	0xd0, 0xba, 0x80, 0x27, 0xe8, 0x5d, 0xef, 0xdc,
	0xaf, 0x51
};

/* These are all test vectors from Section 14 of
   SCTE-35 2019.  "Sample SCTE 35 Messages (Informative)" */
static const uint8_t scte35_2019_14_1 [] = {
	0xFC, 0x30, 0x34, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0xFF, 0xFF, 0xF0, 0x05, 0x06, 0xFE, 0x72,
	0xBD, 0x00, 0x50, 0x00, 0x1E, 0x02, 0x1C, 0x43,
	0x55, 0x45, 0x49, 0x48, 0x00, 0x00, 0x8E, 0x7F,
	0xCF, 0x00, 0x01, 0xA5, 0x99, 0xB0, 0x08, 0x08,
	0x00, 0x00, 0x00, 0x00, 0x2C, 0xA0, 0xA1, 0x8A,
	0x34, 0x02, 0x00, 0x9A, 0xC9, 0xD1, 0x7E
};

static const uint8_t scte35_2019_14_2 [] = {
	0xFC, 0x30, 0x2F, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0xFF, 0xFF, 0xF0, 0x14, 0x05, 0x48, 0x00,
	0x00, 0x8F, 0x7F, 0xEF, 0xFE, 0x73, 0x69, 0xC0,
	0x2E, 0xFE, 0x00, 0x52, 0xCC, 0xF5, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x0A, 0x00, 0x08, 0x43, 0x55,
	0x45, 0x49, 0x00, 0x00, 0x01, 0x35, 0x62, 0xDB,
	0xA3, 0x0A
};

static const uint8_t scte35_2019_14_3 [] = {
	0xFC, 0x30, 0x2F, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0xFF, 0xFF, 0xF0, 0x05, 0x06, 0xFE, 0x74,
	0x62, 0x90, 0xA0, 0x00, 0x19, 0x02, 0x17, 0x43,
	0x55, 0x45, 0x49, 0x48, 0x00, 0x00, 0x8E, 0x7F,
	0x9F, 0x08, 0x08, 0x00, 0x00, 0x00, 0x00, 0x2C,
	0xA0, 0xA1, 0x8A, 0x35, 0x02, 0x00, 0xA9, 0xCC,
	0x67, 0x58
};

static const uint8_t scte35_2019_14_4 [] = {
	0xFC, 0x30, 0x48, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0xFF, 0xFF, 0xF0, 0x05, 0x06, 0xFE, 0x7A,
	0x4D, 0x88, 0xB6, 0x00, 0x32, 0x02, 0x17, 0x43,
	0x55, 0x45, 0x49, 0x48, 0x00, 0x00, 0x18, 0x7F,
	0x9F, 0x08, 0x08, 0x00, 0x00, 0x00, 0x00, 0x2C,
	0xCB, 0xC3, 0x44, 0x11, 0x00, 0x00, 0x02, 0x17,
	0x43, 0x55, 0x45, 0x49, 0x48, 0x00, 0x00, 0x19,
	0x7F, 0x9F, 0x08, 0x08, 0x00, 0x00, 0x00, 0x00,
	0x2C, 0xA4, 0xDB, 0xA0, 0x10, 0x00, 0x00, 0x99,
	0x72, 0xE3, 0x43
};

static const uint8_t scte35_2019_14_5 [] = {
	0xFC, 0x30, 0x2F, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0xFF, 0xFF, 0xF0, 0x05, 0x06, 0xFE, 0xAE,
	0xBF, 0xFF, 0x64, 0x00, 0x19, 0x02, 0x17, 0x43,
	0x55, 0x45, 0x49, 0x48, 0x00, 0x00, 0x08, 0x7F,
	0x9F, 0x08, 0x08, 0x00, 0x00, 0x00, 0x00, 0x2C,
	0xA5, 0x6C, 0xF5, 0x17, 0x00, 0x00, 0x95, 0x1D,
	0xB0, 0xA8
};

static const uint8_t scte35_2019_14_6 [] = {
	0xFC, 0x30, 0x48, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0xFF, 0xFF, 0xF0, 0x05, 0x06, 0xFE, 0x93,
	0x2E, 0x38, 0x0B, 0x00, 0x32, 0x02, 0x17, 0x43,
	0x55, 0x45, 0x49, 0x48, 0x00, 0x00, 0x0A, 0x7F,
	0x9F, 0x08, 0x08, 0x00, 0x00, 0x00, 0x00, 0x2C,
	0xA0, 0xA1, 0xE3, 0x18, 0x00, 0x00, 0x02, 0x17,
	0x43, 0x55, 0x45, 0x49, 0x48, 0x00, 0x00, 0x09,
	0x7F, 0x9F, 0x08, 0x08, 0x00, 0x00, 0x00, 0x00,
	0x2C, 0xA0, 0xA1, 0x8A, 0x11, 0x00, 0x00, 0xB4,
	0x21, 0x7E, 0xB0
};

static const uint8_t scte35_2019_14_7 [] = {
	0xFC, 0x30, 0x2F, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0xFF, 0xFF, 0xF0, 0x05, 0x06, 0xFE, 0xAE,
	0xF1, 0x7C, 0x4C, 0x00, 0x19, 0x02, 0x17, 0x43,
	0x55, 0x45, 0x49, 0x48, 0x00, 0x00, 0x07, 0x7F,
	0x9F, 0x08, 0x08, 0x00, 0x00, 0x00, 0x00, 0x2C,
	0xA5, 0x6C, 0x97, 0x11, 0x00, 0x00, 0xC4, 0x87,
	0x6A, 0x2E
};

static const uint8_t scte35_2019_14_8 [] = {
	0xFC, 0x30, 0x61, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0xFF, 0xFF, 0xF0, 0x05, 0x06, 0xFE, 0xA8,
	0xCD, 0x44, 0xED, 0x00, 0x4B, 0x02, 0x17, 0x43,
	0x55, 0x45, 0x49, 0x48, 0x00, 0x00, 0xAD, 0x7F,
	0x9F, 0x08, 0x08, 0x00, 0x00, 0x00, 0x00, 0x2C,
	0xB2, 0xD7, 0x9D, 0x35, 0x02, 0x00, 0x02, 0x17,
	0x43, 0x55, 0x45, 0x49, 0x48, 0x00, 0x00, 0x26,
	0x7F, 0x9F, 0x08, 0x08, 0x00, 0x00, 0x00, 0x00,
	0x2C, 0xB2, 0xD7, 0x9D, 0x11, 0x00, 0x00, 0x02,
	0x17, 0x43, 0x55, 0x45, 0x49, 0x48, 0x00, 0x00,
	0x27, 0x7F, 0x9F, 0x08, 0x08, 0x00, 0x00, 0x00,
	0x00, 0x2C, 0xB2, 0xD7, 0xB3, 0x10, 0x00, 0x00,
	0x8A, 0x18, 0x86, 0x9F
};

struct sample {
	const char *name;
	const uint8_t *buf;
	size_t buf_size;
};

const static struct sample samples[] = {
	{ "Mouse out-of-network sample", mouse_oon, sizeof(mouse_oon)},
	{ "Mouse btn sample", mouse_btn, sizeof(mouse_btn) },
	{ "Multi-descriptor test", multi_descriptor_test1, sizeof(multi_descriptor_test1) },
	{ "Comcast GOTS test1 sample", comcast_gots_test1, sizeof(comcast_gots_test1) },
	{ "Comcast GOTS test2 sample", comcast_gots_test2, sizeof(comcast_gots_test2) },
	{ "Comcast GOTS test3 sample", comcast_gots_test3, sizeof(comcast_gots_test3) },
	{ "bandwidth reservation sample", bw_reservation, sizeof(bw_reservation) },
	{ "invalid segmentation identifier sample", seg_invalid_id, sizeof(seg_invalid_id) },
	{ "SCTE-35:2019 Sec 14.1 Time_Signal – Placement Opportunity Start", scte35_2019_14_1, sizeof(scte35_2019_14_1) },
	{ "SCTE-35:2019 Sec 14.2 Splice_Insert", scte35_2019_14_2, sizeof(scte35_2019_14_2) },
	{ "Sec 14.3 Time_Signal – Placement Opportunity End", scte35_2019_14_3, sizeof(scte35_2019_14_3) },
	{ "Sec 14.4 Time_Signal – Program Start/End", scte35_2019_14_4, sizeof(scte35_2019_14_4) },
	{ "SCTE-35:2019 Sec 14.5 Time_Signal – Program Overlap Start", scte35_2019_14_5, sizeof(scte35_2019_14_5) },
	{ "SCTE-35:2019 Sec 14.6 Time_Signal – Program Blackout Override / Program End", scte35_2019_14_6, sizeof(scte35_2019_14_6) },
	{ "SCTE-35:2019 Sec 14.7 Time_Signal – Program End", scte35_2019_14_7, sizeof(scte35_2019_14_7) },
	{ "SCTE-35:2019 Sec 14.8 Time_Signal – Program Start/End - Placement Opportunity End", scte35_2019_14_8, sizeof(scte35_2019_14_8) },
};

int get_scte35sample(unsigned int sample_num, const char **name, const uint8_t **buf, size_t *size)
{
	if (sample_num >= sizeof(samples) / sizeof(struct sample))
		return -1;

	*name = samples[sample_num].name;
	*buf = samples[sample_num].buf;
	*size = samples[sample_num].buf_size;
	return 0;
}
