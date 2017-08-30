env = Environment()
env.Append(CXXFLAGS = '-std=c++1z')

env.SConscript('src/SConscript', { 'env': env }, variant_dir = 'obj', duplicate = 0)

