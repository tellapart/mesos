// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//  http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef __STOUT_OS_REALPATH_HPP__
#define __STOUT_OS_REALPATH_HPP__


#include <stout/result.hpp>

#ifdef __WINDOWS__
#include <stout/windows.hpp>
#endif


namespace os {

inline Result<std::string> realpath(const std::string& path)
{
  char temp[PATH_MAX];
  if (::realpath(path.c_str(), temp) == NULL) {
    if (errno == ENOENT || errno == ENOTDIR) {
      return None();
    }
    return ErrnoError();
  }
  return std::string(temp);
}

} // namespace os {

#endif // __STOUT_OS_REALPATH_HPP__
