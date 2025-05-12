def sliding_window(window_size, total_frames):
    sent = 0
    while sent < total_frames:
        # Sending frames
        for i in range(sent, min(sent + window_size, total_frames)):
            print(f"Frame {i + 1} sent")

        # Receiving acknowledgments
        for i in range(sent, min(sent + window_size, total_frames)):
            print(f"ACK received for Frame {i + 1}")

        # Move the window
        sent += window_size

# Example usage
window_size = 4
total_frames = 10
sliding_window(window_size, total_frames)