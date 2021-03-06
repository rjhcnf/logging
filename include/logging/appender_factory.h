// MIT License

// Copyright (c) 2018 Kohei Otsuka

// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:

// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#ifndef INCLUDE_LOGGING_APPENDER_FACTORY_H_
#define INCLUDE_LOGGING_APPENDER_FACTORY_H_

#include <memory>
#include <utility>
#include "appender_interface.h"
#include "console_appender.h"
#include "logging/file_appender.h"
#ifdef ARALOG
#include "logging/aralog_appender.h"
#endif

namespace logging {

class AppenderFactory {
 public:
  template <class T>
  static std::unique_ptr<IAppender> CreateAppender(std::unique_ptr<AppenderConfig> appender_config) {
          return std::unique_ptr<IAppender>(new T(std::move(appender_config)));
  }
};

}  // namespace logging

#endif  // INCLUDE_LOGGING_APPENDER_FACTORY_H_
