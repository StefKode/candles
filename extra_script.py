Import("env")

# Get the platform path for proper Arduino framework includes
platform = env.PioPlatform()
framework_path = platform.get_package_dir("framework-arduino-avr")

# Add build flags for proper include paths
env.Append(
    CPPPATH=[
        framework_path,
        framework_path + "/cores/arduino",
        framework_path + "/variants/standard"
    ]
)