//
// Copyright (C) 2023 Intel Corporation
// SPDX-License-Identifier: Apache 2.0
//

//

#pragma once

#include <vpux_elf/types/data_types.hpp>

namespace elf {

///
/// Refer to https://docs.oracle.com/cd/E23824_01/html/819-0690/chapter6-79797.html
/// for the detailed description of the values and structures below
///

//! Symbol binding
constexpr uint8_t STB_LOCAL  = 0;
constexpr uint8_t STB_GLOBAL = 1;
constexpr uint8_t STB_WEAK   = 2;
constexpr uint8_t STB_LOOS   = 10;
constexpr uint8_t STB_HIOS   = 12;
constexpr uint8_t STB_LOPROC = 13;
constexpr uint8_t STB_HIPROC = 15;

//! Symbol types
constexpr uint8_t STT_NOTYPE         = 0;
constexpr uint8_t STT_OBJECT         = 1;
constexpr uint8_t STT_FUNC           = 2;
constexpr uint8_t STT_SECTION        = 3;
constexpr uint8_t STT_FILE           = 4;
constexpr uint8_t STT_COMMON         = 5;
constexpr uint8_t STT_TLS            = 6;
constexpr uint8_t STT_LOOS           = 10;
constexpr uint8_t STT_HIOS           = 12;
constexpr uint8_t STT_LOPROC         = 13;
constexpr uint8_t STT_SPARC_REGISTER = 13;
constexpr uint8_t STT_HIPROC         = 15;

//! Symbol visibility
constexpr uint8_t STV_DEFAULT   = 0;
constexpr uint8_t STV_INTERNAL  = 1;
constexpr uint8_t STV_HIDDEN    = 2;
constexpr uint8_t STV_PROTECTED = 3;
constexpr uint8_t STV_EXPORTED  = 4;
constexpr uint8_t STV_SINGLETON = 5;
constexpr uint8_t STV_ELIMINATE = 6;

struct Elf64_Sym {
    Elf_Word   st_name;
    uint8_t    st_info;
    uint8_t    st_other;
    Elf_Half   st_shndx;
    Elf64_Addr st_value;
    Elf_Xword  st_size;
};

struct Elf32_Sym {
    Elf_Word   st_name;
    Elf32_Addr st_value;
    Elf_Word   st_size;
    uint8_t    st_info;
    uint8_t    st_other;
    Elf_Half   st_shndx;
};

//! Extract symbol binding attributes from info
Elf_Xword elf64STBind(Elf_Xword info);

//! Extract symbol type from info
Elf_Xword elf64STType(Elf_Xword info);

//! Pack symbol binding attributes and symbol type into info
Elf_Xword elf64STInfo(Elf_Xword bind, Elf_Xword type);

//! Performs a transformation over visibility to zero out all bits that have no defined meaning
uint8_t elf64STVisibility(uint8_t visibility);

using SymbolEntry = Elf64_Sym;

} // namespace elf
