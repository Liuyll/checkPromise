{   
    "include_dirs": ["<!(node -p \"require('node-addon-api').include_dir\")"],
    "targets": [
        {
            "target_name": "checkPromise",
            "sources": ["src/checkPromise.cc"]
        }
    ]
}