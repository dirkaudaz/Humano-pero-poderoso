#include <initializer_list>

namespace Shell
{
  class CommandLineOptions
  {
  public:
    CommandLineOptions(std::initializer_list<CommandLineOptions> options);
  private:
    std::map<int, size_t> short_index;
    std::map<int, size_t> long_index;

    std::vector<CommandLineOptions> all_options;
    std::vector<CommandLineOptions> required_options;

  }
}
