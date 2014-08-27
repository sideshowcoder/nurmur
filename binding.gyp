{
  "targets": [
    {
      "target_name": "murmur3",
      "sources": [
        "src/binding.cc",
        "src/murmur3.c",
        "src/murmur3.h"
      ],
      "include_dirs": [
        "<!(node -e \"require('nan')\")",
        "./"
      ]
    }
  ]
}
