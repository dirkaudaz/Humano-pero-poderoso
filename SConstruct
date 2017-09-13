import re

env = Environment()
env.Append(CXXFLAGS = '-std=c++1z')

retVal = env.SConscript('src/SConscript', { 'env': env }, variant_dir = 'obj', duplicate = 0)

executables = retVal['executables']
objects = retVal['objects']

for executable in executables:
  s = re.search('.*obj/(.*)\.o', executable[0].str_for_display())
  if s:
    executable_name = s.group(1)
    env.Program('bin/%s' % executable_name, executable + objects)
