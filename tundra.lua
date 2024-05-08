Build {
   Units = function()
      local test = Program {
         Name = "rmathtest",
         Sources = { "test.cpp", "src/vectormath.cpp" },
         Libs = { },
         Includes = {"include"},
      }
      Default(test)
   end,

   Env = {
      CCOPTS = "/0d",
      PROGOPTS = "/SUBSYSTEM:CONSOLE /DEBUG",
      GENERATE_PDB = "1",
   },

   Configs = {
      Config {
         Name = "win64-msvc",
         DefaultOnHost = "windows",
         Tools = { {"msvc"; TargetArch = "x64"} },
      },
   },
}