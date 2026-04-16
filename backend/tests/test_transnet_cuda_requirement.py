from __future__ import annotations

import unittest
from unittest.mock import patch

from services.transnet_refinement import load_transnetv2_model


class TransNetCudaRequirementTests(unittest.TestCase):
    def tearDown(self) -> None:
        load_transnetv2_model.cache_clear()

    def test_load_transnetv2_model_requires_torch_cuda(self) -> None:
        with patch("services.transnet_refinement.is_torch_cuda_available", return_value=False):
            load_transnetv2_model.cache_clear()
            with self.assertRaises(RuntimeError):
                load_transnetv2_model()

    def test_load_transnetv2_model_forces_cuda_device(self) -> None:
        fake_model = object()

        with (
            patch("services.transnet_refinement.is_torch_cuda_available", return_value=True),
            patch("transnetv2_pytorch.TransNetV2", return_value=fake_model) as constructor_mock,
        ):
            load_transnetv2_model.cache_clear()
            result = load_transnetv2_model()

        constructor_mock.assert_called_once_with(device="cuda")
        self.assertIs(result, fake_model)


if __name__ == "__main__":
    unittest.main()
