/**
 * @file    flash_blob.c
 * @brief   Flash algorithm for the ke18f
 *
 * DAPLink Interface Firmware
 * Copyright (c) 2009-2016, ARM Limited, All Rights Reserved
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 (the "License"); you may
 * not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "flash_blob.h"

static const uint32_t mke18f16_flash_prog_blob[] = {
    0xE00ABE00, 0x062D780D, 0x24084068, 0xD3000040, 0x1E644058, 0x1C49D1FA, 0x2A001E52, 0x4770D1F2,
    0xb510483f, 0x6041493d, 0x71fff64f, 0x68016081, 0x0180f021, 0x0120f041, 0x483a6001, 0xf00168c1,
    0x29400160, 0x2101bf0c, 0x4a372100, 0x7011444a, 0x68c1b139, 0x0160f021, 0x68c160c1, 0x0f60f011,
    0x4832d1fb, 0xf0004448, 0x2800f865, 0x2001bf18, 0x482dbd10, 0x78004448, 0x482ab158, 0xf02168c1,
    0xf0410160, 0x60c10140, 0xf00168c1, 0x29400160, 0x2000d1fa, 0x48254770, 0x4925b510, 0xf0004448,
    0x2800f8a1, 0xbd10bf18, 0x48202100, 0x4010e8bd, 0xf0004448, 0xb570b966, 0x46054c1c, 0x4601444c,
    0x46204b1b, 0xf00068e2, 0x2800f8c6, 0xbd70bf18, 0x46292300, 0xe8bd68e2, 0x48144070, 0xf0004448,
    0xb570b95a, 0x460b460c, 0x46014606, 0xb084480f, 0x44484615, 0xf8f9f000, 0xbf1c2800, 0xbd70b004,
    0x21012000, 0x1000e9cd, 0x48089002, 0x4622462b, 0x44484631, 0xf98df000, 0xbd70b004, 0xd928c520,
    0x40052000, 0x4007e000, 0x00000004, 0x00000008, 0x6b65666b, 0xbf042800, 0x47702004, 0x6cc949f0,
    0x6103f3c1, 0xbf08290f, 0x2100f44f, 0x4aedbf1f, 0xf832447a, 0x02891011, 0x2200b410, 0x2100e9c0,
    0x60812101, 0x03094be8, 0xf89360c1, 0x110cc000, 0xfc0cfa04, 0xc014f8c0, 0x618378db, 0xf04f6102,
    0xe9c052a0, 0xbc102108, 0x47702000, 0xbf0e2800, 0x61012004, 0x47702000, 0x48dc4602, 0x49db6800,
    0x0020f040, 0x46086008, 0xf0406800, 0x60080010, 0x48d74770, 0x70012170, 0x70012180, 0xf0117801,
    0xd0fb0f80, 0xf0107800, 0xbf1c0f20, 0x47702067, 0x0f10f010, 0x2068bf1c, 0xf0104770, 0xbf180001,
    0x47702069, 0xbf042800, 0x47702004, 0x4604b510, 0xf06f4ac7, 0x6050403b, 0x428148c6, 0x206bbf14,
    0x28002000, 0xbd10bf18, 0xf7ff4620, 0x4603ffd2, 0xf7ff4620, 0x4618ffc1, 0x2800bd10, 0x2004bf04,
    0x23004770, 0x60936053, 0x611360d3, 0x61936153, 0x601161d3, 0x605168c1, 0x1001e9d0, 0xf0f0fbb1,
    0x20086090, 0xe9c22110, 0xe9c20103, 0x20041005, 0x200061d0, 0xe92d4770, 0xb0884df0, 0x46984615,
    0x4682460c, 0xf7ff466a, 0x462affd8, 0x46504621, 0xf0009b04, 0x0007f92f, 0xb008bf1c, 0x8df0e8bd,
    0x4600e9dd, 0x1e451960, 0xf0f6fbb5, 0x5110fb06, 0x1c40b111, 0x1e454370, 0xbf9842ac, 0xb270f8df,
    0xf024d81c, 0xf040407f, 0xf8cb6010, 0x48990004, 0xbf144580, 0x2000206b, 0xbf1c2800, 0xe8bdb008,
    0x46508df0, 0xff75f7ff, 0xf8da4607, 0x28000010, 0x4780bf18, 0x4434b917, 0xd9e242ac, 0xf7ff4650,
    0xb008ff5b, 0xe8bd4638, 0x2a008df0, 0x2004bf04, 0xe92d4770, 0xb08945f0, 0x461e4614, 0x4680460d,
    0xf7ff466a, 0x4632ff8a, 0x46404629, 0xf0009b03, 0x0007f8e1, 0xb009bf1c, 0x85f0e8bd, 0x2e009d00,
    0xf8dfbf18, 0xd025a1ec, 0x0b04f854, 0x0008f8ca, 0x28049803, 0xf025bf04, 0xf040407f, 0xd00960c0,
    0xd1092808, 0x0b04f854, 0x000cf8ca, 0x407ff025, 0x60e0f040, 0x0004f8ca, 0xf7ff4640, 0xf8d8ff2a,
    0x46071010, 0xbf182900, 0xb91f4788, 0x44059803, 0xd1d91a36, 0xf7ff4640, 0xb009ff0f, 0xe8bd4638,
    0x280085f0, 0x2004bf04, 0x4a634770, 0x4101ea42, 0x60514a5f, 0xe92de70d, 0xb0884dff, 0x469a4614,
    0x466a460d, 0xf7ff9808, 0x4622ff38, 0x9b054629, 0xf0009808, 0x2800f88f, 0xb00cbf1c, 0x8df0e8bd,
    0x4629466a, 0xf7ff9808, 0x9e00ff28, 0x8008f8dd, 0xf1c84270, 0x40080100, 0x42b74247, 0x4447bf08,
    0xbf182c00, 0xb128f8df, 0x1bbdd01f, 0xbf8842a5, 0x98054625, 0x417ff026, 0xf0f0fbb5, 0x7180f041,
    0x1004f8cb, 0xea400400, 0xf040200a, 0xf8cb00ff, 0x98080008, 0xfecdf7ff, 0xbf1c2800, 0xe8bdb00c,
    0x1b648df0, 0x4447442e, 0xb00cd1df, 0xe8bd2000, 0x2b008df0, 0x2004bf04, 0xe92d4770, 0xb0884dff,
    0xe9dd4616, 0x461d7a14, 0x466a460c, 0x8058f8dd, 0xf7ff9808, 0xe9ddfee2, 0x46323007, 0xf0004621,
    0x2800f839, 0xb00cbf1c, 0x8df0e8bd, 0x2e009c00, 0xb00cbf04, 0x8df0e8bd, 0xb094f8df, 0x407ff06f,
    0x6707ea40, 0x407ff024, 0x7000f040, 0x0004f8cb, 0x7008f8cb, 0xf8cb6828, 0x9808000c, 0xfe89f7ff,
    0xf1bab168, 0xbf180f00, 0x4000f8ca, 0x0f00f1b8, 0x2100bf1c, 0x1000f8c8, 0xe8bdb00c, 0x99078df0,
    0xf0211a76, 0x440d0103, 0x440c9907, 0xb00cd1da, 0x8df0e8bd, 0xbf042800, 0x47702004, 0x42191e5b,
    0x421abf0e, 0x47702065, 0x428b6803, 0x6840d806, 0x44184411, 0xbf244288, 0x47702000, 0x47702066,
    0x40048000, 0x000003d0, 0x40020028, 0x40001400, 0x40020000, 0x6b65666b, 0x4000ffff, 0x40020004,
    0x40020010, 0x00100008, 0x00200018, 0x00400030, 0x00800060, 0x010000c0, 0x02000180, 0x04000300,
    0x00000600, 0x00000000, 0x00000000,
};

static const program_target_t flash = {
    0x20000021, // Init
    0x20000073, // UnInit
    0x20000097, // EraseChip
    0x200000B7, // EraseSector
    0x200000E3, // ProgramPage
    0x0,        // Verify
    // BKPT : start of blob + 1
    // RSB  : blob start + header + rw data offset
    // RSP  : stack pointer
    {
        0x20000000 + 0x00000001,
        0x20000000 + 0x00000020 + 0x00000524,
        0x20000800
    },

    0x20000000 + 0x00000A00,   // mem buffer location
    0x20000000,                // location to write prog_blob in target RAM
    sizeof(mke18f16_flash_prog_blob), // prog_blob size
    mke18f16_flash_prog_blob,         // address of prog_blob
    0x00000200                 // ram_to_flash_bytes_to_be_written
};
