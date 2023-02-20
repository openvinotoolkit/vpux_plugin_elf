//
// Copyright (C) 2023 Intel Corporation
// SPDX-License-Identifier: Apache 2.0
//

//

#pragma once

#include <vpux_elf/writer/section.hpp>

namespace elf {

class Writer;

namespace writer {

template <typename T>
class BinaryDataSection final : public Section {
public:
    size_t appendData(const T& obj) {
        return appendData(&obj, 1);
    }

    size_t appendData(const T* obj, size_t sizeInElements) {
        const auto offset = m_data.size();
        m_data.insert(m_data.end(), reinterpret_cast<const uint8_t*>(obj),
                      reinterpret_cast<const uint8_t*>(obj) + sizeInElements * sizeof(T));
        return offset;
    }

    size_t getNumEntries() const {
        return static_cast<size_t>(m_data.size() / sizeof(T));
    }

private:
    explicit BinaryDataSection(const std::string& name, const Elf_Word section_type = SHT_PROGBITS) : Section(name) {
        static_assert(std::is_standard_layout<T>::value, "Only POD types are supported");
        m_header.sh_type = section_type;
        m_header.sh_entsize = sizeof(T);
    }

    friend Writer;
};

} // namespace writer
} // namespace elf
